#pragma once
#include "typedef.h"
#include "KeyHook.h"

enum RawHookerStatus {
    FREE,
    INUSE,
};

// 실제 Hook를 수행하는 클래스
// 외부에 보여지지 않음
class RawHooker {
    bool m_valid;
    IKeyHooker* m_hooker;
    HHOOK m_hHook = NULL;
public:
    static RawHookerStatus s_status;
    static bool s_stopsignal;
    
    RawHooker(IKeyHooker* hooker);
    ~RawHooker();
    void hook();
};