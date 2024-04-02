#pragma once
#include "KeyHook/typedef.h"
#include "KeyHook/IKeyHooker.h"
#include "KeyHook/IKeyListener.h"
#include "KeyListener.h"
#include "KeyQueue.h"

// MagicFn�� ������ �⺻ KeyHooker Ŭ���� ����
// RawHooker���� ����
class KeyHooker : public IKeyHooker {
    bool m_magicFnEnabled = false;
    IKeyListener* m_keyListener = nullptr;
    VKCODE m_magicFn = VK_CAPITAL;
    KeyQueue m_queue;

    bool isMagicFn(VKCODE) const;
    bool isLocked(VKCODE) const;
public:
    KeyHooker() {}
    KeyHooker(IKeyListener*);
    void setKeyListener(IKeyListener*);

    KeyHookResult onHook(KeyHookInfo&, void*) override;
};
