//
// Created by my_fl on 2020-10-09.
//
#include "sb_sandbox.h"
VOID SB_SANDBOX::FUNCTION::createAWindowPalette(std::unique_ptr<_SETCREATEDEFAULT> &set, LPCTSTR &lpszClassName, BOOL ImmediateExposure) {
    std::cout << "(" << &set->hwnd << ") ";
    std::cout << "WINDOW-" << "(" << &*set << ")" << "-POS : " << set->pos.x << "/";
    std::cout << " " << set->pos.y << "/";
    std::cout << " " << set->pos.w << "/";
    std::cout << " " << set->pos.h << '\n';


    set->hwnd = CreateWindow(
            lpszClassName,
            _T("title"),
            WS_OVERLAPPEDWINDOW,
            set->pos.x, set->pos.y,
            set->pos.w, set->pos.h,
            NULL,
            NULL,
            set->hinc,
            NULL
    );

    if (!set->hwnd) {
        MessageBox(NULL,
                   _T("Call to Create\"Window\" failed!"),
                   _T("Windows Desktop Alert"),
                   0);
        std::cout << "(" << &set->hwnd << ") " << "--FAILURE" << '\n';
    } else {
        std::cout << "(" << &set->hwnd << ") " << "--OK" << "(" << set->hwnd <<  ")" << '\n';
    };


    if (ImmediateExposure == 1) {
        ShowWindow(set->hwnd, 1);
        UpdateWindow(set->hwnd);
    };
};

VOID SB_SANDBOX::FUNCTION::createWindowButton(std::unique_ptr<_SETCREATEDEFAULT> &set, HWND &Palette, HMENU TriggerID, BOOL ImmediateExposure) {
    std::cout << "(" << &set->hwnd << ") ";
    std::cout << "BUTTON-" << "(" << &*set << ")" << "-POS : " << set->pos.x << "/";
    std::cout << " " << set->pos.y << "/";
    std::cout << " " << set->pos.w << "/";
    std::cout << " " << set->pos.h << '\n';

    set->hwnd = CreateWindow(
            _T("BUTTON"),
            _T("BUTTON TEXT"),
            WS_CHILD | WS_VISIBLE,
            set->pos.x, set->pos.y,
            set->pos.w, set->pos.h,
            Palette,
            TriggerID,
            set->hinc,
            NULL
    );

    if (!set->hwnd) {
        MessageBox(NULL,
                   _T("Call to Create\"Button\" failed!"),
                   _T("Windows Desktop Alert"),
                   0);
        std::cout << "(" << &set->hwnd << ") " << "--FAILURE" << '\n';
    } else {
        std::cout << "(" << &set->hwnd << ") " << "--OK" << '\n';
    };


    if (ImmediateExposure == 1) {
        ShowWindow(set->hwnd, 1);
        UpdateWindow(set->hwnd);
    };
};



VOID SB_SANDBOX::FUNCTION::createClickable(std::unique_ptr<_SETCREATEVIRTUAL> &set, BOOL ImmediateExposure)
{

    std::cout << "hello";
};