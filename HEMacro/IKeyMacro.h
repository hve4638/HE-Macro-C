#pragma once
#include "KeyHook/typedef.h"

interface IKeyMacro {
	virtual ~IKeyMacro() {}
	virtual IKeyMacro& lock(WORD) abstract;
	virtual IKeyMacro& unlock(WORD) abstract;

	virtual IKeyMacro& sleep(int) abstract;

	virtual IKeyMacro& up(WORD) abstract;
	virtual IKeyMacro& down(WORD) abstract;
	virtual IKeyMacro& click(WORD) abstract;

	virtual IKeyMacro& downCtrl() abstract;
	virtual IKeyMacro& downShift() abstract;
	virtual IKeyMacro& downWin() abstract;

	virtual IKeyMacro& upCtrl() abstract;
	virtual IKeyMacro& upShift() abstract;
	virtual IKeyMacro& upWin() abstract;
};