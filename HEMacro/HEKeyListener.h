#pragma once
#include "pch.h"
#include "KeyHook.h"

namespace KeyHook {
	class HEKeyListener : public KeyListener {
    public:
        LRESULT onPressing(PKBDLLHOOKSTRUCT&) override;
        LRESULT onReleasing(PKBDLLHOOKSTRUCT&) override;
    };
}