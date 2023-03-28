#include "pch.h"
#include "KeyHook.h"

namespace KeyHook {
	void MagicFnEvents::setPressAndReleaseEvent(WORD vkCode, KeyEvent pressEvent, KeyEvent releaseEvent) {
		pressEvents[vkCode] = pressEvent;
		releaseEvents[vkCode] = releaseEvent;
	}
}