#include "KeyHook.h"

using namespace std;

WORD MagicFnHotkey[256] = { 0, 0, };

int main() {
    MagicFnHotkey['A'] = VK_LEFT;
    MagicFnHotkey['S'] = VK_DOWN;
    MagicFnHotkey['D'] = VK_RIGHT;

    MagicFnHotkey['I'] = VK_UP;
    MagicFnHotkey['J'] = VK_LEFT;
    MagicFnHotkey['K'] = VK_DOWN;
    MagicFnHotkey['L'] = VK_RIGHT;

    MagicFnHotkey['Q'] = VK_CONTROL;
    MagicFnHotkey['W'] = VK_LSHIFT;

    MagicFnHotkey['1'] = VK_F1;
    MagicFnHotkey['2'] = VK_F2;
    MagicFnHotkey['3'] = VK_F3;
    MagicFnHotkey['4'] = VK_F4;
    MagicFnHotkey['5'] = VK_F5;
    MagicFnHotkey['6'] = VK_F6;
    MagicFnHotkey['7'] = VK_F7;
    MagicFnHotkey['8'] = VK_F8;
    MagicFnHotkey['9'] = VK_F9;
    MagicFnHotkey['0'] = VK_F10;
    MagicFnHotkey[189] = VK_F11; // '-'
    MagicFnHotkey[187] = VK_F12; // '='
    MagicFnHotkey[186] = 13; // ';' - ENTER
    
    MagicFnHotkey['U'] = VK_HOME;
    MagicFnHotkey['O'] = VK_END;
    MagicFnHotkey['N'] = VK_BACK;
    MagicFnHotkey['M'] = VK_DELETE;
    
    MagicFnHotkey['H'] = 21; // 'ÇÑ/¿µ'

    RunKeyHook();
    return 0;
}
