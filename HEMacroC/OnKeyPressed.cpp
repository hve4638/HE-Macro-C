#include "KeyHook.h"
extern WORD MagicFnHotkey[256];

using namespace std;

LRESULT OnKeyPressed(PKBDLLHOOKSTRUCT p)
{
#ifdef _DEBUG
    cout << "Pressed: " << p->vkCode << endl;
#endif

    char vkCode = p->vkCode;
    if (vkCode >= 'A' && vkCode <= 'Z') {
        DWORD key = MagicFnHotkey[vkCode];

        if (key != 0) {
            INPUT input[1];
            ZeroMemory(input, sizeof(input));

            input[0].type = INPUT_KEYBOARD;
            input[0].ki.wVk = key;

            SendInput(1, input, sizeof(INPUT));
            return 1;
        }
    }
    return 0;
}
