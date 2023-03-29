#include "pch.h"
#include "KeyEvents.h"

using namespace KeyHook;
// 1 리턴은 기존값 블록, 0 리턴은 기존값도 입력

LRESULT EventDownWithCtrl(PKBDLLHOOKSTRUCT p) {
    InputQueue::Instance.push(VK_LCONTROL, DOWN);
    InputQueue::Instance.push(p->vkCode, DOWN);
    return 1;
}
LRESULT EventUpWithCtrl(PKBDLLHOOKSTRUCT p) {
    InputQueue::Instance.push(VK_LCONTROL, UP);
    InputQueue::Instance.push(p->vkCode, UP);
    return 1;
}