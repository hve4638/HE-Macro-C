#pragma once
#include "pch.h"

#ifdef HEMACRO_EXPORTS
#define HEMACRO_API __declspec(dllexport)
#else
#define HEMACRO_API __declspec(dllimport)
#endif

extern "C" HEMACRO_API void runMacro();
extern "C" HEMACRO_API void stopMacro();