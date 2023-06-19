#include "KeyHooker.h"
#define KEYHOOKINFO_VKCODE(keyHookInfo) (((PKBDLLHOOKSTRUCT)(info.lParam))->vkCode)
#define KEYHOOKRESULT_CHECK(X)                                \
if ((X) == RESULT_EXIT_BLOCK) { goto EXIT_BLOCKED; }          \
else if ((X) == RESULT_EXIT_NORMAL) { goto EXIT_NORMAL; }     \

void KeyHooker::setKeyListener(IKeyListener* listener) {
    m_keyListener = listener;
}

KeyHookerProcessResult KeyHooker::processMatchQueue(VKCODE vkCode, KeyState nFlag, IKeyQueue& queue) {
    if (queue.isEmpty()) {
        return RESULT_PASS;
    }
    else if (queue.match(vkCode, nFlag)) {
        queue.pop();
        return RESULT_EXIT_NORMAL;
    }
    else {
        return RESULT_PASS;
    }
}

KeyHookerProcessResult KeyHooker::processMagicFn(VKCODE vkCode, KeyState nFlag) {
    if (vkCode == VK_CAPITAL) {
        if (nFlag == KeyState::DOWN) {
            if (!m_magicFnEnabled) {
                m_magicFnEnabled = true;
                m_keyListener->onMagicFnChanged(m_magicFnEnabled);
            }
        }
        else if (nFlag == KeyState::UP) {
            if (m_magicFnEnabled) {
                m_magicFnEnabled = false;
                m_keyListener->onMagicFnChanged(m_magicFnEnabled);
            }
        }

        return RESULT_EXIT_BLOCK;
    }
    else {
        return RESULT_PASS;
    }
}

KeyHookerProcessResult KeyHooker::processKeyEvent(KeyHookInfo& info, IKeyQueue& queue) {
    PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)info.lParam;
    auto vkCode = p->vkCode;
    KeyState nFlag = (info.wParam == WM_KEYDOWN) ? KeyState::DOWN : KeyState::UP;

    if (!m_magicFnEnabled) {
        return RESULT_EXIT_NORMAL;
    }
    else if (nFlag == KeyState::DOWN) {
        MacroKeyResult result = m_keyListener->onPressing(p, queue);
        if (result == MacroKeyResult::BLOCK) {
            return RESULT_EXIT_BLOCK;
        }
    }
    else if (nFlag == KeyState::UP) {
        MacroKeyResult result = m_keyListener->onReleasing(p, queue);
        if (result == MacroKeyResult::BLOCK) {
            return RESULT_EXIT_BLOCK; 
        }
    }

    return RESULT_EXIT_NORMAL;
}

LRESULT KeyHooker::onHook(KeyHookInfo &info, IKeyQueue &queue) {
    int nCode = info.nCode;
    WPARAM wParam = info.wParam;
    LPARAM lParam = info.lParam;

    if (nCode == HC_ACTION) {
        PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
        auto vkCode = p->vkCode;
        auto nFlag = (info.wParam == WM_KEYDOWN) ? KeyState::DOWN : KeyState::UP;

        KeyHookerProcessResult result;
        result = processMatchQueue(vkCode, nFlag, queue);
        KEYHOOKRESULT_CHECK(result);
        result = processMagicFn(vkCode, nFlag);
        KEYHOOKRESULT_CHECK(result);
        result = processKeyEvent(info, queue);
        KEYHOOKRESULT_CHECK(result);
    }

EXIT_NORMAL:
    return CallNextHookEx(NULL, nCode, wParam, lParam);
EXIT_BLOCKED:
    return 1;
}