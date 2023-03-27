#include "KeyHook.h"

LRESULT OnKeyReleased(PKBDLLHOOKSTRUCT p)
{
    DWORD vkCode = p->vkCode;
    if (KeyInMagicFnRange(vkCode)) {
        DWORD hotkey = MagicFnHotkey[vkCode];

        if (hotkey != 0) {
            INPUT input[1];
            ZeroMemory(input, sizeof(input));

            SetInputKeyUp(input[0], (WORD)hotkey);
            SendInput(1, input, sizeof(INPUT));

            return 1;
        }

        KeyEvent onEvent = MagicFnReleaseEvent[vkCode];
        if (onEvent != NULL) {
            if (onEvent(p)) return 1;
        }
    }

    return 0;
}
