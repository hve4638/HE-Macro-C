#pragma once
#include "typedef.h"

namespace KeyHook {
    namespace InputEditer {
        extern "C" KEYHOOK_API void Down(INPUT & input, WORD vk);
        extern "C" KEYHOOK_API void Up(INPUT & input, WORD vk);
    }
}