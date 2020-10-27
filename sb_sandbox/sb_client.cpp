//
// Created by my_fl on 2020-10-13.
//
#include "sb_sandbox.h"
//------------------------------------------------------------------------------------------------
//class : winApp
//------------------------------------------------------------------------------------------------


FLOAT SB_SANDBOX::UIFeedback::mouseDefaultTick = 0.041f;
UINT SB_SANDBOX::UIFeedback::mouseX = 0;
UINT SB_SANDBOX::UIFeedback::mouseVX = 0;
UINT SB_SANDBOX::UIFeedback::mouseY = 0;
UINT SB_SANDBOX::UIFeedback::mouseVY = 0;
UINT SB_SANDBOX::UIFeedback::mouseUP = 0;
UINT SB_SANDBOX::UIFeedback::mouseDown = 0;
UINT SB_SANDBOX::UIFeedback::mouseLUP = 0;
UINT SB_SANDBOX::UIFeedback::mouseLDown = 0;
UINT SB_SANDBOX::UIFeedback::mouseRUP = 0;
UINT SB_SANDBOX::UIFeedback::mouseRDown = 0;
UINT SB_SANDBOX::UIFeedback::mouseIsClicked = 0;



INT SB_SANDBOX::client::LIMITOVERFLOWFLAGINT = 0;


LRESULT CALLBACK SB_SANDBOX::client::publicWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return SB_SANDBOX::client::privateWndProc(hWnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK SB_SANDBOX::client::privateWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_MOUSEMOVE:
            SB_SANDBOX::client::mouseX = HIWORD(lParam);
            SB_SANDBOX::client::mouseY = LOWORD(lParam);

        case WM_LBUTTONUP:
            SB_SANDBOX::client::mouseUP = 1;
            SB_SANDBOX::client::mouseDown = 1;
            break;
        case WM_NCCREATE:
            std::cout << "is good bitch" << '\n';
            break;
    };
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
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

INT CALLBACK SB_SANDBOX::client::run()
{
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        ++LIMITOVERFLOWFLAGINT;
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        this->afterMessageDispatch();
    }
    return (int) msg.wParam;
}


VOID SB_SANDBOX::client::afterMessageDispatch()
{
    UINT currentTime = GetTickCount();
    this->frameBegin = (this->frameBegin == 0 ? GetTickCount() : this->frameBegin);
    UINT runtime = (currentTime - this->frameBegin);
    ++this->frameCnt;


    std::cout << "NUM:" << LIMITOVERFLOWFLAGINT << " / FPS: " << this->frame << " MOUSE POS:" << mouseX << "/" << mouseY << '\n';
    //HDC hoho = GetDC(this->get_wndHandle());
    //RECT rect = { 20, 20, 200, 200 };
    //LPCTSTR frametext = frametextcp;
    //SB_SANDBOX::DCTOOLSET::drawTextAtAFrame(this->get_wndHandle(), hoho, rect, frametext);




    if (runtime > 1000)
    {
        this->frame = (this->frameCnt*1000.0)/(currentTime - this->frameEnd);
        this->frameEnd = currentTime;
        this->frameBegin = 0;
        this->frameCnt = 0;
    }

    ::SetWindowPos(this->get_wndHandle(), HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
    ::ShowWindow(this->get_wndHandle(), SW_NORMAL);
    InvalidateRect(this->get_wndHandle(),NULL,TRUE);
    //UpdateWindow(this->get_wndHandle());
};



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

    this->frameBegin = 0;
    this->frameEnd = 0;
    this->frameCnt = 0;
    this->frame = 0;

};

SB_SANDBOX::client::~client() {

};

LPCTSTR &SB_SANDBOX::client::get_lpClassName() {
    return this->lpClassName;
};

LPCTSTR &SB_SANDBOX::client::get_lpWndName() {
    return this->lpWndName;
};

HWND &SB_SANDBOX::client::get_wndHandle() {
    return this->wndHandle;
};

HINSTANCE &SB_SANDBOX::client::get_processHandle() {
    return this->processHandle;
};

//------------------------------------------------------------------------------------------------
//class : DCTOOLSET
//------------------------------------------------------------------------------------------------
VOID SB_SANDBOX::DCTOOLSET::drawTextAtAFrame(HWND handle, HDC hdc, RECT rect, LPCTSTR text) {
    SetTextColor(hdc,RGB(255,0,0));
    SetBkColor(hdc,RGB(0,255,0));
    DrawText(hdc, text,-1,&rect,DT_LEFT);
};
