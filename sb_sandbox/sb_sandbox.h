//
// Created by my_fl on 2020-10-09.
//


#ifndef WINDOW_DRAW_TEST02_SB_SANDBOX_H
#define WINDOW_DRAW_TEST02_SB_SANDBOX_H
#include "sb_define.h"

//class SB_SANDBOX
//{
//    SB_SANDBOX(){};
//    ~SB_SANDBOX(){};
//private:
//
//public:
//    static BOOL IS_MADEN;
//    BOOL IS_CHILD_SANDBOX;
//    template<typename T>
//    VOID MAKE_TRIGGER(_SETCREATEDEFAULT *object, std::function<T> *callable)
//    {
//
//    };
//};


namespace SB_SANDBOX
{
    interface PRIMARY_INF
    {
        static BOOL is_declared;
    };
    class GROUND : public PRIMARY_INF
    {
        ~GROUND();
    private:
        UINT *LEVEL;
        UINT LEVEL_SIZE;
    public:
        UINT* getLevel();
        UINT getLevelLength();
        VOID setEnvForLevel(UINT maxIndex);
        VOID ForceSetEnvLevelPtr(UINT* ptr, UINT size);
        GROUND();
    };


    namespace IMP_FUNCTION
    {
        LRESULT CALLBACK WndProc(_In_ HWND hWnd, _In_ UINT message, _In_ WPARAM wParam, _In_ LPARAM lParam);
    };
    namespace FUNCTION
    {
        //Set object row index
        VOID setEnvForLevel(SB_SANDBOX::GROUND *ground, INT maxIndex);
        //make up a window
        VOID createAWindowPalette(std::unique_ptr<_SETCREATEDEFAULT> &set, LPCTSTR &lpszClassName, BOOL ImmediateExposure = 0);
        //make up a button as window
        VOID createWindowButton(std::unique_ptr<_SETCREATEDEFAULT> &set, HWND &Palette, HMENU TriggerID, BOOL ImmediateExposure = 0);
        //make virtual button
        VOID createClickable(std::unique_ptr<_SETCREATEVIRTUAL> &set, BOOL ImmediateExposure = 0);
    };
};


#endif //WINDOW_DRAW_TEST02_SB_SANDBOX_H
