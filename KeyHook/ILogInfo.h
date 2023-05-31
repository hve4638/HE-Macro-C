#pragma once
#include <string>

namespace LogUtils {
    struct ILogInfo {
        ~ILogInfo() {}
        virtual std::string message() = 0;
    };
}