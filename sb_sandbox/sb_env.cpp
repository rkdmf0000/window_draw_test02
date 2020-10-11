//
// Created by my_fl on 2020-10-09.
//
#include "sb_sandbox.h"

VOID SB_SANDBOX::FUNCTION::setEnvForLevel(SB_SANDBOX::GROUND *ground, const INT maxIndex)
{

    UINT* thisLevel = ground->getLevel();
    const UINT currentGroundLevel = ground->getLevelLength();

    std::cout << "LEVEL SIZE :" << currentGroundLevel << '\n';

    UINT *bufferLevel = new UINT[maxIndex];

    if (maxIndex > currentGroundLevel) //If it's can take it
    {
        std::cout << "<UPPER LEVEL SCALING>" << '\n';
        unsigned int pre_idx;
        for(pre_idx=0; pre_idx < currentGroundLevel ; ++pre_idx)
        {
            bufferLevel[pre_idx] = thisLevel[pre_idx];
            std::cout << pre_idx <<  " : " << thisLevel[pre_idx] << '\n';
        };
        for(;pre_idx < maxIndex; ++pre_idx)
        {
            bufferLevel[pre_idx] = 0;
            std::cout << pre_idx <<  " : (NEW) " << '\n';
        };
        ground->ForceSetEnvLevelPtr(bufferLevel, maxIndex);
    }
    else if(maxIndex == currentGroundLevel) //If same
    {
        std::cout << "(SAME)" << '\n';
    }
    else //If It's over-strawing!!
    {
        std::cout << "(LOW)" << '\n';
    };





//    for(auto buffptr = thisLevel[0] ; buffptr != thisLevel[currentGroundLevel] ; ++buffptr)
//    {
//        std::cout << " : " << buffptr << '\n';
//    };

    delete[] bufferLevel;
//    int (*arraypointer)[4] = new int[1][4]{{1, 2, 3, 4}};
//    for(int &n : *arraypointer) n *= 2;
//    delete [] arraypointer;


};