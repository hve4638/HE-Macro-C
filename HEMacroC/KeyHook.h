#include <Windows.h>
#define MAGICFN_RANGE 256

typedef LRESULT(*KeyEvent)(PKBDLLHOOKSTRUCT);

extern KeyEvent MagicFnPressEvent[MAGICFN_RANGE];
extern KeyEvent MagicFnReleaseEvent[MAGICFN_RANGE];
extern WORD MagicFnHotkey[MAGICFN_RANGE];
extern int KeyInMagicFnRange(DWORD vk);

extern LRESULT OnKeyPressed(PKBDLLHOOKSTRUCT);
extern LRESULT OnKeyReleased(PKBDLLHOOKSTRUCT);

extern void RunKeyHook();

extern void MaginFnSetKey(WORD, KeyEvent, KeyEvent);

extern void SetInputKeyDown(INPUT& input, WORD vk);
extern void SetInputKeyUp(INPUT& input, WORD vk);

extern LRESULT NoEvent(PKBDLLHOOKSTRUCT);
extern LRESULT EventPressWithCtrl(PKBDLLHOOKSTRUCT);
extern LRESULT EventReleaseWithCtrl(PKBDLLHOOKSTRUCT);

extern LRESULT EventPress(PKBDLLHOOKSTRUCT p);
extern LRESULT EventRelease(PKBDLLHOOKSTRUCT p);