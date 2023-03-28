#pragma once
#include <Windows.h>
#include <iostream>
#define MAGICFN_RANGE 256
#define VKCODE DWORD

namespace KeyHook {
	typedef LRESULT(*KeyEvent)(PKBDLLHOOKSTRUCT);
	#define KeyEventLambda(x) [](PKBDLLHOOKSTRUCT x) -> LRESULT
}
