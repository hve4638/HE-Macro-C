#pragma once
#include "typedef.h"

namespace KeyHook {
    class KEYHOOK_API IKeyListener {
    public:
        virtual void onMagicFnChanged(bool)=0;
        virtual LRESULT onPressing(PKBDLLHOOKSTRUCT&)=0;
        virtual LRESULT onReleasing(PKBDLLHOOKSTRUCT&)=0;
    };
}