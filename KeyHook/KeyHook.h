#pragma once
#include "typedef.h"
#include "KeyHooker.h"
#include "KeyListener.h"
#include "MagicFnEvents.h"
#include "InputQueue.h"

namespace KeyHook {
    extern "C" KEYHOOK_API void runKeyHook(KeyHooker*);
    extern "C" KEYHOOK_API void stopKeyHook();
}