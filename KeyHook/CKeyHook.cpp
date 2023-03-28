#include "pch.h"
#include "KeyHook.h"
#include <stdlib.h>

namespace KeyHook {
	static KeyHooker* CurrentRunningHooker = NULL;

    LRESULT CALLBACK hookProc(int nCode, WPARAM wParam, LPARAM lParam) {
        return CurrentRunningHooker->onHook(nCode, wParam, lParam);
    }

    void RunKeyHook(KeyHooker* hooker) {
        if (CurrentRunningHooker != NULL) abort();
        CurrentRunningHooker = hooker;
        HHOOK hHook = SetWindowsHookEx(WH_KEYBOARD_LL, hookProc, NULL, 0);

        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        UnhookWindowsHookEx(hHook);
        CurrentRunningHooker = NULL;
    }
}