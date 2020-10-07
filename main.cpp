#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <memory>

#define __STANDARD_BUTTON_CLICK_EVENT_HANDLE_NUMBER__ 0x00f0
#define __STANDARD_BUTTON_CLICK_UP_EVENT_HANDLE_NUMBER__ 0x00f1
#define __STANDARD_BUTTON_CLICK_DOWN_EVENT_HANDLE_NUMBER__ 0x00f2

struct _SETCREATEPOSITION {
    INT x;
    INT y;
    INT w;
    INT h;
};

struct _SETCREATEDEFAULT {
    _SETCREATEPOSITION pos{0, 0, 0, 0};
    HINSTANCE hinc;
    HWND hwnd;

    _SETCREATEDEFAULT(_SETCREATEPOSITION pos) : pos(pos) {
        std::cout << "(" << this << ") --STRUCTURE DECLARED(pos)" << '\n';
    };

    _SETCREATEDEFAULT(HINSTANCE hinc) : hinc(hinc) {
        std::cout << "(" << this << ") --STRUCTURE DECLARED(hinc)" << '\n';
    };

    _SETCREATEDEFAULT(HWND hwnd) : hwnd(hwnd) { std::cout << "(" << this << ") --STRUCTURE DECLARED(hwnd)" << '\n'; };

    _SETCREATEDEFAULT(_SETCREATEPOSITION pos, HINSTANCE hinc) : pos(pos), hinc(hinc) {
        std::cout << "(" << this << ") --STRUCTURE DECLARED(pos, hinc)" << '\n';
    };

    _SETCREATEDEFAULT(_SETCREATEPOSITION pos, HINSTANCE hinc, HWND hwnd) : pos(pos), hinc(hinc), hwnd(hwnd) {
        std::cout << "(" << this << ") --STRUCTURE DECLARED(pos, hinc, hwnd)" << '\n';
    };

    _SETCREATEDEFAULT() { std::cout << "(" << this << ") --STRUCTURE DECLARED" << '\n'; }

    ~_SETCREATEDEFAULT() { std::cout << "(" << this << ") --STRUCTURE DESTROYED" << '\n'; }
};



//typedef struct tagBITMAPFILEHEADER {    // 14 = 2+4+2+2+4 (byte)
//    WORD    bfType;  // "BM"이라는 글자가 설정됨
//    DWORD   bfSize;  // 비트맵 파일의 전체 크기
//    WORD    bfReserved1;  // 예약변수(0으로 설정함)
//    WORD    bfReserved2;  // 예약변수(0으로 설정함)
//    DWORD   bfOffBits;  // 파일에서 비트맵 데이터가 있는 위치
//} BITMAPFILEHEADER;
//
//typedef struct tagBITMAPINFOHEADER {  // 40 = 4+4+4+2+2+4+4+4+4+4+4 (byte)
//    DWORD biSize;  // 구조체의 크기
//    LONG biWidth;  // 비트맵의 가로 크기
//    LONG biHeight;  // 비트맵의 세로 크기
//    WORD biPlanes;  // Plane수(1로 설정함)
//    WORD biBitCount;  // 한 픽셀당 비트수
//    DWORD biCompression;  // 압축 유무 플래그
//    DWORD biSizeImage;  // 그림 데이터의 크기
//    LONG biXPelsPerMeter;  // 한 픽셀당 가로 미터
//    LONG biYPelsPerMeter;  // 한 픽셀당 세로 미터
//    DWORD biClrUsed;  // 그림에서 실제 사용되는 컬러 수
//    DWORD biClrImportant;  // 중요하게 사용되는 컬러
//} BITMAPINFOHEADER;
//
//typedef struct tagRGBQUAD { // 4
//    BYTE rgbBlue;  // B성분 (파랑)
//    BYTE rgbGreen; // G성분 (초록)
//    BYTE rgbRed;   // R성분 (빨강)
//    BYTE rgbReserved;
//} RGBQUAD;
//typedef struct tagBITMAPINFO {
//    BITMAPINFOHEADER bmiHeader;
//    RGBQUAD bmiColors[1];
//} BITMAPINFO;



