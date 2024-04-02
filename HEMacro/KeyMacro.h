#pragma once
#include "IKeyMacro.h"
#include "KeyHook/IKeyQueue.h"

class KeyMacro : public IKeyMacro {
	IKeyQueue* m_queue;
	bool* m_keylock;

public:
	KeyMacro(IKeyQueue* queue, bool keylock[]) {
		m_queue = queue;
		m_keylock = keylock;
	}
	IKeyMacro& lock(WORD);
	IKeyMacro& unlock(WORD);
	
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