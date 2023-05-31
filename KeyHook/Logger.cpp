#include <iostream>
#include <format>
#include "typedef.h"
#include "Logger.h"

using namespace std;

namespace LogUtils {
    Logger::Logger(LogLevel logLevel) {
        setLogLevel(logLevel);
    }
    Logger::Logger(LogDirection logDirection) {
        setLogDirection(logDirection);
    }
    Logger::Logger(LogLevel logLevel, LogDirection logDirection) {
        setLogLevel(logLevel);
        setLogDirection(logDirection);
    }
    Logger::Logger(LogDirection logDirection, LogLevel logLevel) {
        setLogLevel(logLevel);
        setLogDirection(logDirection);
    }

    void Logger::setLogLevel(LogLevel logLevel) {
        m_logLevel = logLevel;
    }
    void Logger::setLogDirection(LogDirection logDirection) {
        m_logDirection = logDirection;
    }

    bool Logger::enabled() {
        return (m_writeLevel >= m_logLevel);
    }

    void Logger::write(const string& message) {
        if (m_logDirection == LogDirection::DEBUGVIEW) {

        }
        else if (m_logDirection == LogDirection::CONSOLE) {
            cout << message;
        }
    };

    void Logger::writeln(const string& message) {
        write(message);
        if (m_logDirection == LogDirection::DEBUGVIEW) {

        }
        else if (m_logDirection == LogDirection::CONSOLE) {
            cout << endl;
        }
    }

    ILogger& Logger::operator<<(const string& message) {
        if (enabled()) {
            write(message);
        }
        return *this;
    }

    ILogger& Logger::operator<<(const char* message) {
        if (enabled()) {
            write(format("{:s}", message));
        }
        return *this;
    }

    ILogger& Logger::operator<<(ILogInfo* info) {
        if (enabled()) {
            write(info->message());
        }
        return *this;
    }

    ILogger& Logger::operator<<(LogLevel logLevel) {
        m_writeLevel = logLevel;
        return *this;
    }


    ILogger& Logger::operator<<(LogDirection logDirection) {
        m_logDirection = logDirection;
        return *this;
    }
}