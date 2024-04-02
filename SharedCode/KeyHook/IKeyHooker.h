#pragma once
#include "typedef.h"
#include "KeyHook/KeyHookResult.h"
#include "KeyHook/IKeyListener.h"
#include "KeyHook/IKeyQueue.h"

typedef struct KeyHookInfo {
    int nCode;
    WPARAM wParam;
    LPARAM lParam;
} KeyHookInfo;

interface IKeyHooker {
    // 리턴이 PASS인 경우 입력 그대로 통과
    // 리턴이 BLOCK인 경우 입력 차단
    virtual KeyHookResult onHook(KeyHookInfo&, void*) abstract;
};