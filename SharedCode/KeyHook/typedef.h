#pragma once
#include <windows.h>
#include <functional>
#include <memory>

#define MAGICFN_RANGE 256
#define KeyEventLambda(x) [](PKBDLLHOOKSTRUCT &x) -> LRESULT
#define Invoker []()

typedef PKBDLLHOOKSTRUCT KHStruct;
typedef DWORD VKCODE;

typedef LRESULT(*KeyEvent)(PKBDLLHOOKSTRUCT&);
typedef void(*OnInvoke)();

typedef std::function<void()> Action;
typedef std::function<void(bool)> BoolAction;

enum InputNodeFlags {
    DOWN,
    UP,
};