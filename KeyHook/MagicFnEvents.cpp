#include "KeyHook.h"

namespace KeyHook {
	void MagicFnEventsClass::setPressAndReleaseEvent(WORD vkCode, KeyEvent pressEvent, KeyEvent releaseEvent) {
		pressEvents[vkCode] = pressEvent;
		releaseEvents[vkCode] = releaseEvent;
	}
}