#pragma once
#include "KeyHook/typedef.h"
#include "KeyHook/IKeyQueue.h"

// RawHooker¿¡¼­ »ç¿ëµÊ
class KeyQueue : public IKeyQueue {
private:
    InputQueueNode* m_firstNode = NULL;
    InputQueueNode* m_lastNode = NULL;
    InputQueueState m_state = FINISHED;
    int m_count = 0;

    void pushNode(InputQueueNode*);
    void sendFirstNode();
public:
    static KeyQueue Instance;

    int count() override;
    InputQueueState state() override;
    bool isEmpty() override;
    void pushInput(size_t, INPUT[]) override;
    void push(VKCODE, KeyState) override;
    void pop() override;
    bool match(VKCODE, KeyState) override;

    InputQueueNode* rawNodeBegin() override;
};