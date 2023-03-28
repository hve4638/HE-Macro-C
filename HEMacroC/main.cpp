#include "KeyHook.h"
#include "keyEvents.h"
#include "VKExtend.h"

using namespace std;
using namespace KeyHook;

int main() {
    KeyHooker hooker;
    KeyListener listener;
    MagicFnEvents magicFnEvents;
    
    magicFnEvents.setPressAndReleaseEvent('Z', &EventDownWithCtrl, &EventUpWithCtrl);
    magicFnEvents.setPressAndReleaseEvent('X', &EventDownWithCtrl, &EventUpWithCtrl);
    magicFnEvents.setPressAndReleaseEvent('C', &EventDownWithCtrl, &EventUpWithCtrl);
    magicFnEvents.setPressAndReleaseEvent('V', &EventDownWithCtrl, &EventUpWithCtrl);
    magicFnEvents.setPressAndReleaseEvent('B', &EventDownWithCtrl, &EventUpWithCtrl);

    magicFnEvents.pressEvents['Q'] = KeyEventLambda(p) {
        InputQueue::Instance.push(VK_CONTROL, DOWN);
        return 1;
    };
    magicFnEvents.releaseEvents['Q'] = KeyEventLambda(p) {
        InputQueue::Instance.push(VK_CONTROL, UP);
        return 1;
    };
    magicFnEvents.pressEvents['W'] = KeyEventLambda(p) {
        InputQueue::Instance.push(VK_SHIFT, DOWN);
        return 1;
    };
    magicFnEvents.releaseEvents['W'] = KeyEventLambda(p) {
        InputQueue::Instance.push(VK_SHIFT, UP);
        return 1;
    };


    magicFnEvents.hotkey['E'] = VK_CAPITAL;
    magicFnEvents.hotkey['A'] = VK_LEFT;
    magicFnEvents.hotkey['D'] = VK_RIGHT;

    magicFnEvents.hotkey['I'] = VK_UP;
    magicFnEvents.hotkey['J'] = VK_LEFT;
    magicFnEvents.hotkey['K'] = VK_DOWN;
    magicFnEvents.hotkey['L'] = VK_RIGHT;

    //magicFnEvents.hotkey['Q'] = VK_CONTROL;
    //magicFnEvents.hotkey['W'] = VK_LSHIFT;
    //magicFnEvents.hotkey['E'] = VK_CAPITAL;xx

    magicFnEvents.hotkey['1'] = VK_F1;
    magicFnEvents.hotkey['2'] = VK_F2;
    magicFnEvents.hotkey['3'] = VK_F3;
    magicFnEvents.hotkey['4'] = VK_F4;
    magicFnEvents.hotkey['5'] = VK_F5;
    magicFnEvents.hotkey['6'] = VK_F6;
    magicFnEvents.hotkey['7'] = VK_F7;
    magicFnEvents.hotkey['8'] = VK_F8;
    magicFnEvents.hotkey['9'] = VK_F9;
    magicFnEvents.hotkey['0'] = VK_F10;
    magicFnEvents.hotkey[189] = VK_F11; // '-'
    magicFnEvents.hotkey[187] = VK_F12; // '='

    magicFnEvents.hotkey[219] = VK_PGUP; // '['
    magicFnEvents.hotkey[221] = VK_PGDOWN; // ']'
    
    magicFnEvents.hotkey['R'] = VK_INSERT;

    magicFnEvents.hotkey['U'] = VK_HOME;
    magicFnEvents.hotkey['O'] = VK_END;
    magicFnEvents.hotkey['N'] = VK_BACK;
    magicFnEvents.hotkey['M'] = VK_DELETE;
    magicFnEvents.hotkey[VK_OEM_1] = VK_RETURN; // ';' -> ENTER

    magicFnEvents.hotkey['H'] = 21; // 'ÇÑ/¿µ'

    listener.setMagicFnEvents(&magicFnEvents);
    hooker.setKeyListener(&listener);
    hooker.run();
    return 0;
}
