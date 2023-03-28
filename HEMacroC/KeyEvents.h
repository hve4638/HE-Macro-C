#pragma once
#include "precompiled.h"

namespace KeyHook {
	LRESULT NoEvent(PKBDLLHOOKSTRUCT);
	LRESULT EventPressWithCtrl(PKBDLLHOOKSTRUCT);
	LRESULT EventReleaseWithCtrl(PKBDLLHOOKSTRUCT);
	LRESULT EventDownWithCtrl(PKBDLLHOOKSTRUCT);
	LRESULT EventUpWithCtrl(PKBDLLHOOKSTRUCT);
}