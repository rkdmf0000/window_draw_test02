#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#pragma execution_character_set( "utf-8" )


#include <sb_sandbox.h>


void testBootFn(SB_SANDBOX::objectLoader *loader)
{
    int a = 5, b = 10;
    char ca = 'a';

    //int* basket_int;


    std::string sa("wowowow");
    loader->TESTFORACTION_PRELOAD_INT(a);
    loader->TESTFORACTION_PRELOAD_INT(b);
    loader->TESTFORACTION_PRELOAD_CHAR(ca);
    loader->TESTFORACTION_PRELOAD_STRING(sa);

    loader->filterCollection(SB_SANDBOX::TYPE_RESOURCE_CONTROL::INT);

    //loader->printCollectorLength();
    //loader->printCollectorPtr();

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






