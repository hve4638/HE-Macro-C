#pragma once
#include <string>
#include <windows.h>
#include <functional>

typedef int(*FuncRetInt)();
typedef const char*(*FuncRetChar)();
typedef void(*FuncNoArg)();
typedef int(*FuncArgCharRetInt)(const char*);

class HEMacroLoader {
    HMODULE m_module = NULL;
    BOOL m_loaded = FALSE;

    FuncRetInt m_runMacro = NULL;
    FuncNoArg m_stopMacro = NULL;
    FuncNoArg m_clearInputQueue = NULL;
    FuncArgCharRetInt m_writeQueueLog = NULL;
    FuncRetChar m_version = NULL;

    void error(std::string message = "error occured");
public:
    HEMacroLoader(std::string path);
    ~HEMacroLoader();

    BOOL load();

    int runMacro();
    void stopMacro();
    void clearInputQueue();
    int writeQueueLog(const char*);
    const char* version();
};