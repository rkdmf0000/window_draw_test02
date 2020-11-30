//
// Created by my_fl on 2020-10-13.
//
#include "sb_sandbox.h"

//------------------------------------------------------------------------------------------------
//class : winApp
//------------------------------------------------------------------------------------------------

FLOAT SB_SANDBOX::UIFeedback::mouseDefaultTick = 0.041f;

BOOL SB_SANDBOX::UIFeedback::mouseMOVE = FALSE;
UINT SB_SANDBOX::UIFeedback::mouseX = 0;
UINT SB_SANDBOX::UIFeedback::mouseVX = 0;
UINT SB_SANDBOX::UIFeedback::mouseVXF = 0;

UINT SB_SANDBOX::UIFeedback::mouseY = 0;
UINT SB_SANDBOX::UIFeedback::mouseVY = 0;
UINT SB_SANDBOX::UIFeedback::mouseVYF = 0;

UINT SB_SANDBOX::UIFeedback::mouseVTICK = 100;

UINT SB_SANDBOX::UIFeedback::mouseUP = 0;
UINT SB_SANDBOX::UIFeedback::mouseDown = 0;
UINT SB_SANDBOX::UIFeedback::mouseLUP = 0;
UINT SB_SANDBOX::UIFeedback::mouseLDown = 0;
UINT SB_SANDBOX::UIFeedback::mouseRUP = 0;
UINT SB_SANDBOX::UIFeedback::mouseRDown = 0;
UINT SB_SANDBOX::UIFeedback::mouseIsClicked = 0;

UINT SB_SANDBOX::client::LIMITOVERFLOWFLAGINT = 0;

LRESULT CALLBACK SB_SANDBOX::client::publicWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return SB_SANDBOX::client::privateWndProc(hWnd, uMsg, wParam, lParam);
}

VOID SB_SANDBOX::client::FOR_PROCEDURE__WM_PAINT(const HWND hWnd)
{
    if (!this->isBootedClient) return; //early return

    PAINTSTRUCT& ps = *this->loader->getResourcePaintStruct("test");
    HDC hdc = *this->loader->getResourceHdc("test_hdc");

    FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+3));

    std::cout << ps.hdc << " / " << hdc << '\n';

    EndPaint(hWnd, &ps);
};

LRESULT CALLBACK SB_SANDBOX::client::privateWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    SB_SANDBOX::client* client = (SB_SANDBOX::client*) GetWindowLongPtr(hWnd, GWLP_USERDATA);

    switch (uMsg)
    {
        case WM_INITDIALOG:
            SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)lParam);
        break;
        //--------------------
        case WM_MOUSEMOVE:
            SB_SANDBOX::client::mouseMOVE   = TRUE;
            SB_SANDBOX::client::mouseX      = LOWORD(lParam);
            SB_SANDBOX::client::mouseY      = HIWORD(lParam);
            break;
        case WM_LBUTTONUP:
            SB_SANDBOX::client::mouseUP = 1;
            SB_SANDBOX::client::mouseDown = 0;
            break;
        case WM_LBUTTONDOWN:
            SB_SANDBOX::client::mouseUP = 0;
            SB_SANDBOX::client::mouseDown = 1;
            break;
        case WM_LBUTTONDBLCLK:
            break;
        //--------------------
        case WM_RBUTTONUP:
            break;
        case WM_RBUTTONDOWN:
            break;
        case WM_RBUTTONDBLCLK:
            break;
        //--------------------
        case WM_MBUTTONUP:
            break;
        case WM_MBUTTONDOWN:
            break;
        //--------------------
        case WM_MOUSEWHEEL:
            break;
        //--------------------

        case WM_CREATE:
            std::cout << "it was good bitch" << '\n';
            break;
        case WM_NCCREATE:
        {
            auto ist_p = (SB_SANDBOX::client*)((CREATESTRUCT*)lParam)->lpCreateParams;
            SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)ist_p);
            return TRUE;
        }
        case WM_PAINT:
            client->FOR_PROCEDURE__WM_PAINT(hWnd);
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
    this->wndHandle = CreateWindow(
            this->get_lpClassName(), this->get_lpWndName()
            , WS_OVERLAPPED
            , CW_USEDEFAULT, CW_USEDEFAULT
            , 500, 500
            , nullptr, 0
            , this->get_processHandle()
            , this
            );
    ShowWindow(this->get_wndHandle(),1);
    UpdateWindow(this->get_wndHandle());

    std::cout << __FUNCTION__ << ":" << this->wndHandle << '\n';

    //this->clientDC = GetDC(this->wndHandle);
};

INT CALLBACK SB_SANDBOX::client::run()
{
    if (this->clientBootFn == NULL)
    {
        std::cout << "CLIENT BOOT NOT DEFINED!" << '\n';
        return 0;
    };
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        ++SB_SANDBOX::client::LIMITOVERFLOWFLAGINT;
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        this->afterMessageDispatch(&msg);
    }
    return (int) msg.wParam;
}


