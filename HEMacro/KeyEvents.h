#pragma once
#include "pch.h"
#include "KeyHook.h"

LRESULT NoEvent(PKBDLLHOOKSTRUCT);
LRESULT EventDownWithCtrl(PKBDLLHOOKSTRUCT);
LRESULT EventUpWithCtrl(PKBDLLHOOKSTRUCT);