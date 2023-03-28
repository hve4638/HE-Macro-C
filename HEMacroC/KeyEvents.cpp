#include "KeyHook.h"

LRESULT NoEvent(PKBDLLHOOKSTRUCT p) {
    return 1;
}

LRESULT EventPress(PKBDLLHOOKSTRUCT p) {
    INPUT input[1];
    ZeroMemory(input, sizeof(input));

    SetInputKeyDown(input[0], VK_LCONTROL);
    SendInput(1, input, sizeof(INPUT));
    return 1;
}

LRESULT EventRelease(PKBDLLHOOKSTRUCT p) {
    INPUT input[1];
    ZeroMemory(input, sizeof(input));

    SetInputKeyUp(input[0], VK_LCONTROL);

    SendInput(1, input, sizeof(INPUT));
    return 1;
}

LRESULT EventPressWithCtrl(PKBDLLHOOKSTRUCT p) {
    INPUT input[2];
    ZeroMemory(input, sizeof(input));

    SetInputKeyDown(input[0], VK_LCONTROL);
    SetInputKeyDown(input[1], (WORD)(p->vkCode));

    //PushSendQueue(2, input);
    SendInput(2, input, sizeof(INPUT));
    return 1;
}

LRESULT EventReleaseWithCtrl(PKBDLLHOOKSTRUCT p) {
    INPUT input[2];
    ZeroMemory(input, sizeof(input));

    SetInputKeyUp(input[0], VK_LCONTROL);
    SetInputKeyUp(input[1], (WORD)(p->vkCode));

    SendInput(2, input, sizeof(INPUT));
    return 1;
}


LRESULT EventClick(PKBDLLHOOKSTRUCT p) {
    INPUT input[1];
    ZeroMemory(input, sizeof(input));

    SetInputKeyDown(input[0], (WORD)(p->vkCode));

    SendInput(1, input, sizeof(INPUT));
    return 1;
}

LRESULT EventClickWithCtrl(PKBDLLHOOKSTRUCT p) {
    INPUT input[2];
    ZeroMemory(input, sizeof(input));

    SetInputKeyDown(input[0], VK_CONTROL);
    SetInputKeyDown(input[0], (WORD)(p->vkCode));

    SendInput(1, input, sizeof(INPUT));
    return 1;
}