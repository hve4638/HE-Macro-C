#include <iostream>
#include <windows.h>
#include "HEMacro/HEMacroLoader.h"

using namespace std;

HEMacroLoader loader = { "./HEMacro.dll" };

BOOL WINAPI handleInterrupt(DWORD signal) {
	if (signal == CTRL_C_EVENT) {
		std::cout << "KeyboardInterrupt" << std::endl;

		cout << loader.writeQueueLog(".tmpqueuelog.txt") << endl;
		std::cout << "done" << std::endl;
		return TRUE;
	}
	else {
		cout << "signal: " << signal << endl;
	}
	return FALSE;
}

int main() {
	if (!loader.load()) {
		cerr << "load failed" << endl;
		return -1;
	}
	
	SetConsoleCtrlHandler(handleInterrupt, TRUE);
	cout << "version: " << loader.version() << endl;
	cout << "Macro Enabled" << endl;
	cout << loader.runMacro() << endl;

	cout << "normal exit" << endl;
}

