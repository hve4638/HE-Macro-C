#include <iostream>
#include "KeyListener.h"
#include "KeyMacro.h"

using namespace std;

void KeyListener::resetKeyQueue() {
    m_keyQueue = NULL;
    m_keyMacro.reset();
}
void KeyListener::setKeyQueue(IKeyQueue& keyQueue) {
    m_keyQueue = &keyQueue;
    m_keyMacro.reset(new KeyMacro(keyQueue));
}
void KeyListener::setMagicFnEvents(MagicFnMacro* keyFnMacro) {
    m_magicFnEvents = keyFnMacro;
}

void KeyListener::onMagicFnChanged(bool enabled) {
    if (enabled) {
        auto onEnabled = m_magicFnEvents->onMagicFnEnabled;
        if (onEnabled != NULL) onEnabled(*m_keyMacro);
    }
    else {
        auto onDisabled = m_magicFnEvents->onMagicFnDisabled;
        if (onDisabled != NULL) onDisabled(*m_keyMacro);
    }
}

MacroKeyResult KeyListener::onPressing(PKBDLLHOOKSTRUCT& p, IKeyQueue& queue) {    
    DWORD vkCode = p->vkCode;
    if (vkCode >= 0 && vkCode < MAGICFN_RANGE) {
        DWORD hotkey = m_magicFnEvents->hotkey[vkCode];

        if (hotkey != 0) {
            m_keyQueue->push(hotkey, KeyState::DOWN);
            return MacroKeyResult::BLOCK;
        }

        KeyEventFunc onEvent = m_magicFnEvents->onPressing[vkCode];
        if (onEvent != NULL) {
            if (onEvent(p, *m_keyMacro) == MacroKeyResult::BLOCK) {
                return MacroKeyResult::BLOCK;
            }
        }
    }
    return MacroKeyResult::PASS;
}

MacroKeyResult KeyListener::onReleasing(PKBDLLHOOKSTRUCT& p, IKeyQueue& queue) {
    DWORD vkCode = p->vkCode;

    if (vkCode >= 0 && vkCode < MAGICFN_RANGE) {
        DWORD hotkey = m_magicFnEvents->hotkey[vkCode];

        if (hotkey != 0) {
            m_keyQueue->push(hotkey, KeyState::UP);
            return MacroKeyResult::BLOCK;
        }

        KeyEventFunc onEvent = m_magicFnEvents->onReleasing[vkCode];
        if (onEvent != NULL) {
            if (onEvent(p, *m_keyMacro) == MacroKeyResult::BLOCK) {
                return MacroKeyResult::BLOCK;
            }
        }
    }
    return MacroKeyResult::PASS;
}