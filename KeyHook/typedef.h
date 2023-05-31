#pragma once
#include <windows.h>
#include <functional>
#include <memory>

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#ifdef KEYHOOK_EXPORTS
#define KEYHOOK_API __declspec(dllexport)
#else
#define KEYHOOK_API __declspec(dllimport)
#endif

#define MAGICFN_RANGE 256
#define KeyEventLambda(x) [](PKBDLLHOOKSTRUCT &x) -> LRESULT
#define Invoker []()

struct IKeyController {
	virtual IKeyController* sleep(int) = 0;

	virtual IKeyController* up(WORD) = 0;
	virtual IKeyController* down(WORD) = 0;
	virtual IKeyController* click(WORD) = 0;

	virtual IKeyController* downCtrl() = 0;
	virtual IKeyController* downShift() = 0;
	virtual IKeyController* downWin() = 0;

	virtual IKeyController* upCtrl() = 0;
	virtual IKeyController* upShift() = 0;
	virtual IKeyController* upWin() = 0;
};

typedef DWORD VKCODE;

typedef LRESULT(*KeyEvent)(PKBDLLHOOKSTRUCT&);
typedef void(*OnInvoke)();

typedef std::function<LRESULT(PKBDLLHOOKSTRUCT&, IKeyController*)> KeyEventFunc;
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
