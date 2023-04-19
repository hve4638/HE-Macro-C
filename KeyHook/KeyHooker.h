#pragma once
#include "typedef.h"
#include "IKeyListener.h"

namespace KeyHook {
    class KEYHOOK_API KeyHooker {
    private:
        bool m_magicFnEnabled = false;
        IKeyListener* m_keyListener = NULL;

    public:
        void setKeyListener(IKeyListener*);
        LRESULT onHook(int, WPARAM, LPARAM);
        void run();
    };
}