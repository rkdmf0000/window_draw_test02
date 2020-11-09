#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#pragma execution_character_set( "utf-8" )


#include <sb_sandbox.h>


//#define __STANDARD_BUTTON_CLICK_EVENT_HANDLE_NUMBER__ 0x00f0
//#define __STANDARD_BUTTON_CLICK_UP_EVENT_HANDLE_NUMBER__ 0x00f1
//#define __STANDARD_BUTTON_CLICK_DOWN_EVENT_HANDLE_NUMBER__ 0x00f2

void testBootFn(SB_SANDBOX::objectLoader *loader)
{
    int a = 5, b = 10;
    loader->TESTFORACTION_PRELOAD_INT(a);
    loader->TESTFORACTION_PRELOAD_INT(a);
    loader->TESTFORACTION_PRELOAD_INT(b);

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
    test_client->run();



    delete test_client;

    return 0;
};






