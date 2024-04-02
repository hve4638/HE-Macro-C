#include <iostream>
#include <stdlib.h>
#include <mutex>
#include "typedef.h"
#include "RawHooker.h"
#include "KeyHook.h"
#include "Debug/Debug.h"

using namespace std;

// SetWindowsHookEx�� �����ϱ� ���� ���� ���� �Ҵ�
// ���� ������ ����ϹǷ� ���μ��� �� �ϳ��� ó���� �� ����
static IKeyQueue* g_currentInputQueue = NULL;
static IKeyHooker* g_currentHooker = NULL;

// SetWindowsHookEx�� �����ϱ� ���� hook�Լ�
// ���� ������ ����ϹǷ� ���μ��� �� �ϳ��� ó���� �� ����
static LRESULT CALLBACK hookProc(int nCode, WPARAM wParam, LPARAM lParam);

RawHookerStatus RawHooker::s_status = FREE;
bool RawHooker::s_stopsignal = false;

RawHooker::RawHooker(IKeyHooker* hooker) {
    DebugInfo("Construct RawHooker");
    // RawHooker�� ���μ����� �ϳ��� ���� �۵��ϹǷ�, �̹� ������� ��� �ʿ��� �ʱ�ȭ�� �������� ����
    // TODO : ���ǹ� �бⰡ ��Ƽ������ ȯ�濡�� ����� �������� ���� �� �����Ƿ� Lock �߰� �ʿ� 
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
