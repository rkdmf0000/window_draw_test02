//
// Created by my_fl on 2020-10-09.
//
#include "sb_sandbox.h"

VOID SB_SANDBOX::FUNCTION::setEnvForLevel(SB_SANDBOX::GROUND *ground, const INT maxIndex)
{

    UINT* thisLevel = ground->getLevel();
    const UINT currentGroundLevel = ground->getLevelLength();

    std::cout << "LEVEL SIZE :" << currentGroundLevel << '\n';

    INT *bufferLevel = new INT[maxIndex];



//    for(auto buffptr = thisLevel[0] ; buffptr != thisLevel[currentGroundLevel] ; ++buffptr)
//    {
//        std::cout << " : " << buffptr << '\n';
//    };

    delete[] bufferLevel;
//    int (*arraypointer)[4] = new int[1][4]{{1, 2, 3, 4}};
//    for(int &n : *arraypointer) n *= 2;
//    delete [] arraypointer;


};