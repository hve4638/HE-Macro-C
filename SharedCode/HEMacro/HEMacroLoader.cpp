#pragma once
#include <iostream>
#include "HEMacroLoader.h"
#define DLL_PROC_SETUP(M) BOOL dllprocloaded = TRUE; HMODULE dllmodule = M;
#define DLL_PROC_LOAD(var_name, load_name, load_type) \
    (dllprocloaded = dllprocloaded && ((var_name = (load_type)GetProcAddress(dllmodule, load_name)) != NULL))
#define DLL_PROC_RESULT(LOADED) (LOADED = dllprocloaded)

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
    if (m_module == NULL) {
        return FALSE;
    }

    DLL_PROC_SETUP(m_module);
    DLL_PROC_LOAD(m_runMacro, "runMacro", FuncRetInt);
    DLL_PROC_LOAD(m_stopMacro, "stopMacro", FuncNoArg);
    DLL_PROC_LOAD(m_writeQueueLog, "clearInputQueue", FuncArgCharRetInt);
    DLL_PROC_LOAD(m_clearInputQueue, "writeQueueLog", FuncNoArg);
    DLL_PROC_LOAD(m_version, "version", FuncRetChar);
    DLL_PROC_RESULT(m_loaded);

    return m_loaded;
}

void HEMacroLoader::error(string message) {
    cerr << "KeyHookLoader: " << message << endl;
    exit(-1);
}

int HEMacroLoader::runMacro() {
    if (m_runMacro == NULL) error(__FUNCTION__);

    return m_runMacro();
}

void HEMacroLoader::stopMacro() {
    if (m_stopMacro == NULL) error(__FUNCTION__);

    m_stopMacro();
}

int HEMacroLoader::writeQueueLog(const char* filename) {
    if (m_writeQueueLog == NULL) error(__FUNCTION__);

    return m_writeQueueLog(filename);
}

void HEMacroLoader::clearInputQueue() {
    if (m_clearInputQueue == NULL) error(__FUNCTION__);

    m_clearInputQueue();
}

const char* HEMacroLoader::version() {
    if (m_version == NULL) error(__FUNCTION__);

    return m_version();
}

