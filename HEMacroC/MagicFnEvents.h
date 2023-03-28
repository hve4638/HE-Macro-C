#pragma once
#include "precompiled.h"

namespace KeyHook {
    class MagicFnEvents {
    private:
    public:
        KeyEvent pressEvents[MAGICFN_RANGE] = { 0, };
        KeyEvent releaseEvents[MAGICFN_RANGE] = { 0, };
        WORD hotkey[MAGICFN_RANGE] = { 0, };

        void setPressAndReleaseEvent(WORD, KeyEvent, KeyEvent);
    };
}