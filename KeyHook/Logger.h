#pragma once
#pragma once
#include "typedef.h"
#include "ILogger.h"

using namespace std;

namespace LogUtils {
    class Logger : public ILogger {
        LogLevel m_logLevel = LogLevel::ALL;
        LogDirection m_logDirection = LogDirection::CONSOLE;
        LogLevel m_currentLogLevel = LogLevel::ALL;

        bool enabled();
        void write(const string&);
        void writeln(const string&);
    public:
        Logger() {}
        Logger(LogLevel);
        Logger(LogDirection);
        Logger(LogLevel, LogDirection);
        Logger(LogDirection, LogLevel);
        void setLogLevel(LogLevel) override;
        void setLogDirection(LogDirection) override;
        ILogger& operator<<(const string&) override;
        ILogger& operator<<(const char*) override;
        ILogger& operator<<(LogLevel) override;
        ILogger& operator<<(LogDirection) override;
        //ILogger& operator<<(const L&) override;
    };
}


