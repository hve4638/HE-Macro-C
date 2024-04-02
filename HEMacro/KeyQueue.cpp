#include "KeyQueue.h"
using namespace std;

KeyQueue KeyQueue::Instance;

int KeyQueue::count() {
    return m_count;
}

InputQueueState KeyQueue::state() {
    return m_state;
}

bool KeyQueue::isEmpty() {
    return (m_firstNode == NULL);
}

void KeyQueue::pushInput(size_t size, INPUT inputs[]) {
    for (size_t i = 0; i < size; i++) {
        KeyState flag = (inputs[i].ki.dwFlags == 0) ? KeyState::DOWN : KeyState::UP;

        push(inputs[i].ki.wVk, flag);
    }
}

void KeyQueue::push(VKCODE vkCode, KeyState flag) {
    InputQueueNode* node = new InputQueueNode();
    node->vkCode = vkCode;
    node->flag = flag;

    pushNode(node);
}

void KeyQueue::pushNode(InputQueueNode* node) {
    if (m_lastNode == NULL) {
        m_firstNode = node;
        m_lastNode = node;
        sendFirstNode();
    }
    else {
        m_lastNode->next = node;
        m_lastNode = node;
    }

    m_count++;
}

void KeyQueue::pop() {
    if (isEmpty()) return;

    InputQueueNode* node = m_firstNode;
    InputQueueNode* next = node->next;
    if (next == NULL) {
        m_firstNode = NULL;
        m_lastNode = NULL;
    }
    else {
        m_firstNode = next;
        sendFirstNode();
    }

    m_count--;
    delete node;
}

void KeyQueue::sendFirstNode() {
    INPUT input{};

    input.type = INPUT_KEYBOARD;
    input.ki.wVk = (WORD)m_firstNode->vkCode;

    if (m_firstNode->flag == KeyState::UP) {
        input.ki.dwFlags = KEYEVENTF_KEYUP;
    }

    SendInput((UINT)1, &input, sizeof(INPUT));
}


bool KeyQueue::match(VKCODE vkCode, KeyState flag) {
    if (isEmpty()) return false;

    return (m_firstNode->vkCode == vkCode && m_firstNode->flag == flag);
}

InputQueueNode* KeyQueue::rawNodeBegin() {
    return m_firstNode;
}