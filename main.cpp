#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")



#include <sb_sandbox.h>


//#define __STANDARD_BUTTON_CLICK_EVENT_HANDLE_NUMBER__ 0x00f0
//#define __STANDARD_BUTTON_CLICK_UP_EVENT_HANDLE_NUMBER__ 0x00f1
//#define __STANDARD_BUTTON_CLICK_DOWN_EVENT_HANDLE_NUMBER__ 0x00f2


INT CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, INT nCmdShow) {
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);

    std::cout << "VERSION : 002 " << '\n' << '\n';
    std::cout << "window-startup-hInstance:" << hInstance << "(" << &hInstance << ")" << '\n';


    SB_SANDBOX::client* test_client = new SB_SANDBOX::client(hInstance);

    test_client->initApp();
    test_client->initInstance();
    test_client->run();

    return 0;
};





