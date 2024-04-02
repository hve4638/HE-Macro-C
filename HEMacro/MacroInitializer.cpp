#include "MacroInitializer.h"
#include "Debug/Debug.h"
#define VK_PGUP 33
#define VK_PGDOWN 34

using namespace std;

static void setMacro(MagicFnMacroConfiguration& configuration);

void initializeMacroToDefaults(MagicFnMacroConfiguration& configuration) {
    setMacro(configuration);

#ifdef _DEBUG
    configuration.onMagicFnEnabled = [](IKeyMacro& macro) {
        //cout << "enabled" << endl;
    };
    configuration.onMagicFnDisabled = [](IKeyMacro& macro) {
        //cout << "disabled" << endl;
    };
#endif
}


void setMacro(MagicFnMacroConfiguration& configuration) {
    configuration.onPressing['Z'] = KeyMacroLambda(kh, macro) {
        macro.downCtrl().click('Z').upCtrl();
        return BLOCK;
    };
    configuration.onPressing['X'] = KeyMacroLambda(kh, macro) {
        macro.downCtrl().click('X').upCtrl();
        return BLOCK;
    };
    configuration.onPressing['C'] = KeyMacroLambda(kh, macro) {
        macro.downCtrl().click('C').upCtrl();
        return BLOCK;
    };
    configuration.onPressing['V'] = KeyMacroLambda(kh, macro) {
        macro.downCtrl().click('V').upCtrl();
        return BLOCK;
    };
    configuration.onPressing['B'] = KeyMacroLambda(kh, macro) {
        macro.downCtrl().click('B').upCtrl();
        return BLOCK;
    };
    configuration.onPressing['A'] = KeyMacroLambda(kh, macro) {
        macro.downCtrl().click('A').upCtrl();
        return BLOCK;
    };
    configuration.onPressing['S'] = KeyMacroLambda(kh, macro) {
        macro.downCtrl().click('S').upCtrl();
        return BLOCK;
    };
    configuration.onPressing['D'] = KeyMacroLambda(kh, macro) {
        macro.downCtrl().click('D').upCtrl();
        return BLOCK;
    };
    configuration.onPressing['F'] = KeyMacroLambda(kh, macro) {
        macro.downCtrl().click('F').upCtrl();
        return BLOCK;
    };

    configuration.onMagicFnEnabled = [](IKeyMacro& macro) {};
    configuration.onMagicFnDisabled = [](IKeyMacro& macro) { macro.upCtrl().upShift(); };

    configuration.onPressing[VK_OEM_COMMA] = KeyMacroLambda(kh, macro) { //'<'
        macro.downCtrl().downWin();
        macro.click(VK_LEFT);
        macro.upCtrl().upWin();

        return BLOCK;
    };
    configuration.onPressing[VK_OEM_PERIOD] = KeyMacroLambda(kh, macro) { //'>'
        macro.downCtrl().downWin();
        macro.click(VK_RIGHT);
        macro.upCtrl().upWin();

        return BLOCK;
    };

    configuration.onPressing['Q'] = KeyMacroLambda(kh, macro) {
        DebugOut("*Q*");
        macro.downCtrl();
        return BLOCK;
    };
    configuration.onReleasing['Q'] = KeyMacroLambda(kh, macro) {
        DebugOut("*Q* (UP)");
        macro.upCtrl();
        return BLOCK;
    };
    configuration.onPressing['W'] = KeyMacroLambda(kh, macro) {
        DebugOut("*W*");
        macro.downShift();
        macro.lock(VK_LSHIFT);
        return BLOCK;
    };
    configuration.onReleasing['W'] = KeyMacroLambda(kh, macro) {
        DebugOut("*W* (UP)");
        macro.upShift();
        macro.unlock(VK_LSHIFT);
        return BLOCK;
    };

    configuration.onPressing['P'] = KeyMacroLambda(kh, macro) {
        macro.downShift().down(VK_LEFT).up(VK_LEFT).upShift();
        return BLOCK;
    };

    configuration.hotkey['E'] = VK_CAPITAL;
    //magicFnMacro.hotkey['A'] = VK_LEFT;
    //magicFnMacro.hotkey['D'] = VK_RIGHT;
    //magicFnMacro.hotkey['S'] = VK_DOWN;
    //magicFnMacro.hotkey['F'] = VK_UP;

    configuration.hotkey['`'] = VK_PAUSE;
    configuration.hotkey['I'] = VK_UP;
    configuration.hotkey['J'] = VK_LEFT;
    configuration.hotkey['K'] = VK_DOWN;
    configuration.hotkey['L'] = VK_RIGHT;

    configuration.hotkey['1'] = VK_F13;
    configuration.hotkey['2'] = VK_F14;
    configuration.hotkey['3'] = VK_F15;
    configuration.hotkey['4'] = VK_F16;
    configuration.hotkey['5'] = VK_F17;
    configuration.hotkey['6'] = VK_F18;
    configuration.hotkey['7'] = VK_F19;
    configuration.hotkey['8'] = VK_F20;
    configuration.hotkey['9'] = VK_F21;
    configuration.hotkey['0'] = VK_F22;
    configuration.hotkey[189] = VK_F23; // '-'lllkkk
    configuration.hotkey[187] = VK_F24; // '='

    configuration.hotkey[0xDB] = VK_PGUP; // '['
    configuration.hotkey[0xDD] = VK_PGDOWN; // ']'

    configuration.hotkey['R'] = VK_INSERT;

    configuration.hotkey['U'] = VK_HOME;
    configuration.hotkey['O'] = VK_END;
    configuration.hotkey['N'] = VK_BACK;
    configuration.hotkey['M'] = VK_DELETE;
    configuration.hotkey[0xBA] = VK_RETURN; // 0xBA=';', VK_RETURN=ENTER

    configuration.hotkey['H'] = 21; // 'ÇÑ/¿µ'
}