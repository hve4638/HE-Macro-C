#pragma once
#include "precompiled.h"

namespace KeyHook {
    enum InputQueueState {
        WAITING,
        READY,
        FINISHED,
    };
    enum InputNodeFlags {
        DOWN,
        UP,
    };

    typedef struct Node {
        DWORD vkCode;
        InputNodeFlags flag;
        Node* next;
    } InputQueueNode;

    class InputQueue {
    private:
        InputQueueNode* m_firstNode = NULL;
        InputQueueNode* m_lastNode = NULL;
        InputQueueState m_state = FINISHED;
        int m_count = 0;

        void pushNode(InputQueueNode*);
        void sendFirstNode();
    public:
        static InputQueue Instance;

        int count();
        InputQueueState state();
        bool isEmpty();
        void push(size_t, INPUT[]);
        void push(VKCODE, InputNodeFlags);
        void pop();
        bool match(VKCODE, InputNodeFlags);

        InputQueueNode* rawNodeBegin();
    };

}