LRESULT CALLBACK WndProc(_In_ HWND hWnd, _In_ UINT message, _In_ WPARAM wParam, _In_ LPARAM lParam) {
    WORD whi = HIWORD(wParam);
    WORD wlo = LOWORD(wParam);
    WORD lhi = HIWORD(lParam);
    WORD llo = LOWORD(lParam);

    switch (message) {
        case WM_MOVE:
            std::cout << "<< WM_MOVE >>" << '\n';
            std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
            std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            break;
        case WM_PAINTICON:
            std::cout << "<< WM_PAINTICON >>" << '\n';
            std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
            std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            break;
        case WM_COMMAND:
            std::cout << "<< WM_COMMAND >>" << '\n';
            std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
            std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            break;
        case WM_CREATE:
            std::cout << "<< WM_CREATE >>" << '\n';
            std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
            std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            break;
        case WM_PAINT:
            PAINTSTRUCT PAINT_STRUCT_OBJECT;
            HDC HDC_OBJECT;
            Rectangle(HDC_OBJECT, 10, 10, 200, 200);
            ReleaseDC(hWnd, HDC_OBJECT);
            break;
        case WM_DESTROY:
            std::cout << "<< WM_DESTROY >>" << '\n';
            std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
            std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
            break;
    };
    return 0;
};

VOID createAWindowPalette(std::unique_ptr<_SETCREATEDEFAULT> &set, LPCTSTR &lpszClassName, BOOL ImmediateExposure = 0) {
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
        std::cout << "(" << &set->hwnd << ") " << "--OK" << '\n';
    };


    if (ImmediateExposure == 1) {
        ShowWindow(set->hwnd, 1);
        UpdateWindow(set->hwnd);
    };
};


VOID createWindowButton(std::unique_ptr<_SETCREATEDEFAULT> &set, HWND &Palette, HMENU TriggerID, BOOL ImmediateExposure = 0) {
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


INT CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, INT nCmdShow) {
    AllocConsole();

    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);

    std::cout << "window-startup-hInstance:" << hInstance << "(" << &hInstance << ")" << '\n';

    const TCHAR szWindowClass[] = _T("DesktopApp");
    const TCHAR szTitle[] = _T("Windows Desktop Guided Tour Application");


    WNDCLASSEX TESTWNDCLASS;
    TESTWNDCLASS.cbSize = sizeof(WNDCLASSEX);
    TESTWNDCLASS.style = CS_HREDRAW | CS_VREDRAW;
    TESTWNDCLASS.lpfnWndProc = WndProc;
    TESTWNDCLASS.cbClsExtra = 0;
    TESTWNDCLASS.cbWndExtra = 0;
    TESTWNDCLASS.hInstance = hInstance;
    TESTWNDCLASS.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    TESTWNDCLASS.hCursor = LoadCursor(NULL, IDC_ARROW);
    TESTWNDCLASS.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
    TESTWNDCLASS.lpszMenuName = NULL;
    TESTWNDCLASS.lpszClassName = szWindowClass;
    TESTWNDCLASS.hIconSm = LoadIcon(TESTWNDCLASS.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&TESTWNDCLASS)) {
        MessageBox(NULL,
                   _T("Call to RegisterClassEx failed!"),
                   _T("Windows Desktop Guided Tour"),
                   0);
        return 1;
    } else {
        std::cout << "Window register class successful!" << '\n';
    };

    HWND helloPallet;
    LPCTSTR testClassName = _T("DesktopApp");
    std::unique_ptr<_SETCREATEDEFAULT> p_0 = std::make_unique<_SETCREATEDEFAULT>(_SETCREATEPOSITION{0, 0, 500, 500}, hInstance);
    std::unique_ptr<_SETCREATEDEFAULT> b_0 = std::make_unique<_SETCREATEDEFAULT>(_SETCREATEPOSITION{10, 10, 100, 50}, hInstance);
    createAWindowPalette(p_0, testClassName ,1);
    createWindowButton(b_0, p_0->hwnd, (HMENU) __STANDARD_BUTTON_CLICK_EVENT_HANDLE_NUMBER__ ,1);


    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int) msg.wParam;
};





