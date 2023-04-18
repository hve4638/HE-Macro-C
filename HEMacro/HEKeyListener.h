#pragma once
#include "pch.h"
#include "KeyHook.h"

namespace KeyHook {
	class HEKeyListener : public KeyListener {
    public:
        LRESULT pressing(PKBDLLHOOKSTRUCT&) override;
        LRESULT releasing(PKBDLLHOOKSTRUCT&) override;
    };
}