#include <Windows.h>

typedef struct Node {
    INPUT input;
    Node* next;
} Node;

Node* FirstNode = NULL;
Node* LastNode = NULL;

bool IsSendQueueEmpty() {
    return (FirstNode == NULL);
}

void PushSendQueue(size_t size, INPUT inputs[]) {
    for (size_t i = 0; i < size; i++) {
        Node* node = new Node();
        node->input = inputs[i];

        if (LastNode == NULL) {
            FirstNode = node;
            LastNode = node;
        }
        else {
            LastNode->next = node;
            LastNode = node;
        }
    }

    SendInput(size, inputs, sizeof(INPUT));
}

void PopSendQueue() {
    if (FirstNode == NULL) return;

    Node* node = FirstNode;
    Node* next = node->next;
    if (next == NULL) {
        FirstNode = NULL;
        LastNode = NULL;
    }
    else {
        FirstNode = next;
    }

    delete &node;
}

bool EqualsInputAndFirstNode(INPUT& input) {
    INPUT* original = &(input);
    if ((original->type == input.type)
        && (original->ki.wVk == input.ki.wVk)
        && (original->ki.dwFlags == input.ki.dwFlags)) {
        return 1;
    }
    else {
        return 0;
    }
}