#pragma once
#include "typedef.h"
#include "KeyHook/KeyHookResult.h"
#include "KeyHook/IKeyListener.h"
#include "KeyHook/IKeyQueue.h"

typedef struct KeyHookInfo {
    int nCode;
    WPARAM wParam;
    LPARAM lParam;
} KeyHookInfo;

interface IKeyHooker {
    // ������ PASS�� ��� �Է� �״�� ���
    // ������ BLOCK�� ��� �Է� ����
    virtual KeyHookResult onHook(KeyHookInfo&, void*) abstract;
};