VOID SB_SANDBOX::client::afterMessageDispatch(MSG* msg)
{
    //get frame
    UINT currentTime = GetTickCount();
    this->frameBegin = (this->frameBegin == 0 ? GetTickCount() : this->frameBegin);
    UINT runtime = (currentTime - this->frameBegin);
    ++this->frameCnt;

    this->nextFrameMove = FALSE;

    //mouse vector
    this->mouseVX = this->mouseVXF - 250;
    this->mouseVY = this->mouseVYF - 250;


    if (this->isBootedClient == FALSE)
    {
        this->getClientBootFn()(this->get_wndHandle(), this->loader); //immediately execution / 그냥 혹시 될까 싶어서 붙였는데 진짜 되넹ㅋㅋ
        this->isBootedClient = TRUE;
    }




    //1 sec per tick times
    if (runtime % this->mouseVTICK == 0)
    {

        this->mouseVXF = this->mouseX;
        this->mouseVYF = this->mouseY;
    };


    this->fluidTickProcess();
    Sleep(this->fluidTickFrame*0.001);


    //frame condition
    if (runtime > 1000)
    {

        printf("NUM: %d / FPS: (%f / %d) / MOUSE(%d) POS: x: %d(v %d), y: %d(v %d) / Tick %d / FrameDelay %f \n"
                ,this->LIMITOVERFLOWFLAGINT
                ,!this->frame ? 0 : this->frame
                ,!this->maximumFps ? 0 : this->maximumFps
                ,this->mouseMOVE ? 1 : 0
                ,this->mouseX
                ,this->mouseVX
                ,this->mouseY
                ,this->mouseVY
                ,this->fluidTickFrame
                , this->frameDelay
        );

        this->frame = (this->frameCnt*1000.0)/(currentTime - this->frameEnd);
        this->frameEnd = currentTime;
        this->frameBegin = 0;
        this->frameCnt = 0;
        this->mouseMOVE = FALSE;
    }

    //top pined set
    //::SetWindowPos(this->get_wndHandle(), HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
    //::ShowWindow(this->get_wndHandle(), SW_NORMAL);

    RedrawWindow(this->get_wndHandle(),NULL,NULL,RDW_INVALIDATE | RDW_ERASE);

    //RedrawWindow(this->get_wndHandle(), NULL, NULL, 0);
    //InvalidateRect(this->get_wndHandle(),NULL, TRUE);
    //UpdateWindow(this->get_wndHandle());
};



//------------------------------------------------------------------------------------------------
//class : client
//------------------------------------------------------------------------------------------------
SB_SANDBOX::client::client(HINSTANCE hin) {
    LPCTSTR szWindowClass   = _T("DesktopApp");
    LPCTSTR szTitle         = _T("Window game interface test");

    this->lpClassName = szWindowClass;
    this->lpWndName = szTitle;
    this->processHandle = hin;

    this->frameBegin = 0;
    this->frameEnd = 0;
    this->frameCnt = 0;
    this->frame = 0;
    this->nextFrameMove = FALSE;
    this->maximumFps = 15;
    this->fluidTickFrame = 24000; // 0.024sec per a frame

    this->loader = new objectLoader();
};

SB_SANDBOX::client::~client() {
    delete this->loader;
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
}

VOID SB_SANDBOX::client::setClientBootFn(std::function<void(HWND hwnd, SB_SANDBOX::objectLoader* loader)> fn) {
    this->clientBootFn = fn;
}

//it is must be returned callable!
std::function<void(HWND hwnd, SB_SANDBOX::objectLoader* loader)> SB_SANDBOX::client::getClientBootFn() {
    return this->clientBootFn;
}

VOID SB_SANDBOX::client::setActionPerFrame(INT fps) {
    this->maximumFps = fps;
}

VOID SB_SANDBOX::client::fluidTickProcess() {
    bool updownFlag(0);
    unsigned short mulAvg(1);
    float magnificationRatio;
    const unsigned int cutCastingedFps = static_cast<unsigned int>(this->frame);
    const unsigned int cutCastingMaxFps = static_cast<unsigned int>(this->maximumFps);

    if (cutCastingMaxFps >= 0 && cutCastingedFps >= 0)
        magnificationRatio = 100 - static_cast<float>(cutCastingMaxFps) / static_cast<float>(cutCastingedFps) * 100;

    //현재프레임보다 목표 프레임이 더 높은 경우
    if (cutCastingedFps >= this->maximumFps)
    {
        this->frameDelay = mulAvg = magnificationRatio >= 0 ? SB_SANDBOX::MATHTOOL::Normalization(0,100, magnificationRatio,1,30) : 1;
        this->fluidTickFrame += mulAvg;
    }
    else if (cutCastingedFps < this->maximumFps)
    {
        updownFlag = true;
        magnificationRatio = abs(magnificationRatio);
        this->frameDelay = mulAvg = magnificationRatio >= 0 ? SB_SANDBOX::MATHTOOL::Normalization(0,100, magnificationRatio,1,30) : 1;

        if (this->fluidTickFrame - mulAvg >= 0) this->fluidTickFrame -= (mulAvg);
    }
    //std::cout << (updownFlag ? "UP - " : "DO - ") << magnificationRatio << "/" << mulAvg << " == " << this->frame << '\n';

};

//------------------------------------------------------------------------------------------------
//class : DCTOOLSET
//------------------------------------------------------------------------------------------------
VOID SB_SANDBOX::DCTOOLSET::drawTextAtAFrame(HWND handle, HDC hdc, RECT rect, LPCTSTR text) {
    SetTextColor(hdc,RGB(255,0,0));
    SetBkColor(hdc,RGB(0,255,0));
    DrawText(hdc, text,-1,&rect,DT_LEFT);
};



std::string SB_SANDBOX::STRINGTOOL::convert(LPCTSTR str) {
    return std::string(str);
}

const float SB_SANDBOX::MATHTOOL::Normalization(float v_min, float v_max, float value, float n_min, float n_max)
{
    return (n_max - n_min) * (value - v_min) / (v_max - v_min) + n_min;
};
