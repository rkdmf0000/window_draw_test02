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

INT SB_SANDBOX::client::LIMITOVERFLOWFLAGINT = 0;


LRESULT CALLBACK SB_SANDBOX::client::publicWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return SB_SANDBOX::client::privateWndProc(hWnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK SB_SANDBOX::client::privateWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
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

    this->clientDC = GetDC(this->wndHandle);
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
        ++LIMITOVERFLOWFLAGINT;
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        this->afterMessageDispatch();
    }
    return (int) msg.wParam;
}


VOID SB_SANDBOX::client::afterMessageDispatch()
{
    //get frame
    UINT currentTime = GetTickCount();
    this->frameBegin = (this->frameBegin == 0 ? GetTickCount() : this->frameBegin);
    UINT runtime = (currentTime - this->frameBegin);
    ++this->frameCnt;

    //mouse vector
    this->mouseVX = this->mouseVXF - 250;
    this->mouseVY = this->mouseVYF - 250;


    if (this->isBootedClient == FALSE)
    {
        this->getClientBootFn()(this->loader); //immediately execution / 그냥 혹시 될까 싶어서 붙였는데 진짜 되넹ㅋㅋ
        this->isBootedClient = TRUE;
    }

    //1 sec per tick times
    if (runtime % this->mouseVTICK == 0)
    {

        this->mouseVXF = this->mouseX;
        this->mouseVYF = this->mouseY;
    };




    //frame condition
    if (runtime > 1000)
    {
        printf("NUM: %d / FPS: %f / MOUSE(%d) POS: x: %d(v %d), y: %d(v %d)----\n"
            ,this->LIMITOVERFLOWFLAGINT
            ,this->frame
            ,(this->mouseMOVE ? 1 : 0)
            ,this->mouseX
            ,this->mouseVX
            ,this->mouseY
            ,this->mouseVY
        );



        this->frame = (this->frameCnt*1000.0)/(currentTime - this->frameEnd);
        this->frameEnd = currentTime;
        this->frameBegin = 0;
        this->frameCnt = 0;

        this->mouseMOVE = FALSE;
    }

    //top pined set
    ::SetWindowPos(this->get_wndHandle(), HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
    ::ShowWindow(this->get_wndHandle(), SW_NORMAL);

    //force update wm_paint
    InvalidateRect(this->get_wndHandle(),NULL,TRUE);
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

VOID SB_SANDBOX::client::setClientBootFn(std::function<void(SB_SANDBOX::objectLoader* loader)> fn) {
    this->clientBootFn = fn;
}

//it is must be returned callable!
std::function<void(SB_SANDBOX::objectLoader* loader)> SB_SANDBOX::client::getClientBootFn() {
    return this->clientBootFn;
};

//------------------------------------------------------------------------------------------------
//class : DCTOOLSET
//------------------------------------------------------------------------------------------------
VOID SB_SANDBOX::DCTOOLSET::drawTextAtAFrame(HWND handle, HDC hdc, RECT rect, LPCTSTR text) {
    SetTextColor(hdc,RGB(255,0,0));
    SetBkColor(hdc,RGB(0,255,0));
    DrawText(hdc, text,-1,&rect,DT_LEFT);
};

//------------------------------------------------------------------------------------------------
//class : objectLoader
//------------------------------------------------------------------------------------------------

SB_SANDBOX::objectLoader::objectLoader()
{
    std::cout << "- - Loader online" << '\n';
    this->collectorLength = 0;
    this->collector = new INT_PTR[0];
};
SB_SANDBOX::objectLoader::~objectLoader()
{
    delete this->collector;
    std::cout << "- - Loader offline" << '\n';
};

VOID SB_SANDBOX::objectLoader::load()
{
    std::cout << "- - Loader running on load" << '\n';
};

//TODO : 이거 아직 미완성임 이거 해야함 ㅋㅋ
template<typename _t>
VOID SB_SANDBOX::objectLoader::resourceControl(_t *data)
{

    unsigned int length = this->collectorLength;
    INT_PTR *dummy = new INT_PTR[length + 1];
    if (length != 0)
    {
        for(int i(0); i < length; ++i)
        {
            std::cout << __FUNCTION__ << " backup :" << i << "/" << reinterpret_cast<INT_PTR>(this->collector+i) << '\n';
            dummy[i] = reinterpret_cast<INT_PTR>(this->collector+i);
        };
    }

    delete this->collector;

    this->collector = dummy;
    this->collector[length+1] = reinterpret_cast<INT_PTR>(data);
    ++this->collectorLength;


}

VOID SB_SANDBOX::objectLoader::TESTFORACTION_PRELOAD_INT(int testInteger)
{
    this->resourceControl<int>(&testInteger);
}

VOID SB_SANDBOX::objectLoader::printCollectorPtr() {
    unsigned int length = this->collectorLength;
    for (int i(0); i < length; ++i)
    {
        std::cout << "address : " << this->collector[i] << '\n';
    };
};
VOID SB_SANDBOX::objectLoader::printCollectorLength()
{
    std::cout << __FUNCTION__ << ":" << this->collectorLength << '\n';
}

