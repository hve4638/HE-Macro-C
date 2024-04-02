#include <cassert>
#include "KeyHooker.h"
#include "KeyHook/KeyHookResult.h"
#include "Debug/Debug.h"

#ifdef _DEBUG
#define LOG(X, Y) std::err << ""
#else
#define LOG(X, Y);
#endif

KeyHookResult KeyHooker::onHook(KeyHookInfo& info, void* reserved) {
    assert(m_keyListener != nullptr);

    int nCode = info.nCode;
    WPARAM wParam = info.wParam;
    LPARAM lParam = info.lParam;

    if (nCode != HC_ACTION) return PASS;

    PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
    auto vkCode = p->vkCode;
    KeyState nFlag = (info.wParam == WM_KEYDOWN) ? KeyState::DOWN : KeyState::UP;
    //DebugOut("Input " << vkCode);

    // 메크로를 통해 입력된 키 또한 onHook로 들어오므로, 검사 후 메크로로 입력된 키라면 바로 PASS
    if (!m_queue.isEmpty() && m_queue.match(vkCode, nFlag)) {
        DebugOut("QUEUE PASS " << vkCode << (nFlag == KeyState::DOWN ? "*" : ""));
        m_queue.pop();
        return PASS;
    }
    else if (isMagicFn(vkCode)) {
        if (nFlag == KeyState::DOWN && !m_magicFnEnabled) {
            m_magicFnEnabled = true;
            m_keyListener->onMagicFnChanged(m_magicFnEnabled);
        }
        else if (nFlag == KeyState::UP && m_magicFnEnabled) {
            m_magicFnEnabled = false;
            m_keyListener->onMagicFnChanged(m_magicFnEnabled);
        }
        return BLOCK;
    }
    else if (isLocked(vkCode)) {
        DebugOut("LOCKED " << vkCode << (nFlag == KeyState::DOWN ? "*" : ""));
        return BLOCK;
    }
    else if (m_magicFnEnabled) {
        DebugOut("MAGICFN " << vkCode << (nFlag == KeyState::DOWN ? "*" : ""));
        if (nFlag == KeyState::DOWN) {
            return m_keyListener->onPressing(p, m_queue);
        }
        else if (nFlag == KeyState::UP) {
            return m_keyListener->onReleasing(p, m_queue);
        }
        return PASS;
    }
    else {
        DebugOut("OTHER " << vkCode << (nFlag == KeyState::DOWN ? "*" : ""));
        return PASS;
    }

    DebugInfo("never be reached");
    return PASS;
}

inline bool KeyHooker::isMagicFn(VKCODE vkCode) const {
    return (vkCode == m_magicFn);
}
inline bool KeyHooker::isLocked(VKCODE vkCode) const {
    assert(m_keyListener != nullptr);

    return m_keyListener->isKeyLocked(vkCode);
}

KeyHooker::KeyHooker(IKeyListener* listener) {
    setKeyListener(listener);
}

void KeyHooker::setKeyListener(IKeyListener* listener) {
    m_keyListener = listener;
    listener->setKeyQueue(&m_queue);
}