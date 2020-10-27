//
// Created by my_fl on 2020-10-09.
//


#ifndef WINDOW_DRAW_TEST02_SB_SANDBOX_H
#define WINDOW_DRAW_TEST02_SB_SANDBOX_H
#include "sb_define.h"


namespace SB_SANDBOX
{

    class winApp
    {
    protected:
        LPCTSTR lpClassName;
        LPCTSTR lpWndName;
        HWND wndHandle;
        HINSTANCE processHandle;
    private:
    public:
    };


    struct UIFeedback
    {
        static FLOAT mouseDefaultTick;
        static UINT mouseX;
        static UINT mouseVX;
        static UINT mouseY;
        static UINT mouseVY;

        static UINT mouseUP;
        static UINT mouseDown;

        static UINT mouseLUP;
        static UINT mouseLDown;
        static UINT mouseRUP;
        static UINT mouseRDown;

        static UINT mouseIsClicked;

    };

    namespace DCTOOLSET
    {
        VOID drawTextAtAFrame(HWND handle, HDC hdc, RECT rect, LPCTSTR text);
    };

    class client : public winApp, public UIFeedback
    {
        ~client();
    protected:
    private:
        static LRESULT CALLBACK privateWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
        VOID afterMessageDispatch();
    public:

        //open-variables
        static INT LIMITOVERFLOWFLAGINT;
        static std::vector<UINT> helloworld();
        UINT frameBegin;
        UINT frameEnd;
        UINT frameCnt;
        FLOAT frame;


        static LRESULT CALLBACK publicWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
        LPCTSTR& get_lpClassName();
        LPCTSTR& get_lpWndName();
        HWND& get_wndHandle();
        HINSTANCE& get_processHandle();
        explicit client(HINSTANCE hin);

        VOID initApp();
        VOID initInstance();
        INT WINAPI run();

    };
};



#endif //WINDOW_DRAW_TEST02_SB_SANDBOX_H
