#pragma once
#include "KeyHook/typedef.h"
#include "KeyHook/IKeyHooker.h"
#include "KeyHook/IKeyListener.h"
#include "KeyHook/IKeyQueue.h"
#include <string>
#include <windows.h>
#include <functional>

typedef int(*TestKeyHookFunc)();
typedef int(*RunKeyHookFunc)(IKeyListener*);
typedef void(*StopKeyHookFunc)();

class KeyHookLoader {
    HMODULE m_module = NULL;
    BOOL m_moduleLoaded = FALSE;
    BOOL m_procLoaded = FALSE;

    RunKeyHookFunc m_runKeyHook = NULL;
    StopKeyHookFunc m_stopKeyHook = NULL;
    TestKeyHookFunc m_testKeyHook = NULL;

    void error(std::string message = "KeyHookLoader : error occured");
public:
    KeyHookLoader(std::string path);
    ~KeyHookLoader();

    BOOL isLoaded();
    BOOL isProcLoaded();
    BOOL load();

    int runKeyHook(IKeyListener*);
    void stopKeyHook();
    int testKeyHook();
};