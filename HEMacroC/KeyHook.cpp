#include <iostream>
#include "KeyHook.h"

using namespace std;

static int EnableMagicFn = 0;

void RunKeyHook();
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
#ifdef _DEBUG
    if (nCode == HC_ACTION && wParam == WM_KEYDOWN) {
        PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
        cout << "INPUT: " << p->vkCode << endl;
    }
#endif

    if (nCode == HC_ACTION) {
        PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;

        if (p->vkCode == 20) {
            if (wParam == WM_KEYDOWN) EnableMagicFn = 1;
            else if (wParam == WM_KEYUP) EnableMagicFn = 0;

            return 1;
        }

        if (!EnableMagicFn) return CallNextHookEx(NULL, nCode, wParam, lParam);

        if (wParam == WM_KEYDOWN) {
            LRESULT result = OnKeyPressed(p);
            if (result == 1) return 1;
        }
        else if (wParam == WM_KEYUP) {
            LRESULT result = OnKeyReleased(p);
            if (result == 1) return 1;
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void RunKeyHook() {
    HHOOK hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hHook);
}