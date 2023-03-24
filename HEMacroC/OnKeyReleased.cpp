#include "KeyHook.h"
extern WORD MagicFnHotkey[256];

LRESULT OnKeyReleased(PKBDLLHOOKSTRUCT p)
{
    char vkCode = p->vkCode;
    if (vkCode >= 'A' && vkCode <= 'Z') {
        DWORD key = MagicFnHotkey[vkCode];

        if (key != 0) {
            INPUT input[1];
            ZeroMemory(input, sizeof(input));

            input[0].type = INPUT_KEYBOARD;
            input[0].ki.wVk = key;
            input[0].ki.dwFlags = KEYEVENTF_KEYUP;

            SendInput(1, input, sizeof(INPUT));
            return 1;
        }
    }

    return 0;
}
