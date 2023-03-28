#pragma once
#include "pch.h"
#include <Windows.h>
#define MAGICFN_RANGE 256
#define VKCODE DWORD
#define KeyEventLambda(x) [](PKBDLLHOOKSTRUCT x) -> LRESULT

#ifdef KEYHOOK_EXPORTS
#define KEYHOOK_API __declspec(dllexport)
#else
#define KEYHOOK_API __declspec(dllimport)
#endif

namespace KeyHook {
    typedef LRESULT(*KeyEvent)(PKBDLLHOOKSTRUCT);

    namespace InputEditer {
        extern "C" KEYHOOK_API void Down(INPUT& input, WORD vk);
        extern "C" KEYHOOK_API void Up(INPUT& input, WORD vk);
    }

    class KEYHOOK_API IKeyListener {
    public:
        virtual LRESULT pressing(PKBDLLHOOKSTRUCT) = 0;
        virtual LRESULT releasing(PKBDLLHOOKSTRUCT) = 0;
    };


    class KEYHOOK_API KeyHooker {
    private:
        bool m_magicFnEnabled = false;
        IKeyListener* m_keyListener = NULL;

    public:
        void setKeyListener(IKeyListener*);
        LRESULT onHook(int, WPARAM, LPARAM);
        void run();
    };

    class KEYHOOK_API MagicFnEvents {
    private:
    public:
        KeyEvent pressEvents[MAGICFN_RANGE] = { 0, };
        KeyEvent releaseEvents[MAGICFN_RANGE] = { 0, };
        WORD hotkey[MAGICFN_RANGE] = { 0, };

        void setPressAndReleaseEvent(WORD, KeyEvent, KeyEvent);
    };

    class KEYHOOK_API KeyListener : public IKeyListener {
        MagicFnEvents* m_magicFnEvents;
    public:
        void setMagicFnEvents(MagicFnEvents*);

        LRESULT pressing(PKBDLLHOOKSTRUCT) override;
        LRESULT releasing(PKBDLLHOOKSTRUCT) override;
    };

    enum InputQueueState {
        WAITING,
        READY,
        FINISHED,
    };
    enum InputNodeFlags {
        DOWN,
        UP,
    };

    typedef struct Node {
        DWORD vkCode;
        InputNodeFlags flag;
        Node* next;
    } InputQueueNode;

    class KEYHOOK_API InputQueue {
    private:
        InputQueueNode* m_firstNode = NULL;
        InputQueueNode* m_lastNode = NULL;
        InputQueueState m_state = FINISHED;
        int m_count = 0;

        void pushNode(InputQueueNode*);
        void sendFirstNode();
    public:
        static InputQueue Instance;

        int count();
        InputQueueState state();
        bool isEmpty();
        void pushInput(size_t, INPUT[]);
        void push(VKCODE, InputNodeFlags);
        void pop();
        bool match(VKCODE, InputNodeFlags);

        InputQueueNode* rawNodeBegin();
    };


    extern "C" KEYHOOK_API void RunKeyHook(KeyHooker*);
}