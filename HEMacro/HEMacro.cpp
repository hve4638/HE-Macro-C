#include "KeyHook/KeyHookLoader.h"
#include "HEMacro.h"
#include "KeyListener.h"
#include <iostream>

#define VK_PGUP 33
#define VK_PGDOWN 34
using namespace std;

static KeyHookLoader loader = { "./KeyHook.dll" };
static MagicFnMacro macro;

void setMacro(MagicFnMacro& magicFnMacro);
int runMacro() {
	if (!loader.isProcLoaded()) {
		loader.load();
	}

    setMacro(macro);

	KeyListener keyListener;
	keyListener.setMagicFnEvents(&macro);
	macro.onMagicFnEnabled = [](IKeyMacro& macro) {
		cout << "enabled?" << endl;
	};
	macro.onMagicFnDisabled = [](IKeyMacro& macro) {
		cout << "disabled??" << endl;
	};
	macro.onPressing['A'] = [](KHStruct kh, IKeyMacro& macro)->MacroKeyResult {
		macro.click(VK_LEFT);
		return MacroKeyResult::BLOCK;
	};

	loader.runKeyHook(&keyListener);

	return loader.testKeyHook();
}

void stopMacro() {
	return;
}

static void setMacro(MagicFnMacro& magicFnMacro) {
    magicFnMacro.onPressing['Z'] = KeyMacroLambda(kh, macro) { 
        macro.downCtrl().click('Z').upCtrl();
        return MacroKeyResult::BLOCK;
    };
    magicFnMacro.onPressing['X'] = KeyMacroLambda(kh, macro) {
        macro.downCtrl().click('X').upCtrl();
        return MacroKeyResult::BLOCK;
    };
    magicFnMacro.onPressing['C'] = KeyMacroLambda(kh, macro) {
        macro.downCtrl().click('C').upCtrl();
        return MacroKeyResult::BLOCK;
    };
    magicFnMacro.onPressing['V'] = KeyMacroLambda(kh, macro) {
        macro.downCtrl().click('V').upCtrl();
        return MacroKeyResult::BLOCK;
    };
    magicFnMacro.onPressing['B'] = KeyMacroLambda(kh, macro) {
        macro.downCtrl().click('B').upCtrl();
        return MacroKeyResult::BLOCK;
    };

    magicFnMacro.onMagicFnEnabled = [](IKeyMacro& macro) { };
    magicFnMacro.onMagicFnDisabled = [](IKeyMacro& macro) { macro.upCtrl().upShift(); };

    magicFnMacro.onPressing[VK_OEM_COMMA] = KeyMacroLambda(kh, macro) { //'<'
        macro.downCtrl().downWin();
        macro.click(VK_LEFT);
        macro.upCtrl().upWin();

        return MacroKeyResult::BLOCK;
    };
    magicFnMacro.onPressing[VK_OEM_PERIOD] = KeyMacroLambda(kh, macro) { //'>'
        macro.downCtrl().downWin();
        macro.click(VK_RIGHT);
        macro.upCtrl().upWin();

        return MacroKeyResult::BLOCK;
    };

    magicFnMacro.onPressing['Q'] = KeyMacroLambda(kh, macro) { 
        macro.downCtrl();
        return MacroKeyResult::BLOCK;
    };
    magicFnMacro.onReleasing['Q'] = KeyMacroLambda(kh, macro) {
        macro.upCtrl();
        return MacroKeyResult::BLOCK;
    };
    magicFnMacro.onPressing['W'] = KeyMacroLambda(kh, macro) {
        cout << "DOWN W" << endl;
        macro.downShift();
        return MacroKeyResult::BLOCK;
    };
    magicFnMacro.onReleasing['W'] = KeyMacroLambda(kh, macro) {
        cout << "UP W" << endl;
        macro.upShift();
        return MacroKeyResult::BLOCK;
    };


    magicFnMacro.hotkey['E'] = VK_CAPITAL;
    magicFnMacro.hotkey['A'] = VK_LEFT;
    magicFnMacro.hotkey['D'] = VK_RIGHT;
    magicFnMacro.hotkey['S'] = VK_DOWN;
    magicFnMacro.hotkey['F'] = VK_UP;

    magicFnMacro.hotkey['I'] = VK_UP;
    magicFnMacro.hotkey['J'] = VK_LEFT;
    magicFnMacro.hotkey['K'] = VK_DOWN;
    magicFnMacro.hotkey['L'] = VK_RIGHT;

    magicFnMacro.hotkey['1'] = VK_F1;
    magicFnMacro.hotkey['2'] = VK_F2;
    magicFnMacro.hotkey['3'] = VK_F3;
    magicFnMacro.hotkey['4'] = VK_F4;
    magicFnMacro.hotkey['5'] = VK_F5;
    magicFnMacro.hotkey['6'] = VK_F6;
    magicFnMacro.hotkey['7'] = VK_F7;
    magicFnMacro.hotkey['8'] = VK_F8;
    magicFnMacro.hotkey['9'] = VK_F9;
    magicFnMacro.hotkey['0'] = VK_F10;
    magicFnMacro.hotkey[189] = VK_F11; // '-'
    magicFnMacro.hotkey[187] = VK_F12; // '='

    magicFnMacro.hotkey[0xDB] = VK_PGUP; // '['
    magicFnMacro.hotkey[0xDD] = VK_PGDOWN; // ']'

    magicFnMacro.hotkey['R'] = VK_INSERT;

    magicFnMacro.hotkey['U'] = VK_HOME;
    magicFnMacro.hotkey['O'] = VK_END;
    magicFnMacro.hotkey['N'] = VK_BACK;
    magicFnMacro.hotkey['M'] = VK_DELETE;
    magicFnMacro.hotkey[0xBA] = VK_RETURN; // ';' -> ENTER

    magicFnMacro.hotkey['H'] = 21; // 'ÇÑ/¿µ'
}