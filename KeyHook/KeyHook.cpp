#include "typedef.h"
#include "KeyHook.h"
#include "KeyHooker.h"
#include "KeyQueue.h"
#include "ReserveCall.h"
#include <iostream>
#include <stdlib.h>
#include <mutex>

using namespace std;

static IKeyQueue* CurrentInputQueue;
static IKeyHooker* CurrentRunningHooker = NULL;
static bool Running = false;

LRESULT CALLBACK hookProc(int nCode, WPARAM wParam, LPARAM lParam) {
    KeyHookInfo info = { 0, };
    info.nCode = nCode;
    info.wParam = wParam;
    info.lParam = lParam;

    return CurrentRunningHooker->onHook(info, *CurrentInputQueue);
}

class Hooker {
    KeyHooker m_hooker;
    KeyQueue m_queue;
    HHOOK m_hHook = NULL;
    IKeyListener* m_keyListener;
public:
    Hooker(IKeyListener* keyListener) {
        m_keyListener = keyListener;

        Running = true;
        CurrentRunningHooker = &m_hooker;
        CurrentInputQueue = &m_queue;
    }

    ~Hooker() {
        if (m_hHook != NULL) UnhookWindowsHookEx(m_hHook);

        Running = false;
        CurrentRunningHooker = NULL;
        CurrentInputQueue = NULL;
        m_keyListener->resetKeyQueue();
    }

    void hook() {
        m_hHook = SetWindowsHookEx(WH_KEYBOARD_LL, hookProc, NULL, 0);
        m_keyListener->setKeyQueue(m_queue);
        m_hooker.setKeyListener(m_keyListener);

        MSG msg;
        while (Running && GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
};

int runKeyHook(IKeyListener* keyListener) {
    if (!Running) {
        Hooker hooker = { keyListener };
        hooker.hook();
    }
    return 0;
}

void stopKeyHook() {
    Running = false;
}

int testKeyHook() {
    return 1990;
}
