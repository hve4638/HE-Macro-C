#pragma once

#ifdef HEMACRO_EXPORTS
#define HEMACRO_API __declspec(dllexport)
#else
#define HEMACRO_API
#endif
