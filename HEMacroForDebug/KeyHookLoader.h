#pragma once
#include <string>
#include <windows.h>
#include <functional>
//#include "KeyHook/typedef.h"

typedef int(*RunKeyHookFunc)();
typedef void(*StopKeyHookFunc)();

class KeyHookLoader {
    HMODULE m_module = NULL;
    BOOL m_loaded = FALSE;

    //m_runKeyHook = 
    RunKeyHookFunc m_startKeyHook;
    StopKeyHookFunc m_stopKeyHook;

    void error(std::string message = "KeyHook : error occured");
public:
    KeyHookLoader(std::string path);
    ~KeyHookLoader();

    BOOL load();

    int runKeyHook();
    void stopKeyHook();
};