#pragma once
#include <string>

namespace LogUtils {
    struct ILogInfo {
        virtual std::string message() = 0;
    };
}