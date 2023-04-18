#include "pch.h"
#include "KeyHook.h"

namespace KeyHook {
    void KeyListener::setMagicFnEvents(MagicFnEvents* magicFnEvents) {
        m_magicFnEvents = magicFnEvents;
    }

    void KeyListener::onMagicFnChanged(bool enabled) {
        if (enabled) {
            auto invoker = m_magicFnEvents->onMagicFnEnabled;
            if (invoker != NULL) invoker();
        }
        else {
            auto invoker = m_magicFnEvents->onMagicFnDisabled;
            if (invoker != NULL) invoker();
        }
    }

	LRESULT KeyListener::pressing(PKBDLLHOOKSTRUCT &p) {
        DWORD vkCode = p->vkCode;
        if (vkCode >= 0 && vkCode < MAGICFN_RANGE) {
            DWORD hotkey = m_magicFnEvents->hotkey[vkCode];

            if (hotkey != 0) {
                InputQueue::Instance.push(hotkey, DOWN);
                return 1;
            }

            KeyEvent onEvent = m_magicFnEvents->pressEvents[vkCode];
            if (onEvent != NULL) {
                if (onEvent(p)) return 1;
            }
        }
        return 0;
	}
	LRESULT KeyListener::releasing(PKBDLLHOOKSTRUCT &p) {
        DWORD vkCode = p->vkCode;

        if (vkCode >= 0 && vkCode < MAGICFN_RANGE) {
            DWORD hotkey = m_magicFnEvents->hotkey[vkCode];

            if (hotkey != 0) {
                InputQueue::Instance.push(hotkey, UP);
                return 1;
            }

            KeyEvent onEvent = m_magicFnEvents->releaseEvents[vkCode];
            if (onEvent != NULL) {
                if (onEvent(p)) return 1;
            }
        }
        return 0;
	}
}