#include <iostream>
#include <Windows.h>

// DLL 함수 포인터 가져오기
typedef void (*ACTION)();
typedef bool (*ACTION_CONSTCHAR)(const char*);

int main()
{
    HINSTANCE hDll = LoadLibrary(L"./HEMacro.dll");
    
    if (hDll == NULL) {
        std::cout << "HEMacro.dll loads failed" << std::endl;
    }
    else {
        ACTION runMacro = (ACTION)GetProcAddress(hDll, "runMacro");
        ACTION stopMacro = (ACTION)GetProcAddress(hDll, "stopMacro");

        runMacro();
    }

    return 0;
}