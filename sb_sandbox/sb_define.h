//
// Created by my_fl on 2020-10-09.
//

#ifndef WINDOW_DRAW_TEST02_SB_DEFINE_H
#define WINDOW_DRAW_TEST02_SB_DEFINE_H

#include <iostream>
#include <windows.h>
#include <stdlib.h>

#include <string.h>
#include <tchar.h>
#include <locale.h>
#include <memory>
#include <functional>

#include <vector>

#include <ctime>

#include <chrono>

namespace SB_SANDBOX {
    struct _SETCREATEPOSITION {
        INT x;
        INT y;
        INT w;
        INT h;
    };

    struct _SETCREATEOPTION {
        COLORREF bgColor = RGB(0, 0, 0);
        COLORREF color = RGB(255, 255, 255);
        wchar_t mainString[255] = L"Undefined text";
        wchar_t subString[255];
        wchar_t description[255];
    };

    struct _SETCREATEDEFAULT {
        _SETCREATEPOSITION pos{0, 0, 0, 0};
        HINSTANCE hinc{};
        HWND hwnd{};

        explicit _SETCREATEDEFAULT(_SETCREATEPOSITION pos) : pos(pos) {
            std::cout << "(" << this << ") --STRUCTURE DECLARED(pos)" << '\n';
        };

        explicit _SETCREATEDEFAULT(HINSTANCE hinc) : hinc(hinc) {
            std::cout << "(" << this << ") --STRUCTURE DECLARED(hinc)" << '\n';
        };

        explicit _SETCREATEDEFAULT(HWND hwnd) : hwnd(hwnd) {
            std::cout << "(" << this << ") --STRUCTURE DECLARED(hwnd)" << '\n';
        };

        explicit _SETCREATEDEFAULT(_SETCREATEPOSITION pos, HINSTANCE hinc) : pos(pos), hinc(hinc) {
            std::cout << "(" << this << ") --STRUCTURE DECLARED(pos, hinc)" << '\n';
        };

        explicit _SETCREATEDEFAULT(_SETCREATEPOSITION pos, HINSTANCE hinc, HWND hwnd) : pos(pos), hinc(hinc), hwnd(hwnd) {
            std::cout << "(" << this << ") --STRUCTURE DECLARED(pos, hinc, hwnd)" << '\n';
        };

        _SETCREATEDEFAULT() { std::cout << "(" << this << ") --STRUCTURE DECLARED" << '\n'; }

        ~_SETCREATEDEFAULT() { std::cout << "(" << this << ") --STRUCTURE DESTROYED" << '\n'; }
    };

    struct _SETCREATEVIRTUAL {
        _SETCREATEPOSITION pos{0, 0, 0, 0};

        _SETCREATEVIRTUAL(_SETCREATEPOSITION pos) : pos(pos) {
            std::cout << "(" << this << ") --VIRTUAL STRUCTURE DECLARED(pos)" << '\n';
        };

        _SETCREATEVIRTUAL() { std::cout << "(" << this << ") --VIRTUAL STRUCTURE DECLARED" << '\n'; }

        ~_SETCREATEVIRTUAL() { std::cout << "(" << this << ") --VIRTUAL STRUCTURE DESTROYED" << '\n'; }
    };

};



#endif //WINDOW_DRAW_TEST02_SB_DEFINE_H

