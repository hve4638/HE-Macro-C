#include <iostream>
#include "HEMacro/HEMacroLoader.h"

using namespace std;

int main()
{
	HEMacroLoader heMacro = { "./HEMacro.dll" };
	heMacro.load();

	cout << heMacro.runMacro() << endl;
}
