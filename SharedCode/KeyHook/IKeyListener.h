#pragma once
#include "typedef.h"
#include "IKeyQueue.h"

enum class MacroKeyResult {
    PASS,
    BLOCK
};

interface IKeyListener {
    virtual ~IKeyListener() {}
    virtual void resetKeyQueue() abstract;
    virtual void setKeyQueue(IKeyQueue&) abstract;
    virtual void onMagicFnChanged(bool) abstract;
    virtual MacroKeyResult onPressing(PKBDLLHOOKSTRUCT&, IKeyQueue&) abstract;
    virtual MacroKeyResult onReleasing(PKBDLLHOOKSTRUCT&, IKeyQueue&) abstract;
};