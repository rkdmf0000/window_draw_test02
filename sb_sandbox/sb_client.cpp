//
// Created by my_fl on 2020-10-13.
//
#include "sb_sandbox.h"
//------------------------------------------------------------------------------------------------
//class : winApp
//------------------------------------------------------------------------------------------------



LRESULT CALLBACK SB_SANDBOX::client::privateWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
        case WM_NCCREATE:{
            //SB_SANDBOX::client* convd_self = static_cast<SB_SANDBOX::client*>(self);
            std::cout << "is good bitch" << '\n';
        };
            break;
    };
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK SB_SANDBOX::client::publicWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    std::cout << "long:" << GetWindowLongPtr(hWnd, GWL_USERDATA) << '\n';
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
    //SB_SANDBOX::client* me = reinterpret_cast<SB_SANDBOX::client*>(GetWindowLongPtr(hWnd, GWL_USERDATA));
    //return me->privateWndProc(hWnd, uMsg, wParam, lParam);
}

VOID SB_SANDBOX::client::initApp() {

    WNDCLASSEX TESTWNDCLASS;
    TESTWNDCLASS.cbSize = sizeof(WNDCLASSEX);
    TESTWNDCLASS.style = CS_HREDRAW | CS_VREDRAW;
    TESTWNDCLASS.lpfnWndProc = this->publicWndProc;
    TESTWNDCLASS.cbClsExtra = 0;
    TESTWNDCLASS.cbWndExtra = 0;
    TESTWNDCLASS.hInstance = this->get_processHandle();
    TESTWNDCLASS.hIcon = LoadIcon(this->get_processHandle(), IDI_APPLICATION);
    TESTWNDCLASS.hCursor = LoadCursor(nullptr, IDC_ARROW);
    TESTWNDCLASS.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
    TESTWNDCLASS.lpszMenuName = nullptr;
    TESTWNDCLASS.lpszClassName = this->get_lpClassName();
    TESTWNDCLASS.hIconSm = LoadIcon(TESTWNDCLASS.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&TESTWNDCLASS)) {
        MessageBox(nullptr,
                   _T("Call to RegisterClassEx failed!"),
                   _T("Windows Desktop"),
                   0);
    } else {
        std::cout << "Window register class successful!" << '\n';
    };
};

VOID SB_SANDBOX::client::initInstance()
{
    this->wndHandle = CreateWindow(this->get_lpClassName(), this->get_lpWndName(), WS_OVERLAPPED, CW_USEDEFAULT, CW_USEDEFAULT, 500, 500, nullptr, 0, this->get_processHandle(), 0);
    ShowWindow(this->get_wndHandle(),1);
    UpdateWindow(this->get_wndHandle());
};

INT CALLBACK SB_SANDBOX::client::run() {
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int) msg.wParam;
}





//------------------------------------------------------------------------------------------------
//class : client
//------------------------------------------------------------------------------------------------
SB_SANDBOX::client::client(HINSTANCE hin) {
    const TCHAR szWindowClass[] = _T("DesktopApp");
    const TCHAR szTitle[] = _T("Windows Desktop Guided Tour Application");
    LPCTSTR testClassName = szWindowClass;

    this->lpClassName = szWindowClass;
    this->lpWndName = szTitle;
    this->processHandle = hin;
};

SB_SANDBOX::client::~client() {

}

LPCTSTR &SB_SANDBOX::client::get_lpClassName() {
    return this->lpClassName;
}

LPCTSTR &SB_SANDBOX::client::get_lpWndName() {
    return this->lpWndName;
}

HWND &SB_SANDBOX::client::get_wndHandle() {
    return this->wndHandle;
}

HINSTANCE &SB_SANDBOX::client::get_processHandle() {
    return this->processHandle;
};
