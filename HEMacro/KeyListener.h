#pragma once
#include "KeyQueue.h"
#include "KeyHook/IKeyListener.h"
#include "KeyMacro.h"
#include "MagicFnMacro.h"

class KeyListener : public IKeyListener {
    const MagicFnMacroConfiguration& m_configuration;
    IKeyQueue* m_keyQueue = nullptr;
    std::shared_ptr<IKeyMacro> m_keyMacro;
    bool m_keylock[MAGICFN_RANGE] = { 0, };

public:
    KeyListener(MagicFnMacroConfiguration& configuration) : m_configuration(configuration) {
        
    }

    bool isKeyLocked(DWORD key) const;

    void setKeyQueue(IKeyQueue*);
    void resetKeyQueue();
    bool writeQueueLog(const char*);
    void clearQueue();

    void onMagicFnChanged(bool) override;
    KeyHookResult onPressing(PKBDLLHOOKSTRUCT&, IKeyQueue&) override;
    KeyHookResult onReleasing(PKBDLLHOOKSTRUCT&, IKeyQueue&) override;
private:
    bool isInKeyRange(DWORD key);
};
