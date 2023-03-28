#include "KeyHook.h"

void SetInputKeyDown(INPUT& input, WORD vk) {
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = vk;
}
void SetInputKeyUp(INPUT& input, WORD vk) {
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = vk;
    input.ki.dwFlags = KEYEVENTF_KEYUP;
}
