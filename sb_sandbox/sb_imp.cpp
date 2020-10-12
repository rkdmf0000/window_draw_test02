//
// Created by my_fl on 2020-10-09.
//
#include "sb_sandbox.h"
LRESULT CALLBACK SB_SANDBOX::GROUND::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    WORD whi = HIWORD(wParam);
    WORD wlo = LOWORD(wParam);
    WORD lhi = HIWORD(lParam);
    WORD llo = LOWORD(lParam);

    SB_SANDBOX::GROUND *pThis;
    if (message == WM_NCCREATE)
    {
        pThis = static_cast<SB_SANDBOX::GROUND*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);

        SetLastError(0);
        if (!SetWindowLongPtr(hWnd, GWL_USERDATA, reinterpret_cast<LONG_PTR>(pThis)))
        {
            if (GetLastError() != 0)
                return FALSE;
        }
    }
    else
    {
        pThis = reinterpret_cast<SB_SANDBOX::GROUND*>(GetWindowLongPtr(hWnd, GWL_USERDATA));
    };

    if (pThis)
    {
        // use pThis->member as needed...
        std::cout << "==========================================loop!" << '\n';
    };


    switch (message) {

        case WM_LBUTTONDOWN:
            std::cout << "========<< WM_LBUTTONDOWN "<< WM_LBUTTONDOWN << "/" << hWnd << " >>" << '\n';
            std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
            std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            break;
        case WM_LBUTTONUP:
            std::cout << "========<< WM_LBUTTONUP "<< WM_LBUTTONUP  << "/" << hWnd <<  " >>" << '\n';
            std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
            std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            break;
        case WM_LBUTTONDBLCLK:
            std::cout << "========<< WM_LBUTTONDBLCLK "<< WM_LBUTTONDBLCLK << "/" << hWnd <<  " >>" << '\n';
            std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
            std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            break;
        case WM_MOUSEMOVE: //클라이언트영역 마우스 움직임
//            std::cout << "<< WM_MOUSEMOVE "<< WM_MOUSEMOVE << " >>" << '\n';
//            std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
//            std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            break;
        case WM_NCMOUSEMOVE: //논클라이언트영역 마우스 움직임
//            std::cout << "<< WM_NCMOUSEMOVE "<< WM_NCMOUSEMOVE << " >>" << '\n';
//            std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
//            std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            break;
        case WM_MOUSEACTIVATE:
            std::cout << "========<< WM_MOUSEACTIVATE "<< WM_MOUSEACTIVATE << "/" << hWnd <<  " >>" << '\n';
            std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
            std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            break;
        case WM_MOVE:
            //std::cout << "<< WM_MOVE >>" << '\n';
            //std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
            //std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            break;
        case WM_PAINTICON:
            std::cout << "========<< WM_PAINTICON "<< WM_PAINTICON << "/" << hWnd <<  " >>" << '\n';
            std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
            std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            break;
        case WM_COMMAND:
            std::cout << "========<< WM_COMMAND "<< WM_COMMAND << "/" << hWnd <<  " >>" << '\n';
            std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
            std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            break;
        case WM_CREATE:
            std::cout << "========<< WM_CREATE "<< WM_CREATE << "/" << hWnd <<  " >>" << '\n';
            std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
            std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            break;
        case WM_PAINT:
            //PAINTSTRUCT PAINT_STRUCT_OBJECT;
            //HDC HDC_OBJECT;
            //Rectangle(HDC_OBJECT, 10, 10, 200, 200);
            //ReleaseDC(hWnd, HDC_OBJECT);
            break;
        case WM_DESTROY:
            std::cout << "========<< WM_DESTROY "<< WM_DESTROY << "/" << hWnd <<  " >>" << '\n';
            std::cout << "wHIWORD : " << HIWORD(wParam) << " / " << "wLOWORD : " << LOWORD(wParam) << '\n';
            std::cout << "lHIWORD : " << HIWORD(lParam) << " / " << "lLOWORD : " << LOWORD(lParam) << '\n';
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
            break;
    };
    return 0;
};

LRESULT CALLBACK SB_SANDBOX::IMP_FUNCTION::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return 0;
};
