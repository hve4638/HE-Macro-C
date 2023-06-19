#pragma once
#include "KeyHook/typedef.h"
#include "IKeyMacro.h"
#define KeyMacroLambda(KH, Macro) [](KHStruct& KH, IKeyMacro& Macro)->MacroKeyResult

typedef std::function<MacroKeyResult(KHStruct&, IKeyMacro&)> KeyEventFunc;
typedef std::function<void(IKeyMacro&)> KeyMacroAction;

/// <summary>
/// KeyListner에 들어가는 메크로 설정 구조체
/// </summary>
struct MagicFnMacro {
    WORD magicKey = 0;
    KeyMacroAction onMagicFnEnabled = NULL;
    KeyMacroAction onMagicFnDisabled = NULL;
    KeyEventFunc onPressing[MAGICFN_RANGE] = { 0, };
    KeyEventFunc onReleasing[MAGICFN_RANGE] = { 0, };
    WORD hotkey[MAGICFN_RANGE] = { 0, };
};