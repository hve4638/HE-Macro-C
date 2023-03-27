#include "KeyHook.h"

LRESULT OnKeyPressed(PKBDLLHOOKSTRUCT p)
{
    DWORD vkCode = p->vkCode;
    if (vkCode >= 'A' && vkCode <= 'Z') {
        DWORD hotkey = MagicFnHotkey[vkCode];

        if (hotkey != 0) {
            INPUT input[1];
            ZeroMemory(input, sizeof(input));

            SetInputKeyDown(input[0], (WORD)hotkey);
            SendInput(1, input, sizeof(INPUT));
            return 1;
        }

        KeyEvent onEvent = MagicFnPressEvent[vkCode];
        if (onEvent != NULL) {
            if (onEvent(p)) return 1;
        }
    }
    return 0;
}
