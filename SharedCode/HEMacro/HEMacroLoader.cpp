#pragma once
#include "HEMacroLoader.h"
#define DLL_PROC_LOAD(var_name, load_name, load_type) ((var_name = (load_type)GetProcAddress(m_module, load_name)) != NULL)
#define DLL_PROC_CHECK(var_name, load_proc) if (var_name == NULL && !load_proc()) error()

using namespace std;

HEMacroLoader::HEMacroLoader(string path) {
    m_module = LoadLibraryA(path.c_str());
    m_loaded = (m_module != NULL);
}

HEMacroLoader::~HEMacroLoader() {
    if (m_module != NULL) {
        FreeLibrary(m_module);
        m_module = NULL;
    }
}

BOOL HEMacroLoader::load() {
    BOOL loaded = TRUE;
    loaded = loaded && DLL_PROC_LOAD(m_runMacro, "runMacro", RunMacroFunc);
    loaded = loaded && DLL_PROC_LOAD(m_stopMacro, "stopMacro", StopMacroFunc);

    return loaded;
}

int HEMacroLoader::runMacro() {
    return m_runMacro();
}

void HEMacroLoader::stopMacro() {
    m_stopMacro();
}