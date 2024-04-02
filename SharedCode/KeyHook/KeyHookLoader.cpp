#include <iostream>
#include "KeyHookLoader.h"
#define DLL_PROC_SETUP(M) BOOL dllprocloaded = TRUE; HMODULE dllmodule = M;
#define DLL_PROC_LOAD(var_name, load_name, load_type) (dllprocloaded = ((var_name = (load_type)GetProcAddress(dllmodule, load_name)) != NULL))
#define DLL_PROC_RESULT(LOADED) (LOADED = dllprocloaded)

using namespace std;

KeyHookLoader::KeyHookLoader(string path) {
    m_module = LoadLibraryA(path.c_str());
    m_moduleLoaded = (m_module != NULL);
}
KeyHookLoader::~KeyHookLoader() {
    if (m_module != NULL) {
        FreeLibrary(m_module);
        m_module = NULL;
    }
}

BOOL KeyHookLoader::load() {
    if (!m_moduleLoaded) {
        return FALSE;
    }

    DLL_PROC_SETUP(m_module);
    DLL_PROC_LOAD(m_runKeyHook, "runKeyHook", FuncRunKeyHook);
    DLL_PROC_LOAD(m_stopKeyHook, "stopKeyHook", FuncStopKeyHook);
    DLL_PROC_LOAD(m_isKeyHookRunning, "isKeyHookRunning", FuncIsRunningKeyHook);
    DLL_PROC_LOAD(m_version, "version", FuncVersion);
    DLL_PROC_RESULT(m_procLoaded);

    return m_procLoaded;
}

BOOL KeyHookLoader::isLoaded() {
    return m_moduleLoaded;
}

BOOL KeyHookLoader::isProcLoaded() {
    return m_procLoaded;
}

int KeyHookLoader::runKeyHook(IKeyHooker* hooker) {
    return m_runKeyHook(hooker);
}
void KeyHookLoader::stopKeyHook() {
    m_stopKeyHook();
}
int KeyHookLoader::isKeyHookRunning() {
    return m_isKeyHookRunning();
}
int KeyHookLoader::testKeyHook() {
    return -1;
}