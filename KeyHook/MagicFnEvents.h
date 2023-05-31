#pragma once
#include "typedef.h"

namespace KeyHook {

    struct MagicFnMacroStruct {
        WORD magicKey = 0;
        Action onMagicFnEnabled = NULL;
        Action onMagicFnDisabled = NULL;
        KeyEventFunc onPressing[MAGICFN_RANGE] = { 0, };
        KeyEventFunc onReleasing[MAGICFN_RANGE] = { 0, };
        WORD hotkey[MAGICFN_RANGE] = { 0, };
    } MagicFnMacroInfo;

    //void setMagicFnPressingAndReleasingEvents(MagicFnEvents&, WORD, KeyEventFunc, KeyEventFunc);

    class KEYHOOK_API MagicFnEventsClass {
    private:
    public:
        OnInvoke onMagicFnEnabled = NULL;
        OnInvoke onMagicFnDisabled = NULL;
        KeyEvent pressEvents[MAGICFN_RANGE] = { 0, };
        KeyEvent releaseEvents[MAGICFN_RANGE] = { 0, };
        WORD hotkey[MAGICFN_RANGE] = { 0, };

        void setPressAndReleaseEvent(WORD, KeyEvent, KeyEvent);
    };
}