#pragma once
#include "typedef.h"

namespace KeyHook {
    class KEYHOOK_API MagicFnEvents {
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