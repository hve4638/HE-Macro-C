#pragma once
#include "KeyHook/typedef.h"
#include "KeyHook/IKeyHooker.h"
#include "KeyHook/IKeyListener.h"
#include "KeyHook/IKeyQueue.h"
#include <string>
#include <windows.h>
#include <functional>

typedef int(*FuncRunKeyHook)(IKeyHooker*);
typedef void(*FuncStopKeyHook)();

typedef int (*FuncIsRunningKeyHook)();
typedef int (*FuncIsStopKeyHook)();
typedef const char* (*FuncVersion)();

// 동적 dll 로드 클래스
class KeyHookLoader {
    HMODULE m_module = NULL;
    BOOL m_moduleLoaded = FALSE;
    BOOL m_procLoaded = FALSE;

    FuncRunKeyHook m_runKeyHook = NULL;
    FuncStopKeyHook m_stopKeyHook = NULL;
    FuncIsRunningKeyHook m_isKeyHookRunning = NULL;
    FuncVersion m_version = NULL;
public:
    KeyHookLoader(std::string path);
    ~KeyHookLoader();

    BOOL isLoaded();
    BOOL isProcLoaded();
    BOOL load();

    int runKeyHook(IKeyHooker*);
    void stopKeyHook();
    int isKeyHookRunning();
    int testKeyHook();
};