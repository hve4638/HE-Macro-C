#pragma once
#include "api.h"
#include "KeyHook/IKeyHooker.h"

// KeyListener�� ������� KeyHook ����
extern "C" KEYHOOK_API int runKeyHook(IKeyHooker*);

// KeyHook ���� ��ȣ ����
// ��� ����Ǵ� ���� �ƴ� ���� Ű �Է� ó�� �� ����ȴ�
extern "C" KEYHOOK_API void stopKeyHook();

// KeyHook ���� ���� Ȯ��
extern "C" KEYHOOK_API int isKeyHookRunning();

extern "C" KEYHOOK_API const char* version();

