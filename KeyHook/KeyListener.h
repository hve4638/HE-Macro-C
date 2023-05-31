#pragma once
#include "typedef.h"
#include "IKeyListener.h"
#include "MagicFnEvents.h"

namespace KeyHook {
    class KEYHOOK_API KeyListener : public IKeyListener {
        MagicFnEventsClass* m_magicFnEvents = NULL;
    public:
        void setMagicFnEvents(MagicFnEventsClass*);

        void onMagicFnChanged(bool) override;
        LRESULT onPressing(PKBDLLHOOKSTRUCT&) override;
        LRESULT onReleasing(PKBDLLHOOKSTRUCT&) override;
    };
}