#include "KeyHook.h"

KeyEvent MagicFnPressEvent[MAGICFN_RANGE] = { 0, };
KeyEvent MagicFnReleaseEvent[MAGICFN_RANGE] = { 0, };
WORD MagicFnHotkey[MAGICFN_RANGE] = { 0, };

int KeyInMagicFnRange(DWORD vk) {
    return (vk >= 0 && vk < MAGICFN_RANGE);
}

void MaginFnSetKey(WORD vk, KeyEvent onPressed, KeyEvent onReleased) {
    MagicFnPressEvent[vk] = onPressed;
    MagicFnReleaseEvent[vk] = onReleased;
}