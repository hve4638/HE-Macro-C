#pragma once
#include <windows.h>
#include <functional>

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.

#ifdef KEYHOOK_EXPORTS
#define KEYHOOK_API __declspec(dllexport)
#else
#define KEYHOOK_API __declspec(dllimport)
#endif

#define MAGICFN_RANGE 256
#define KeyEventLambda(x) [](PKBDLLHOOKSTRUCT &x) -> LRESULT
#define Invoker []()

typedef PKBDLLHOOKSTRUCT KHStruct;
typedef DWORD VKCODE;

typedef LRESULT(*KeyEvent)(PKBDLLHOOKSTRUCT&);
typedef void(*OnInvoke)();

typedef std::function<LRESULT(KHStruct&)> KeyEventFunc;
typedef std::function<void()> Action;
typedef std::function<void(bool)> BoolAction;

enum InputQueueState {
    WAITING,
    READY,
    FINISHED,
};
enum InputNodeFlags {
    DOWN,
    UP,
};
