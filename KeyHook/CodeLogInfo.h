#pragma once
#include "typedef.h"
#include "ILogInfo.h"

namespace LogUtils {
    class CodeLogInfo : public ILogInfo {
        std::string m_message = "";
        DWORD m_errorCode;
        const char* m_fname;
        int m_fline;

    public:
        CodeLogInfo(std::string message = "", DWORD errorCode = GetLastError(), const char* __fname = __builtin_FUNCTION(), const int __fline = __builtin_LINE());
        std::string message() override;
    };
}