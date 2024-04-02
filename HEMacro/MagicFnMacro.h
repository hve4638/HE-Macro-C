#pragma once
#include "KeyHook/typedef.h"
#include "KeyHook/IKeyListener.h"
#include "IKeyMacro.h"
#define KeyMacroLambda(KH, Macro) [](KHStruct& KH, IKeyMacro& Macro)->KeyHookResult

typedef std::function<void(IKeyMacro&)> KeyMacroAction;
typedef std::function<KeyHookResult(KHStruct&, IKeyMacro&)> KeyEventFunc;

/// <summary>
/// KeyListner에 들어가는 메크로 설정 구조체
/// </summary>
struct MagicFnMacroConfiguration {
    WORD magicKey = 0;
    KeyMacroAction onMagicFnEnabled = NULL;
    KeyMacroAction onMagicFnDisabled = NULL;
    KeyEventFunc onPressing[MAGICFN_RANGE] = { 0, };
    KeyEventFunc onReleasing[MAGICFN_RANGE] = { 0, };
    WORD hotkey[MAGICFN_RANGE] = { 0, };
};