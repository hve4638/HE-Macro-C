#pragma once
/* deprecated
#include <windows.h>
#include <functional>

#define MAGICFN_RANGE 256
#define KeyEventLambda(x) [](PKBDLLHOOKSTRUCT &x) -> LRESULT
#define Invoker []()

typedef PKBDLLHOOKSTRUCT KHStruct;
typedef DWORD VKCODE;

typedef LRESULT(*KeyEvent)(PKBDLLHOOKSTRUCT&);
typedef void(*OnInvoke)();

typedef std::function<void()> Action;
typedef std::function<void(bool)> BoolAction;
/**/