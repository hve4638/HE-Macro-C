#include "KeyHook.h"
#include <stdlib.h>

namespace KeyHook {
	static KeyHooker* CurrentRunningHooker = NULL;
    static bool Running = false;

    LRESULT CALLBACK hookProc(int nCode, WPARAM wParam, LPARAM lParam) {
        return CurrentRunningHooker->onHook(nCode, wParam, lParam);
    }

    void stopKeyHook() {
        Running = false;
    }

    void runKeyHook(KeyHooker* hooker) {
        if (CurrentRunningHooker != NULL) abort();
        Running = true;
        CurrentRunningHooker = hooker;
        HHOOK hHook = SetWindowsHookEx(WH_KEYBOARD_LL, hookProc, NULL, 0);

        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0) && Running) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        UnhookWindowsHookEx(hHook);
        CurrentRunningHooker = NULL;
        Running = false;
    }
}