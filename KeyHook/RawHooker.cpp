#include <iostream>
#include <stdlib.h>
#include <mutex>
#include "typedef.h"
#include "RawHooker.h"
#include "KeyHook.h"
#include "Debug/Debug.h"

using namespace std;

// SetWindowsHookEx에 연결하기 위한 전역 변수 할당
// 전역 변수를 사용하므로 프로세스 당 하나만 처리할 수 있음
static IKeyQueue* g_currentInputQueue = NULL;
static IKeyHooker* g_currentHooker = NULL;

// SetWindowsHookEx에 연결하기 위한 hook함수
// 전역 변수를 사용하므로 프로세스 당 하나만 처리할 수 있음
static LRESULT CALLBACK hookProc(int nCode, WPARAM wParam, LPARAM lParam);

RawHookerStatus RawHooker::s_status = FREE;
bool RawHooker::s_stopsignal = false;

RawHooker::RawHooker(IKeyHooker* hooker) {
    DebugInfo("Construct RawHooker");
    // RawHooker는 프로세스당 하나만 정상 작동하므로, 이미 사용중인 경우 필요한 초기화를 진행하지 않음
    // TODO : 조건문 분기가 멀티스레드 환경에서 제대로 동작하지 않을 수 있으므로 Lock 추가 필요 
    if (s_status == INUSE) {
        m_valid = false;
        m_hooker= nullptr;
    }
    else {
        s_status = INUSE;
        m_valid = true;
        m_hooker = hooker;

        g_currentHooker = hooker;
    }
}

RawHooker::~RawHooker() {
    DebugInfo("Destruct RawHooker");
    if (m_hHook != NULL) UnhookWindowsHookEx(m_hHook);
    if (m_valid) {
        s_status = FREE;
        g_currentHooker = NULL;
        g_currentInputQueue = NULL;
    }
}

void RawHooker::hook() {
    if (!m_valid) {
        return;
    }
    DebugInfo("Enter KeyHook");

    m_hHook = SetWindowsHookEx(WH_KEYBOARD_LL, hookProc, NULL, 0);

    s_stopsignal = false;
    MSG msg;
    while (!s_stopsignal && GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    DebugInfo("Exit KeyHook");
}

LRESULT CALLBACK hookProc(int nCode, WPARAM wParam, LPARAM lParam) {
    KeyHookInfo info = { 0, };
    info.nCode = nCode;
    info.wParam = wParam;
    info.lParam = lParam;

    auto result = g_currentHooker->onHook(info, 0);
    switch (result) {
    case BLOCK:
        return 1;
    case PASS:
    default:
        return CallNextHookEx(NULL, nCode, wParam, lParam);
    }
}
