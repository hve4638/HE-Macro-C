#pragma once
#include "api.h"

extern "C" HEMACRO_API int runMacro();

extern "C" HEMACRO_API void stopMacro();

extern "C" HEMACRO_API void clearInputQueue();

extern "C" HEMACRO_API int writeQueueLog(const char*);

extern "C" HEMACRO_API const char* version();