#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#pragma execution_character_set( "utf-8" )


#include <sb_sandbox.h>


void testBootFn(HWND hwnd, SB_SANDBOX::objectLoader *loader)
{

    PAINTSTRUCT testPS;
    HDC testHdc = BeginPaint(hwnd, &testPS);

    loader->preloadPaintStruct(testPS, "test");
    loader->preloadHdc(testHdc, "test_hdc");
    loader->printCollectorLength();
    loader->printCollectorPtr();


    loader->load();
};


bool standardization(std::vector<double> *v)
{
    double max_value = *(std::max_element(v->begin(), v->end()));
    double min_value = *(std::min_element(v->begin(), v->end()));
    double range = 1.0/(max_value - min_value);
    std::vector<double>::iterator pos = v->begin();
    std::vector<double>::iterator end = v->end();

    for(; pos != end; pos++){

        *pos = (*pos - min_value)*range;

    }
    return true;
}





INT CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, INT nCmdShow) {
    AllocConsole();
    SetConsoleOutputCP(65001);

    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);

    std::cout << "VERSION : 003 " << '\n' << '\n';
    std::cout << "window-startup-hInstance:" << hInstance << "(" << &hInstance << ")" << '\n';

    SB_SANDBOX::client* test_client = new SB_SANDBOX::client(hInstance);


//    float axxx;
//    axxx = SB_SANDBOX::MATHTOOL::Normalization(0,6550, 1234, -10, 10);
//    printf("----------------------- ANSWER : %f \n" , axxx);


    test_client->initApp();
    test_client->initInstance();
    test_client->setClientBootFn(testBootFn);
    test_client->setActionPerFrame(60);
    test_client->run();



    delete test_client;

    return 0;
};






