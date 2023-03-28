#include "KeyHook.h"

namespace KeyHook {
    // 1 리턴은 기존값 블록, 0 리턴은 기존값도 입력

    LRESULT NoEvent(PKBDLLHOOKSTRUCT p) {
        return 1;
    }

    LRESULT EventDownWithCtrl(PKBDLLHOOKSTRUCT p) {
        InputQueue::Instance.push(VK_CONTROL, DOWN);
        InputQueue::Instance.push(p->vkCode, DOWN);
        return 1;
    }
    LRESULT EventUpWithCtrl(PKBDLLHOOKSTRUCT p) {
        InputQueue::Instance.push(VK_CONTROL, UP);
        InputQueue::Instance.push(p->vkCode, UP);
        return 1;
    }

    LRESULT EventPressWithCtrl(PKBDLLHOOKSTRUCT p) {
        INPUT input[2];
        ZeroMemory(input, sizeof(input));

        InputEditer::Down(input[0], VK_LCONTROL);
        InputEditer::Down(input[1], (WORD)(p->vkCode));

        //PushSendQueue(2, input);
        InputQueue::Instance.pushInput(2, input);
        return 1;
    }

    LRESULT EventReleaseWithCtrl(PKBDLLHOOKSTRUCT p) {
        INPUT input[2];
        ZeroMemory(input, sizeof(input));

        InputEditer::Up(input[0], VK_LCONTROL);
        InputEditer::Up(input[1], (WORD)(p->vkCode));

        InputQueue::Instance.pushInput(2, input);
        return 1;
    }


    LRESULT EventClick(PKBDLLHOOKSTRUCT p) {
        INPUT input[1];
        ZeroMemory(input, sizeof(input));

        InputEditer::Down(input[0], (WORD)(p->vkCode));

        InputQueue::Instance.pushInput(1, input);
        return 1;
    }

    LRESULT EventClickWithCtrl(PKBDLLHOOKSTRUCT p) {
        INPUT input[4];
        ZeroMemory(input, sizeof(input));

        InputEditer::Down(input[0], VK_CONTROL);
        InputEditer::Down(input[1], (WORD)(p->vkCode));
        InputEditer::Up(input[2], (WORD)(p->vkCode));
        InputEditer::Up(input[3], VK_CONTROL);

        InputQueue::Instance.pushInput(4, input);
        return 1;
    }
}