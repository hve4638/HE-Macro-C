#include <iostream>
#include "KeyHook/KeyHookLoader.h"

using namespace std;
KeyHookLoader keyHookLoader = { "./KeyHook.dll" };

int main()
{
	keyHookLoader.load();
	cout << keyHookLoader.isLoaded() << endl;
}
