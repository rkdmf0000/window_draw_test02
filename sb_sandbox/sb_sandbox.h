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
    class client : public winApp
    {
        ~client();
    protected:
    private:
        LRESULT CALLBACK privateWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    public:
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
