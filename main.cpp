#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#pragma execution_character_set( "utf-8" )


#include <sb_sandbox.h>


void testBootFn(HWND hwnd, SB_SANDBOX::objectLoader *loader)
{

    PAINTSTRUCT testPS;
    HDC testHdc;

    loader->preloadPaintStruct(testPS, "test");
    loader->preloadHdc(testHdc, "test_hdc");
    loader->printCollectorLength();
    loader->printCollectorPtr();


    loader->load();
};


INT CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, INT nCmdShow) {
    AllocConsole();
    SetConsoleOutputCP(65001);

    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);

    std::cout << "VERSION : 003 " << '\n' << '\n';
    std::cout << "window-startup-hInstance:" << hInstance << "(" << &hInstance << ")" << '\n';

    SB_SANDBOX::client* test_client = new SB_SANDBOX::client(hInstance);



    test_client->initApp();
    test_client->initInstance();
    test_client->setClientBootFn(testBootFn);

    test_client->setActionPerFrame(60);

    test_client->run();



    delete test_client;

    return 0;
};






