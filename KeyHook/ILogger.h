#include <string>
#include "ILogInfo.h"

namespace LogUtils {
    enum ErrorLogExtraInfo {
        ERRLOG_EXTRA_NONE = 0x0,
        ERRLOG_EXTRA_FUNCTION = 0x1,
        ERRLOG_EXTRA_FULL = 0xFFFFFF
    };

    enum class LogLevel {
        DISABLE = 0x0,
        ALL = 0x1,
        DEBUG = 0x2,
        INFO = 0x3,
        WARN = 0x4,
        ERR = 0x5,
        FATAL = 0x6
    };

    enum class LogDirection {
        DEBUGVIEW,
        CONSOLE
    };

    struct ILogger {
        virtual void setLogLevel(LogLevel) abstract;
        virtual void setLogDirection(LogDirection) abstract;
        virtual ILogger& operator<<(const std::string&) abstract;
        virtual ILogger& operator<<(const char*) abstract;
        virtual ILogger& operator<<(LogLevel) abstract;
        virtual ILogger& operator<<(LogDirection) abstract;
        virtual ILogger& operator<<(CodeLogInfo*) abstract;
    };
}