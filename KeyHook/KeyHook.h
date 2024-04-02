#pragma once
#include "api.h"
#include "KeyHook/IKeyHooker.h"

// KeyListener를 기반으로 KeyHook 시작
extern "C" KEYHOOK_API int runKeyHook(IKeyHooker*);

// KeyHook 종료 신호 전송
// 즉시 종료되는 것이 아닌 다음 키 입력 처리 후 종료된다
extern "C" KEYHOOK_API void stopKeyHook();

// KeyHook 실행 여부 확인
extern "C" KEYHOOK_API int isKeyHookRunning();

extern "C" KEYHOOK_API const char* version();

