#include <iostream>
#include "KeyHookLoader.h"
#define DLL_PROC_LOAD(var_name, load_name, load_type) ((var_name = (load_type)GetProcAddress(m_module, load_name)) != NULL)
#define DLL_PROC_CHECK(var_name, load_proc) if (var_name == NULL && !load_proc()) error()

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


void KeyHookLoader::error(string message) {
    cout << message << endl;
    exit(-1);
}

BOOL KeyHookLoader::load() {
    BOOL loaded = TRUE;
    loaded = loaded && DLL_PROC_LOAD(m_runKeyHook, "runKeyHook", RunKeyHookFunc);
    loaded = loaded && DLL_PROC_LOAD(m_stopKeyHook, "stopKeyHook", StopKeyHookFunc);

    m_procLoaded = loaded;
    return loaded;
}

BOOL KeyHookLoader::isLoaded() {
    return m_moduleLoaded;
}

BOOL KeyHookLoader::isProcLoaded() {
    return m_procLoaded;
}

int KeyHookLoader::runKeyHook(IKeyListener* listener) {
    return m_runKeyHook(listener);
}
void KeyHookLoader::stopKeyHook() {
    m_stopKeyHook();
}
int KeyHookLoader::testKeyHook() {
    return -1;
}