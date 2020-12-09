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
    //Functional procedure
    //------------------
    class functionalPD
    {

    public:
        static functionalPD mainInstanceHandle;
        functionalPD& getInstance();


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

        //############################################
        //############################################
        //############################################
        VOID preloadHwnd(HWND *data, LPCTSTR name);
        VOID preloadInt(INT *data, LPCTSTR name);
        VOID preloadPaintStruct(PAINTSTRUCT *data, LPCTSTR name);
        VOID preloadHdc(HDC *data, LPCTSTR name);
        VOID preloadHbitmap(HBITMAP *data, LPCTSTR name);
        VOID preloadBitmap(BITMAP *data, LPCTSTR name);
        VOID preloadGdiplusImage(Gdiplus::Image *data, LPCTSTR name);
        VOID preloadGdiplusGraphics(Gdiplus::Graphics *data, LPCTSTR name);
        //############################################
        HWND* getResourceHwnd(LPCTSTR name);
        INT* getResourceInt(LPCTSTR name);
        PAINTSTRUCT* getResourcePaintStruct(LPCTSTR name);
        HDC* getResourceHdc(LPCTSTR name);
        HBITMAP* getResourceHbitmap(LPCTSTR name);
        BITMAP* getResourceBitmap(LPCTSTR name);
        Gdiplus::Image* getResourceGdiplusImage(LPCTSTR name);
        Gdiplus::Graphics* getResourceGdiplusGraphics(LPCTSTR name);
        //############################################
        //############################################
        //############################################
        //static UINT itStackedHowMuch; //it calculation support by used resource detach process.

        objectLoader();
        ~objectLoader();

        VOID filterCollection(SB_SANDBOX::TYPE_RESOURCE_CONTROL type);





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
    namespace MATHTOOL
    {
        //정규화
        const float Normalization(float v_min, float v_max, float value, float n_min = 0.000f, float n_max = 1.000f);
    };
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
        INT fluidTickFrame;
    public:

        //open-variables
        static UINT LIMITOVERFLOWFLAGINT;
        UINT frameBegin;
        UINT frameEnd;
        UINT frameCnt;
        FLOAT frame;
        FLOAT frameDelay;

        Gdiplus::GdiplusStartupInput gdipStartupInput;
        ULONG_PTR gdipToken;

        BOOL nextFrameMove; //unused

        SB_SANDBOX::objectLoader* loader;

        //for_window_message
        VOID FOR_PROCEDURE__WM_PAINT(const HWND);

        //boot_fn
        std::function<VOID(HWND hwnd, SB_SANDBOX::objectLoader* loader)>clientBootFn;
        VOID setClientBootFn(std::function<void(HWND hwnd, SB_SANDBOX::objectLoader* loader)> fn);
        std::function<void(HWND hwnd, SB_SANDBOX::objectLoader* loader)> getClientBootFn();

        //for_controls_frame
        VOID setActionPerFrame(INT fps=60);

        //for_win_procedire
        static LRESULT CALLBACK publicWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

        //for_process_info_security
        LPCTSTR& get_lpClassName();
        LPCTSTR& get_lpWndName();
        HWND& get_wndHandle();
        HINSTANCE& get_processHandle();


        //construction and else
        explicit client(HINSTANCE hin);
        ~client();

        //for_inits_app
        VOID initApp();
        VOID initInstance();
        INT WINAPI run();
        VOID initGdiplusStartup();
    };
};



#endif //WINDOW_DRAW_TEST02_SB_SANDBOX_H

