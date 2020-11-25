//
// Created by my_fl on 2020-10-09.
//


#ifndef WINDOW_DRAW_TEST02_SB_SANDBOX_H
#define WINDOW_DRAW_TEST02_SB_SANDBOX_H
#include "sb_define.h"


namespace SB_SANDBOX
{
    //------------------
    //winApp
    //------------------
    class winApp
    {
    protected:
        LPCTSTR lpClassName;
        LPCTSTR lpWndName;
        HWND wndHandle;
        HINSTANCE processHandle;
    private:
    public:
    };

    //------------------
    //objectLoader
    //------------------
    class objectLoader
    {

    protected:
    private:
        RESOURCE_COLLECTOR collector;
        RESOURCE_TYPE_BASKET collectorType;
        RESOURCE_NAME_BASKET collectorName;
        WORD collectorLength;

        //로드할 자원을 collector에 쌓아주는 메서드
        template<typename _t>
        VOID resourceControl(_t *data);

        //This method grip the start point of pointer by type and name filter
        VOID * resourceGripper(SB_SANDBOX::TYPE_RESOURCE_CONTROL type, LPCTSTR name);

    public:



        PAINTSTRUCT* getResourcePaintStruct(LPCTSTR name);
        HDC* getResourceHdc(LPCTSTR name);

        //static UINT itStackedHowMuch; //it calculation support by used resource detach process.

        objectLoader();
        ~objectLoader();


        VOID filterCollection(SB_SANDBOX::TYPE_RESOURCE_CONTROL type);

        INT* filterIntCollection();
        CHAR* filterCharCollection();
        HDC* filterHdcCollection();
        HPEN* filterHpenCollection();

        INT* filterIntCollection(LPCTSTR name);
        CHAR* filterCharCollection(LPCTSTR name);
        HDC* filterHdcCollection(LPCTSTR name);
        HPEN* filterHpenCollection(LPCTSTR name);


        VOID preloadPaintStruct(PAINTSTRUCT &data, LPCTSTR name);
        VOID preloadHdc(HDC &data, LPCTSTR name);

        //디버그용 함수
        VOID printCollectorPtr();
        VOID printCollectorLength();
        //BMP 확장자의 이미지를 로드
        VOID preloadBmpOfImage(LPCWSTR &filePath);

        //쌓인 모든 자원을 표시하도록 준비
        VOID load();
        //등록된 모든 자원을 치워버리기
        VOID cutAll();
    };
    //------------------
    //UIFeedback
    //------------------
    struct UIFeedback
    {
        static FLOAT mouseDefaultTick;
        static BOOL mouseMOVE;
        static UINT mouseX;
        static UINT mouseVX;
        static UINT mouseVXF;
        static UINT mouseY;
        static UINT mouseVY;
        static UINT mouseVYF;
        static UINT mouseVTICK;



        static UINT mouseUP;
        static UINT mouseDown;

        static UINT mouseLUP;
        static UINT mouseLDown;
        static UINT mouseRUP;
        static UINT mouseRDown;

        static UINT mouseIsClicked;

    };
    //------------------
    //DCTOOLSET
    //------------------
    namespace STRINGTOOL
    {
        std::string convert(LPCTSTR str);
    };
    namespace DCTOOLSET
    {
        VOID drawTextAtAFrame(HWND handle, HDC hdc, RECT rect, LPCTSTR text);
    };
    //------------------
    //client
    //------------------
    class client : public winApp, public UIFeedback
    {

    protected:
    private:
        BOOL isBootedClient = FALSE;
        static LRESULT CALLBACK privateWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
        VOID afterMessageDispatch(MSG* msg);
        VOID fluidTickProcess();

        UINT maximumFps;
        HDC clientDC;
        INT fluidTickFrame;
    public:

        //open-variables
        static UINT LIMITOVERFLOWFLAGINT;
        UINT frameBegin;
        UINT frameEnd;
        UINT frameCnt;
        FLOAT frame;


        BOOL nextFrameMove; //unused

        SB_SANDBOX::objectLoader* loader;

        std::function<VOID(HWND hwnd, SB_SANDBOX::objectLoader* loader)>clientBootFn;
        VOID setClientBootFn(std::function<void(HWND hwnd, SB_SANDBOX::objectLoader* loader)> fn);
        std::function<void(HWND hwnd, SB_SANDBOX::objectLoader* loader)> getClientBootFn();

        VOID setActionPerFrame(INT fps=60);

        static LRESULT CALLBACK publicWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
        LPCTSTR& get_lpClassName();
        LPCTSTR& get_lpWndName();
        HWND& get_wndHandle();
        HINSTANCE& get_processHandle();

        explicit client(HINSTANCE hin);
        ~client();

        VOID initApp();
        VOID initInstance();
        INT WINAPI run();

    };
};



#endif //WINDOW_DRAW_TEST02_SB_SANDBOX_H

