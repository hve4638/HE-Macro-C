#pragma once
#include "typedef.h"
#include "IKeyQueue.h"
#include "KeyHook/KeyHookResult.h"

interface IKeyListener {
    virtual ~IKeyListener() {}
    
    virtual bool isKeyLocked(DWORD vkCode) const abstract;

    virtual void setKeyQueue(IKeyQueue*) abstract;
    virtual void resetKeyQueue() abstract;

    virtual void onMagicFnChanged(bool) abstract;
    virtual KeyHookResult onPressing(PKBDLLHOOKSTRUCT&, IKeyQueue&) abstract;
    virtual KeyHookResult onReleasing(PKBDLLHOOKSTRUCT&, IKeyQueue&) abstract;
};