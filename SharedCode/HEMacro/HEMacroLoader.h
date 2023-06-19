#pragma once
#include <string>
#include <windows.h>
#include <functional>

typedef int(*RunMacroFunc)();
typedef void(*StopMacroFunc)();

class HEMacroLoader {
    HMODULE m_module = NULL;
    BOOL m_loaded = FALSE;

    RunMacroFunc m_runMacro = NULL;
    StopMacroFunc m_stopMacro = NULL;

    void error(std::string message = "HEMacroLoader : error occured");
public:
    HEMacroLoader(std::string path);
    ~HEMacroLoader();

    BOOL load();

    int runMacro();
    void stopMacro();
};