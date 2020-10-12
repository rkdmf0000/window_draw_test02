//
// Created by my_fl on 2020-10-09.
//
#include "sb_sandbox.h"
VOID SB_SANDBOX::FUNCTION::createAWindowPalette(std::unique_ptr<_SETCREATEDEFAULT> &set, LPCTSTR &lpszClassName, BOOL ImmediateExposure) {
    std::cout << "(" << &set->hwnd << ") ";
    std::cout << "WINDOW-" << "(" << &*set << ")" << "-POS : " << set->pos.x << "/";
    std::cout << " " << set->pos.y << "/";
    std::cout << " " << set->pos.w << "/";
    std::cout << " " << set->pos.h << '\n';


    set->hwnd = CreateWindow(
            lpszClassName,
            _T("title"),
            WS_OVERLAPPEDWINDOW,
            set->pos.x, set->pos.y,
            set->pos.w, set->pos.h,
            NULL,
            NULL,
            set->hinc,
            NULL
    );

    if (!set->hwnd) {
        MessageBox(NULL,
                   _T("Call to Create\"Window\" failed!"),
                   _T("Windows Desktop Alert"),
                   0);
        std::cout << "(" << &set->hwnd << ") " << "--FAILURE" << '\n';
    } else {
        std::cout << "(" << &set->hwnd << ") " << "--OK" << "(" << set->hwnd <<  ")" << '\n';
    };


    if (ImmediateExposure == 1) {
        ShowWindow(set->hwnd, 1);
        UpdateWindow(set->hwnd);
    };
};

VOID SB_SANDBOX::FUNCTION::createWindowButton(std::unique_ptr<_SETCREATEDEFAULT> &set, HWND &Palette, HMENU TriggerID, BOOL ImmediateExposure) {
    std::cout << "(" << &set->hwnd << ") ";
    std::cout << "BUTTON-" << "(" << &*set << ")" << "-POS : " << set->pos.x << "/";
    std::cout << " " << set->pos.y << "/";
    std::cout << " " << set->pos.w << "/";
    std::cout << " " << set->pos.h << '\n';

    set->hwnd = CreateWindow(
            _T("BUTTON"),
            _T("BUTTON TEXT"),
            WS_CHILD | WS_VISIBLE,
            set->pos.x, set->pos.y,
            set->pos.w, set->pos.h,
            Palette,
            TriggerID,
            set->hinc,
            NULL
    );

    if (!set->hwnd) {
        MessageBox(NULL,
                   _T("Call to Create\"Button\" failed!"),
                   _T("Windows Desktop Alert"),
                   0);
        std::cout << "(" << &set->hwnd << ") " << "--FAILURE" << '\n';
    } else {
        std::cout << "(" << &set->hwnd << ") " << "--OK" << '\n';
    };


    if (ImmediateExposure == 1) {
        ShowWindow(set->hwnd, 1);
        UpdateWindow(set->hwnd);
    };
};






VOID SB_SANDBOX::GROUND::setEnvForLevel(UINT maxIndex)
{
    SB_SANDBOX::FUNCTION::setEnvForLevel(this, maxIndex);
};

UINT* SB_SANDBOX::GROUND::getLevel()
{
    return this->LEVEL;
};
UINT* SB_SANDBOX::GROUND::getLevelGroup()
{
    return this->LEVEL_GROUP;
};
UINT SB_SANDBOX::GROUND::getLevelLength()
{
    return this->LEVEL_SIZE;
}

SB_SANDBOX::GROUND::GROUND() {
    std::cout << "SB::SANDBOX::GROUND CREATED!" << '\n';
    this->LEVEL_SIZE    = 255;
    this->LEVEL_STACK   = 0;
    this->LEVEL         = new UINT[this->LEVEL_SIZE];
    this->LEVEL_GROUP   = new UINT[this->LEVEL_SIZE];

    for(INT initializationLevelSizeIDX(0);initializationLevelSizeIDX<this->LEVEL_SIZE;++initializationLevelSizeIDX)
    {
        std::cout << "LEVEL_SIZE Initializational IDX : " << initializationLevelSizeIDX << '\r';
        this->LEVEL[initializationLevelSizeIDX] = 0;
        this->LEVEL_GROUP[initializationLevelSizeIDX] = 0;
    };
    std::cout << "\r\nLEVEL_SIZE Initializational IDX : " << "GOOD!" << '\n';

};
SB_SANDBOX::GROUND::~GROUND() {
    std::cout << "SB::SANDBOX::GROUND DESTROYED!" << '\n';
    //heep clear
    delete[] this->LEVEL;
    delete[] this->LEVEL_GROUP;
    //delete[] this->MAP;
}

VOID SB_SANDBOX::GROUND::ForceSetEnvLevelPtr(UINT *ptr, UINT size) {
    std::cout << __FUNCTION__ << " ACTIVATED!" << '\n';
    delete[] this->LEVEL;
    this->LEVEL = ptr;
    this->LEVEL_SIZE = size;
}
VOID SB_SANDBOX::FUNCTION::createClickable(SB_SANDBOX::GROUND *ground, std::unique_ptr<_SETCREATEVIRTUAL> &set, BOOL ImmediateExposure)
{
    std::cout << __FUNCTION__ << " ACTIVATED!" << '\n';
    ground->insertVirtualObjectByLevel(set.get(),1);
};
VOID SB_SANDBOX::GROUND::insertVirtualObjectByLevel(_SETCREATEVIRTUAL* objptr, UINT levelNumber) {
    UINT uptrint = (UINT)objptr;
    std::cout << __FUNCTION__ << " Pointer Number:" << uptrint << '\n';
    this->LEVEL[this->LEVEL_STACK] = uptrint;
    this->LEVEL_GROUP[this->LEVEL_STACK] = levelNumber;
    ++this->LEVEL_STACK;
}


