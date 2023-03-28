#include "InputQueue.h"
using namespace std;

namespace KeyHook {
    InputQueue InputQueue::Instance;

    int InputQueue::count() {
        return m_count;
    }

    InputQueueState InputQueue::state() {
        return m_state;
    }

    bool InputQueue::isEmpty() {
        return (m_firstNode == NULL);
    }

    void InputQueue::push(size_t size, INPUT inputs[]) {
        for (size_t i = 0; i < size; i++) {
            InputNodeFlags flag = (inputs[i].ki.dwFlags == 0) ? DOWN : UP;

            push(inputs[i].ki.wVk, flag);
        }
    }

    void InputQueue::push(VKCODE vkCode, InputNodeFlags flag) {
        InputQueueNode* node = new InputQueueNode();
        node->vkCode = vkCode;
        node->flag = flag;

        pushNode(node);
    }

    void InputQueue::pushNode(InputQueueNode* node) {
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

    void InputQueue::pop() {
        if (isEmpty()) return;

        Node* node = m_firstNode;
        Node* next = node->next;
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

    void InputQueue::sendFirstNode() {
        INPUT input{};

        input.type = INPUT_KEYBOARD;
        input.ki.wVk = (WORD)m_firstNode->vkCode;

        if (m_firstNode->flag == UP) {
            input.ki.dwFlags = KEYEVENTF_KEYUP;
        }

        SendInput((UINT)1, &input, sizeof(INPUT));
    }

    
    bool InputQueue::match(VKCODE vkCode, InputNodeFlags flag) {
        if (isEmpty()) return false;

        return (m_firstNode->vkCode == vkCode && m_firstNode->flag == flag);
    }

    InputQueueNode* InputQueue::rawNodeBegin() {
        return m_firstNode;
    }
}