#pragma once
#include "typedef.h"
#include "KeyHook.h"

enum RawHookerStatus {
    FREE,
    INUSE,
};

// ���� Hook�� �����ϴ� Ŭ����
// �ܺο� �������� ����
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