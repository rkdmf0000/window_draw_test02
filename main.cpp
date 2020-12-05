#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#pragma execution_character_set( "utf-8" )


#include <sb_sandbox.h>


void testBootFn(HWND hWnd, SB_SANDBOX::objectLoader *loader)
{


    HWND* mainHwnd = new HWND(hWnd);
    PAINTSTRUCT* testPS = new PAINTSTRUCT;
    HDC* testHdc = new HDC;
    *testHdc = GetDC(hWnd);
    ReleaseDC(hWnd, *testHdc);


    Gdiplus::Graphics* test_graphics = new Gdiplus::Graphics(*testHdc);
    Gdiplus::Image* test_image = new Gdiplus::Image(L"./image.bmp");

    loader->preloadHwnd(mainHwnd, "main_handle");
    loader->preloadPaintStruct(testPS, "test");
    loader->preloadHdc(testHdc, "test_hdc");

    loader->preloadGdiplusImage(test_image, "test_image");
    loader->preloadGdiplusGraphics(test_graphics, "test_graphics");

    loader->printCollectorLength();
    loader->printCollectorPtr();


    loader->load();
};


//bool standardization(std::vector<double> *v)
//{
//    double max_value = *(std::max_element(v->begin(), v->end()));
//    double min_value = *(std::min_element(v->begin(), v->end()));
//    double range = 1.0/(max_value - min_value);
//    std::vector<double>::iterator pos = v->begin();
//    std::vector<double>::iterator end = v->end();
//
//    for(; pos != end; pos++){
//
//        *pos = (*pos - min_value)*range;
//
//    }
//    return true;
//}





INT CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, INT nCmdShow) {
    AllocConsole();
    SetConsoleOutputCP(65001);
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);

    SB_SANDBOX::client* test_client = new SB_SANDBOX::client(hInstance);

    test_client->initGdiplusStartup();
    test_client->initApp();
    test_client->initInstance();
    test_client->setClientBootFn(testBootFn);
    test_client->setActionPerFrame(60);
    test_client->run();

    delete test_client;
    return 0;
};






