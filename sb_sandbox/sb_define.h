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
#include <memory.h>
#include <algorithm>

#include <gdiplus.h>
//#pragma comment(lib, "gdiplus.lib")

//#include <afxwin.h>


namespace SB_SANDBOX {



    enum class TYPE_RESOURCE_CONTROL
    {
        HBITMAP,           //done
        BITMAP,            //done
        INT,               //done
        UINT,
        CHAR,
        STRING,
        HDC,               //done
        PAINTSTRUCT,       //done
        HBRUSH,
        HPEN,
        RECT,
        HWND,               //done
        GDIPLUS_IMAGE,      //done
        GDIPLUS_GRAPHICS    //done
    };

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


    typedef void* RESOURCE_PTR;
    typedef void** RESOURCE_COLLECTOR;
    typedef std::vector<std::string> RESOURCE_NAME_BASKET;
    typedef std::vector<SB_SANDBOX::TYPE_RESOURCE_CONTROL> RESOURCE_TYPE_BASKET;
};







#define D_GAME_NAME			"API Sample"	///< 어플리케이션의 이름
#define D_SCREEN_WIDTH		500			///< 어플리케이션의 최대 가로 값
#define D_SCREEN_HEIGHT		500				///< 어플리케이션의 최대 세로 값
#define D_WINDOW_WIDTH		GetSystemMetrics(SM_CXSCREEN)		//!< 윈도우의 가로 값
#define D_WINDOW_HEIGHT		GetSystemMetrics(SM_CYSCREEN)		//!< 윈도우의 세로 값
#define D_SCREEN_XPOS		D_WINDOW_WIDTH	/ 2 - D_SCREEN_WIDTH  / 2	//!< 윈도우의 위치 (가로) 값
#define D_SCREEN_YPOS		D_WINDOW_HEIGHT	/ 2 - D_SCREEN_HEIGHT / 2	//!< 윈도우의 위치 (세로) 값
#define SAFE_DELETE(p)	\
{ \
	do					\
	{					\
		delete p;		\
		p = NULL;		\
	}while (0);			\
}





#endif //WINDOW_DRAW_TEST02_SB_DEFINE_H

