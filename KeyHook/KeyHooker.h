#pragma once
#include "typedef.h"
#include "KeyHook/IKeyHooker.h"
#include "KeyHook/IKeyListener.h"

enum KeyHookerProcessResult {
    RESULT_PASS,
    RESULT_EXIT_NORMAL,
    RESULT_EXIT_BLOCK,
};

class KeyHooker : public IKeyHooker {
    bool m_magicFnEnabled = false;
    IKeyListener* m_keyListener = NULL;

    KeyHookerProcessResult processMatchQueue(VKCODE, KeyState, IKeyQueue&);
    KeyHookerProcessResult processMagicFn(VKCODE, KeyState);
    KeyHookerProcessResult processKeyEvent(KeyHookInfo&, IKeyQueue&);
public:
    void setKeyListener(IKeyListener*);

    LRESULT onHook(KeyHookInfo&, IKeyQueue&) override;
};
