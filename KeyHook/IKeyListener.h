#pragma once
#include "typedef.h"

namespace KeyHook {
    class KEYHOOK_API IKeyListener {
    public:
        virtual void onMagicFnChanged(bool) = 0;
        virtual LRESULT pressing(PKBDLLHOOKSTRUCT&) = 0;
        virtual LRESULT releasing(PKBDLLHOOKSTRUCT&) = 0;
    };
}