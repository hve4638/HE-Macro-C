#pragma once
#include "IKeyMacro.h"
#include "KeyHook/IKeyQueue.h"

class KeyMacro : public IKeyMacro {
	IKeyQueue* m_queue;

public:
	KeyMacro(IKeyQueue& queue) {
		m_queue = &queue;
	}
	
	IKeyMacro& sleep(int) override;

	IKeyMacro& up(WORD) override;
	IKeyMacro& down(WORD) override;
	IKeyMacro& click(WORD) override;

	IKeyMacro& downCtrl() override;
	IKeyMacro& downShift() override;
	IKeyMacro& downWin() override;

	IKeyMacro& upCtrl() override;
	IKeyMacro& upShift() override;
	IKeyMacro& upWin() override;
};