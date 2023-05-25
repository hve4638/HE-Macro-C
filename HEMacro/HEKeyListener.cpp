#pragma once
#include "pch.h"
#include "HEKeyListener.h"
#include <iostream>
using namespace std;

namespace KeyHook {
    LRESULT HEKeyListener::onPressing(PKBDLLHOOKSTRUCT &p) {
        cout << "pressing " << p->vkCode << endl;

        auto node = InputQueue::Instance.rawNodeBegin();
        while (node != NULL) {
            cout << node->vkCode << "_";
            node = node->next;
        }
        cout << endl;

        return KeyListener::onPressing(p);
    }
    LRESULT HEKeyListener::onReleasing(PKBDLLHOOKSTRUCT &p) {
        return KeyListener::onReleasing(p);
    }
}