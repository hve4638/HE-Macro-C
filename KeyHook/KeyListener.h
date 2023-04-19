#pragma once
#include "typedef.h"
#include "IKeyListener.h"
#include "MagicFnEvents.h"

namespace KeyHook {
    class KEYHOOK_API KeyListener : public IKeyListener {
        MagicFnEvents* m_magicFnEvents = NULL;
    public:
        void setMagicFnEvents(MagicFnEvents*);

        void onMagicFnChanged(bool) override;
        LRESULT pressing(PKBDLLHOOKSTRUCT&) override;
        LRESULT releasing(PKBDLLHOOKSTRUCT&) override;
    };
}