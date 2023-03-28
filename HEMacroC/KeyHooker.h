#pragma once
#include "precompiled.h"
#include "IKeyListener.h"

namespace KeyHook {
    class KeyHooker {
    private:
        bool m_magicFnEnabled = false;
        IKeyListener* m_keyListener = NULL;

    public:
        void setKeyListener(IKeyListener*);
        LRESULT onHook(int, WPARAM, LPARAM);
        void run();
    };
}