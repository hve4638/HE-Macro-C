#include "KeyHook.h"

namespace KeyHook {
    void KeyHooker::setKeyListener(IKeyListener* listener) {
        m_keyListener = listener;
    }

    void KeyHooker::run() {
        runKeyHook(this);
    }

    LRESULT KeyHooker::onHook(int nCode, WPARAM wParam, LPARAM lParam) {
        if (nCode == HC_ACTION) {
            PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;

            if (!InputQueue::Instance.isEmpty()) {
                InputNodeFlags nFlag = (wParam == WM_KEYDOWN) ? DOWN : UP;
                if (InputQueue::Instance.match(p->vkCode, nFlag)) {
                    InputQueue::Instance.pop();

                    goto normalExit;
                }
            }
            if (p->vkCode == VK_CAPITAL) {
                if (wParam == WM_KEYDOWN) {
                    m_magicFnEnabled = true;
                    m_keyListener->onMagicFnChanged(true);
                }
                else if (wParam == WM_KEYUP) {
                    m_magicFnEnabled = false;
                    m_keyListener->onMagicFnChanged(false);
                }

                return 1;
            }

            if (!m_magicFnEnabled) goto normalExit;

            if (wParam == WM_KEYDOWN) {
                LRESULT result = m_keyListener->onPressing(p);
                if (result == 1) goto keyBlocked;
            }
            else if (wParam == WM_KEYUP) {
                LRESULT result = m_keyListener->onReleasing(p);
                if (result == 1) goto keyBlocked;
            }
        }

    normalExit:
        return CallNextHookEx(NULL, nCode, wParam, lParam);
    keyBlocked:
        return 1;
    }
}
