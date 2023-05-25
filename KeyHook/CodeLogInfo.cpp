#include "typedef.h"
#include "ILogInfo.h"

namespace LogUtils {
    class CodeLogInfo : ILogInfo {
        std::string message = "";
        DWORD errorCode = GetLastError();
        const char* funcName;
        const int funcLine;

    public:
        CodeLogInfo(std::string message, DWORD errorCode, const char* __fname, const int __fline);
        std::string message() = 0;
    };
}