#include <iostream>
#include <windows.h>
#include "KeyHook/KeyHookLoader.h"
#include "KeyHooker.h"
#include "HEMacro.h"
#include "MacroInitializer.h"
#include "KeyListener.h"

//#define VK_PGUP 33
//#define VK_PGDOWN 34
using namespace std;

static KeyHookLoader loader = { "./KeyHook.dll" };

// MagicFnMacro의 크기는 3만 바이트를 넘어감
// 스택영역에 넣는것은 부적절하므로 전역 선언
static MagicFnMacroConfiguration macro;
static KeyListener* currentKeyListener = NULL;

static void loadcheck();

void clearInputQueue() {
	if (currentKeyListener == NULL) return;

	currentKeyListener->clearQueue();
}

int writeQueueLog(const char* filename) {
	return 15;
	if (currentKeyListener == NULL) return -2;
	
	if (currentKeyListener->writeQueueLog(filename)) {
		return 0;
	}
	else {
		return -1;
	}
}

int runMacro() {                                                                                                                                                                                                                                                                                                                                                                                                                                                           
	if (!loader.isProcLoaded()) loader.load();
    if (loader.isKeyHookRunning()) return -1;

    initializeMacroToDefaults(macro);

	KeyListener keyListener = { macro };

	// TODO : 생명주기 처리에 대한 더 나은 방법 필요
	KeyHooker keyHooker = { &keyListener };
	loader.runKeyHook(&keyHooker);

	return 0;
}

void stopMacro() {
	if (!loader.isProcLoaded()) loader.load();

	cerr << "StopMacro()" << endl;
	loader.stopKeyHook();
	while (loader.isKeyHookRunning()) {
		Sleep(1);
	}
	return;
}

void loadcheck() {
	if (loader.isProcLoaded()) {
		return;
	}
	else if (!loader.load()) {
		cerr << "load fail: KeyHook.dll" << endl;
		exit(-2);
	}
}

const char* version() {
	return "v1.1.0 (HEMacro)";
}