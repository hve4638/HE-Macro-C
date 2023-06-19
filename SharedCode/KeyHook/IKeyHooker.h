#pragma once
#include "typedef.h"
#include "KeyHook/IKeyListener.h"
#include "KeyHook/IKeyQueue.h"

typedef struct KeyHookInfo {
    int nCode;
    WPARAM wParam;
    LPARAM lParam;
} KeyHookInfo;

interface IKeyHooker {
    virtual LRESULT onHook(KeyHookInfo&, IKeyQueue&) abstract;
};