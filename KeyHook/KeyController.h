#pragma once
#include "typedef.h"
#include "InputQueue.h"

namespace KeyHook {
	class KeyController : public IKeyController {
		std::shared_ptr<InputQueue> m_inputQueue;

	public:
		IKeyController* sleep(int) override;
		
		IKeyController* down(WORD) override;
		IKeyController* up(WORD) override;
		IKeyController* click(WORD) override;

		IKeyController* downCtrl() override;
		IKeyController* downShift() override;
		IKeyController* downWin() override;
		IKeyController* upCtrl() override;
		IKeyController* upShift() override;
		IKeyController* upWin() override;

		
	};
}