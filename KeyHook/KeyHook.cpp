#include "typedef.h"
#include "RawHooker.h"
#include <iostream>
#include <stdlib.h>
#include <mutex>

using namespace std;

int runKeyHook(IKeyHooker* keyHooker) {
    RawHooker hooker = { keyHooker };
    hooker.hook();

    return 0;
}

void stopKeyHook() {
    RawHooker::s_stopsignal = true;
}

int isKeyHookRunning() {
    return (RawHooker::s_status == INUSE);
}

const char* version() {
    return "v1.1.0 (KeyHook)";
}
