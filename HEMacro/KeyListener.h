#pragma once
#include "KeyHook/IKeyListener.h"
#include "KeyMacro.h"
#include "MagicFnMacro.h"

class KeyListener : public IKeyListener {
    MagicFnMacro* m_magicFnEvents = NULL;
    IKeyQueue* m_keyQueue = NULL;
    std::shared_ptr<IKeyMacro> m_keyMacro;

public:
    void resetKeyQueue();
    void setKeyQueue(IKeyQueue&);
    void setMagicFnEvents(MagicFnMacro*);

    void onMagicFnChanged(bool) override;
    MacroKeyResult onPressing(PKBDLLHOOKSTRUCT&, IKeyQueue&) override;
    MacroKeyResult onReleasing(PKBDLLHOOKSTRUCT&, IKeyQueue&) override;
};
