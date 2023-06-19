#pragma once
#include "typedef.h"

enum class KeyState {
    DOWN,
    UP
};
enum InputQueueState {
    WAITING,
    READY,
    FINISHED,
};
typedef struct InputQueueNode {
    DWORD vkCode;
    KeyState flag;
    InputQueueNode* next;
} InputQueueNode;


interface IKeyQueue {
    virtual InputQueueState state() abstract;
    virtual int count() abstract;
    virtual bool isEmpty() abstract;
    virtual void pushInput(size_t, INPUT[]) abstract;
    virtual void push(VKCODE, KeyState) abstract;
    virtual void pop() abstract;
    virtual bool match(VKCODE, KeyState) abstract;

    virtual InputQueueNode* rawNodeBegin() abstract;
};