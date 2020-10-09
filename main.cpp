#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")



#include <sb_sandbox.h>

#define __STANDARD_BUTTON_CLICK_EVENT_HANDLE_NUMBER__ 0x00f0
#define __STANDARD_BUTTON_CLICK_UP_EVENT_HANDLE_NUMBER__ 0x00f1
#define __STANDARD_BUTTON_CLICK_DOWN_EVENT_HANDLE_NUMBER__ 0x00f2





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



//LRESULT CALLBACK WndProc(_In_ HWND hWnd, _In_ UINT message, _In_ WPARAM wParam, _In_ LPARAM lParam) {
//
//};





INT CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, INT nCmdShow) {
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);

    std::cout << "VERSION : 001 " << '\n' << '\n';
    std::cout << "window-startup-hInstance:" << hInstance << "(" << &hInstance << ")" << '\n';

    const TCHAR szWindowClass[] = _T("DesktopApp");
    const TCHAR szTitle[] = _T("Windows Desktop Guided Tour Application");

    WNDCLASSEX TESTWNDCLASS;
    TESTWNDCLASS.cbSize = sizeof(WNDCLASSEX);
    TESTWNDCLASS.style = CS_HREDRAW | CS_VREDRAW;
    TESTWNDCLASS.lpfnWndProc = SB_SANDBOX::IMP_FUNCTION::WndProc;
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






    LPCTSTR testClassName = _T("DesktopApp");

    std::unique_ptr<_SETCREATEDEFAULT> p_0 = std::make_unique<_SETCREATEDEFAULT>(_SETCREATEPOSITION{0, 0, 500, 500}, hInstance);
    std::unique_ptr<_SETCREATEDEFAULT> b_0 = std::make_unique<_SETCREATEDEFAULT>(_SETCREATEPOSITION{10, 10, 100, 50}, hInstance);

    std::unique_ptr<_SETCREATEVIRTUAL> v_0 = std::make_unique<_SETCREATEVIRTUAL>(_SETCREATEPOSITION{100,100,100,50});

    SB_SANDBOX::FUNCTION::createAWindowPalette(p_0, testClassName ,1);
    SB_SANDBOX::FUNCTION::createWindowButton(b_0, p_0->hwnd, (HMENU) __STANDARD_BUTTON_CLICK_EVENT_HANDLE_NUMBER__ ,1);


    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int) msg.wParam;
};





