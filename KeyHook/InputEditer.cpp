#include "KeyHook.h"
#include "pch.h"

namespace KeyHook {
    namespace InputEditer {
        void Down(INPUT& input, WORD vk) {
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = vk;
        }

        void Up(INPUT& input, WORD vk) {
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = vk;
            input.ki.dwFlags = KEYEVENTF_KEYUP;
        }
    }
}