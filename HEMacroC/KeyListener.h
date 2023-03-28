#pragma once
#include "precompiled.h"
#include "IKeyListener.h"
#include "MagicFnEvents.h"

namespace KeyHook {
	class KeyListener : public IKeyListener {
		MagicFnEvents* m_magicFnEvents;
	public:
		void setMagicFnEvents(MagicFnEvents*);

		LRESULT pressing(PKBDLLHOOKSTRUCT) override;
		LRESULT releasing(PKBDLLHOOKSTRUCT) override;
	};
}
