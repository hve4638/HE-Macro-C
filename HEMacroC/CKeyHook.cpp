#include "KeyHook.h"
#include "vkCodeDBG.h"
#include <iostream>
using namespace std;

namespace KeyHook {
	static KeyHooker* CurrentRunningHooker = NULL;

    LRESULT CALLBACK hookProc(int nCode, WPARAM wParam, LPARAM lParam) {
#ifdef _DEBUG
        if (nCode == HC_ACTION && wParam == WM_KEYDOWN) {
            PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
            cout << "INPUT: " << p->vkCode << " (";
            if (isSpecialVkCode(p->vkCode)) cout << specialVkCodeToChar(p->vkCode);
            else cout << (char)(p->vkCode);
            cout << ")" << endl;
        }
#endif

        return CurrentRunningHooker->onHook(nCode, wParam, lParam);
    }

    void RunKeyHook(KeyHooker* hooker) {
        if (CurrentRunningHooker != NULL) throw std::string("KeyHooks cannot be run in duplicate.");
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