#pragma once

#ifdef _DEBUG
static bool isSpecialVkCode(unsigned long vkCode) {
    if (vkCode >= '0' && vkCode <= '9') return false;
    if (vkCode >= 'A' && vkCode <= 'Z') return false;
    return true;
}

static const char* specialVkCodeToChar(unsigned long vkCode) {
    switch (vkCode) {
    case 27:
        return "~";
    case 9:
        return "Tab";
    case 37:
        return "LEFT";
    case 38:
        return "UP";
    case 39:
        return "RIGHT";
    case 40:
        return "DOWN";
    case 20:
        return "CAPSLOCK";
    case 162:
        return "CTRL";
    case 160:
        return "LSHIFT";
    case 161:
        return "RSHIFT";
    case 13:
        return "ENTER";
    case 220:
        return "|";
    case 32:
        return "SPACE";
    case 91:
        return "WIN";
    case 188:
        return ",";
    case 190:
        return ".";
    case 186:
        return ";";
    case 222:
        return "'";
    case 191:
        return "/";
    }

    return "unknown";
}
#endif
