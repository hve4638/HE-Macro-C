#include <iostream>
#include <fstream>
#include <cassert>
#include "KeyListener.h"
#include "KeyMacro.h"
#include "Debug/Debug.h"

using namespace std;

bool KeyListener::isKeyLocked(DWORD key) const {
    return m_keylock[key];
}

void KeyListener::setKeyQueue(IKeyQueue* queue) {
    m_keyQueue = queue;
    m_keyMacro = make_shared<KeyMacro>(queue, m_keylock);
}

void KeyListener::resetKeyQueue() {
    m_keyQueue = nullptr;
    m_keyMacro.reset();
}

bool KeyListener::writeQueueLog(const char* filename) {
    ofstream file(filename);
    if (!file.is_open()) return true;

    auto node = m_keyQueue->rawNodeBegin();
    while (node != NULL) {
        file << (node->vkCode) << endl;
        if (node->vkCode == UP) file << "*";

        node = node->next;
    }
    file.close();
    return false;
}

void KeyListener::clearQueue() {
    while (!m_keyQueue->isEmpty()) {
        m_keyQueue->pop();
    }
}

void KeyListener::onMagicFnChanged(bool enabled) {
    if (enabled) {
        auto onEnabled = m_configuration.onMagicFnEnabled;
        if (onEnabled != NULL) onEnabled(*m_keyMacro);
    }
    else {
        auto onDisabled = m_configuration.onMagicFnDisabled;
        if (onDisabled != NULL) onDisabled(*m_keyMacro);
    }
}

KeyHookResult KeyListener::onPressing(PKBDLLHOOKSTRUCT& p, IKeyQueue& queue) {

    DWORD vkCode = p->vkCode;
    if (isInKeyRange(vkCode)) {
        DWORD hotkey = m_configuration.hotkey[vkCode];
        if (hotkey != 0) {
            m_keyQueue->push(hotkey, KeyState::DOWN);
            return BLOCK;
        }

        KeyEventFunc onEvent = m_configuration.onPressing[vkCode];
        if (onEvent != NULL) {
            if (onEvent(p, *m_keyMacro) == BLOCK) {
                return BLOCK;
            }
        }
    }
    return PASS;
}

KeyHookResult KeyListener::onReleasing(PKBDLLHOOKSTRUCT& p, IKeyQueue& queue) {
    DWORD vkCode = p->vkCode;

    if (isInKeyRange(vkCode)) {
        DWORD hotkey = m_configuration.hotkey[vkCode];
        if (hotkey != 0) {
            m_keyQueue->push(hotkey, KeyState::UP);
            return BLOCK;
        }

        KeyEventFunc onEvent = m_configuration.onReleasing[vkCode];
        if (onEvent != NULL) {
            if (onEvent(p, *m_keyMacro) == BLOCK) {
                return BLOCK;
            }
        }
    }
    return PASS;
}

bool KeyListener::isInKeyRange(DWORD vkCode) {
    return (vkCode >= 0 && vkCode < MAGICFN_RANGE);
}