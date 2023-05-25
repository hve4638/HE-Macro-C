#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "HEMacro.h"
#include "KeyHook.h"
#include "KeyEvents.h"
#include "HEKeyListener.h"
#define VK_PGUP 33
#define VK_PGDOWN 34

using namespace std;
using namespace KeyHook;

MagicFnEvents* makeKeyEvents();

bool writeInputQueue(const char* filename) {
    auto node = InputQueue::Instance.rawNodeBegin();

    ofstream file(filename);
    if (file.is_open()) {
        while (node != NULL) {
            file << (node->vkCode) << endl;
            if (node->vkCode == UP) file << "*";

            node = node->next;
        }

        file.close();
        return true;
    }
    else {
        return false;
    }
}

void stopMacro() {
    stopKeyHook();
}

void runMacroDebug() {
    KeyHooker hooker;
    KeyListener* listener = new HEKeyListener();
    MagicFnEvents* magicFnEvents = makeKeyEvents();

    listener->setMagicFnEvents(magicFnEvents);
    hooker.setKeyListener(listener);
    hooker.run();

    delete listener;
    delete magicFnEvents;
}
void runMacro() {
    KeyHooker hooker;
    KeyListener* listener = new KeyListener();
    MagicFnEvents* magicFnEvents = makeKeyEvents();

    listener->setMagicFnEvents(magicFnEvents);
    hooker.setKeyListener(listener);
    hooker.run();

    delete listener;
    delete magicFnEvents;
}

void clearInputQueue() {
    while (!InputQueue::Instance.isEmpty()) {
        InputQueue::Instance.pop();
    }   
}

MagicFnEvents* makeKeyEvents() {
    MagicFnEvents *magicFnEvents = new MagicFnEvents();

    magicFnEvents->setPressAndReleaseEvent('Z', &EventDownWithCtrl, &EventUpWithCtrl);
    magicFnEvents->setPressAndReleaseEvent('X', &EventDownWithCtrl, &EventUpWithCtrl);
    magicFnEvents->setPressAndReleaseEvent('C', &EventDownWithCtrl, &EventUpWithCtrl);
    magicFnEvents->setPressAndReleaseEvent('V', &EventDownWithCtrl, &EventUpWithCtrl);
    magicFnEvents->setPressAndReleaseEvent('B', &EventDownWithCtrl, &EventUpWithCtrl);

    magicFnEvents->onMagicFnEnabled = Invoker{
    };
    magicFnEvents->onMagicFnDisabled = Invoker{
        InputQueue::Instance.push(VK_LSHIFT, UP);
        InputQueue::Instance.push(VK_LCONTROL, UP);
    };
    //magicFnEvents->setPressAndReleaseEvent('A', &EventDownWithCtrl, &EventUpWithCtrl);
    //magicFnEvents->setPressAndReleaseEvent('D', &EventDownWithCtrl, &EventUpWithCtrl);

    magicFnEvents->pressEvents[VK_OEM_COMMA] = KeyEventLambda(p) {
        InputQueue::Instance.push(VK_LCONTROL, DOWN);
        InputQueue::Instance.push(VK_LWIN, DOWN);
        InputQueue::Instance.push(VK_LEFT, DOWN);
        InputQueue::Instance.push(VK_LEFT, UP);
        InputQueue::Instance.push(VK_LWIN, UP);
        InputQueue::Instance.push(VK_LCONTROL, UP);
        return 1;
    };
    magicFnEvents->pressEvents[VK_OEM_PERIOD] = KeyEventLambda(p) {
        InputQueue::Instance.push(VK_LCONTROL, DOWN);
        InputQueue::Instance.push(VK_LWIN, DOWN);
        InputQueue::Instance.push(VK_RIGHT, DOWN);
        InputQueue::Instance.push(VK_RIGHT, UP);
        InputQueue::Instance.push(VK_LWIN, UP);
        InputQueue::Instance.push(VK_LCONTROL, UP);
        return 1;
    };
    magicFnEvents->pressEvents['Q'] = KeyEventLambda(p) {
        //p->vkCode = VK_LCONTROL;
        InputQueue::Instance.push(VK_LCONTROL, DOWN);
        return 1;
    };
    magicFnEvents->releaseEvents['Q'] = KeyEventLambda(p) {
        //p->vkCode = VK_LCONTROL;
        InputQueue::Instance.push(VK_LCONTROL, UP);
        return 1;
    };
    magicFnEvents->pressEvents['W'] = KeyEventLambda(p) {
        InputQueue::Instance.push(VK_LSHIFT, DOWN);

        return 1;
    };
    magicFnEvents->releaseEvents['W'] = KeyEventLambda(p) {
        InputQueue::Instance.push(VK_LSHIFT, UP);
        return 1;
    };

    magicFnEvents->hotkey['E'] = VK_CAPITAL;

    magicFnEvents->hotkey['A'] = VK_LEFT;
    magicFnEvents->hotkey['D'] = VK_RIGHT;
    magicFnEvents->hotkey['S'] = VK_DOWN;
    magicFnEvents->hotkey['F'] = VK_UP;

    magicFnEvents->hotkey['I'] = VK_UP;
    magicFnEvents->hotkey['J'] = VK_LEFT;
    magicFnEvents->hotkey['K'] = VK_DOWN;
    magicFnEvents->hotkey['L'] = VK_RIGHT;

    magicFnEvents->hotkey['1'] = VK_F1;
    magicFnEvents->hotkey['2'] = VK_F2;
    magicFnEvents->hotkey['3'] = VK_F3;
    magicFnEvents->hotkey['4'] = VK_F4;
    magicFnEvents->hotkey['5'] = VK_F5;
    magicFnEvents->hotkey['6'] = VK_F6;
    magicFnEvents->hotkey['7'] = VK_F7;
    magicFnEvents->hotkey['8'] = VK_F8;
    magicFnEvents->hotkey['9'] = VK_F9;
    magicFnEvents->hotkey['0'] = VK_F10;
    magicFnEvents->hotkey[189] = VK_F11; // '-'
    magicFnEvents->hotkey[187] = VK_F12; // '='

    magicFnEvents->hotkey[0xDB] = VK_PGUP; // '['
    magicFnEvents->hotkey[0xDD] = VK_PGDOWN; // ']'

    magicFnEvents->hotkey['R'] = VK_INSERT;

    magicFnEvents->hotkey['U'] = VK_HOME;
    magicFnEvents->hotkey['O'] = VK_END;
    magicFnEvents->hotkey['N'] = VK_BACK;
    magicFnEvents->hotkey['M'] = VK_DELETE;
    magicFnEvents->hotkey[0xBA] = VK_RETURN; // ';' -> ENTER

    magicFnEvents->hotkey['H'] = 21; // 'ÇÑ/¿µ'

    return magicFnEvents;
}