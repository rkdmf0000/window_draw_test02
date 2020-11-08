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
        //TODO : 자원을 포인터로 저장하는것 까진 좋은데 이걸 편히 불러오려면 각 배열마다의 타입을 알고있어야 할 것이다.
        INT_PTR* collector;
        WORD collectorLength;

        //로드할 자원을 collector에 쌓아주는 메서드
        VOID resourceInitor();
    public:
        //it calculation support by used resource detach process.
        static UINT itStackedHowMuch;

        objectLoader();
        ~objectLoader();


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
        VOID afterMessageDispatch();

        HDC clientDC;

    public:

        //open-variables
        static INT LIMITOVERFLOWFLAGINT;
        UINT frameBegin;
        UINT frameEnd;
        UINT frameCnt;
        FLOAT frame;

        SB_SANDBOX::objectLoader* loader;

        std::function<VOID(SB_SANDBOX::objectLoader* loader)>clientBootFn;
        VOID setClientBootFn(std::function<void(SB_SANDBOX::objectLoader* loader)> fn);
        std::function<void(SB_SANDBOX::objectLoader* loader)> getClientBootFn();

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

