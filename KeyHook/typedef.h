#pragma once
#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
#include <windows.h>
#define MAGICFN_RANGE 256
#define KeyEventLambda(x) [](PKBDLLHOOKSTRUCT &x) -> LRESULT
#define Invoker []()
typedef DWORD VKCODE;

#ifdef KEYHOOK_EXPORTS
#define KEYHOOK_API __declspec(dllexport)
#else
#define KEYHOOK_API __declspec(dllimport)
#endif

typedef LRESULT(*KeyEvent)(PKBDLLHOOKSTRUCT&);
typedef void(*OnInvoke)();

enum InputQueueState {
    WAITING,
    READY,
    FINISHED,
};
enum InputNodeFlags {
    DOWN,
    UP,
};
