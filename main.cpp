#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#pragma execution_character_set( "utf-8" )
#include <sb_sandbox.h>
//#include <afxres.h>
void testBootFn(HWND hWnd, SB_SANDBOX::objectLoader *loader)
{

    std::cout << "윈도우 타이틀이 안나옴.. ㄹㅇ 극혐" << '\n';


    HDC* x_hdc = new HDC(GetDC(hWnd));
    HDC* x_c_hdc = new HDC(CreateCompatibleDC(*x_hdc));
    HBITMAP* x_hbitmap = new HBITMAP(CreateCompatibleBitmap(*x_hdc, 500, 500));
    SelectObject(*x_c_hdc, (HBITMAP)*x_hbitmap);
    Gdiplus::Graphics* x_gp = new Gdiplus::Graphics(*x_hdc);

    Gdiplus::Image* x_img = new Gdiplus::Image(L".\\image\\test1.bmp");
    Gdiplus::Image* x_img2 = new Gdiplus::Image(L".\\image\\blood-sample.png");

    loader->preloadHdc(x_c_hdc, "t_mem_hdc");
    loader->preloadGdiplusGraphics(x_gp, "t_gp");
    loader->preloadGdiplusImage(x_img, "t_img");
    loader->preloadGdiplusImage(x_img2, "t_img2");

    loader->printCollectorLength();
    loader->printCollectorPtr();
    loader->load();
};
INT CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, INT nCmdShow) {
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
    SetConsoleOutputCP(65001);

    std::cout << "-- - - - - --" << '\n';
    std::cout << (HBITMAP) LoadImage(hInstance, TEXT("image\\test1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION) << '\n';
    DWORD lastError = GetLastError();


    std::cout << lastError << '\n';
    std::cout << "-- - - - - --" << '\n';
    SB_SANDBOX::client* test_client = new SB_SANDBOX::client(hInstance);
    test_client->initGdiplusStartup();
    test_client->initApp();
    test_client->initInstance();
    test_client->setClientBootFn(testBootFn);
    test_client->setActionPerFrame(15);
    test_client->run();
    test_client->loader->cutAll();
    delete test_client;
    return 0;
};
