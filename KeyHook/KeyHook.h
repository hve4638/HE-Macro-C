#pragma once
#include "api.h"
#include "KeyHook/IKeyHooker.h"

extern "C" KEYHOOK_API int testKeyHook();
extern "C" KEYHOOK_API int runKeyHook(IKeyListener*);
extern "C" KEYHOOK_API void stopKeyHook();