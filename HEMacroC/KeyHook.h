#pragma once
#include <Windows.h>
#include <iostream>

extern LRESULT OnKeyPressed(PKBDLLHOOKSTRUCT);
extern LRESULT OnKeyReleased(PKBDLLHOOKSTRUCT);

void RunKeyHook();