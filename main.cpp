#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#pragma execution_character_set( "utf-8" )


#include <sb_sandbox.h>


void testBootFn(SB_SANDBOX::objectLoader *loader)
{

    PAINTSTRUCT testPS;
    loader->preloadPaintStruct(testPS, "test");
    loader->preloadPaintStruct(testPS, "test");

    //loader->filterCollection(SB_SANDBOX::TYPE_RESOURCE_CONTROL::INT);
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






