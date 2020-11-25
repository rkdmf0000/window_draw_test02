//
// Created by my_fl on 2020-11-23.
//

#include "sb_sandbox.h"
//------------------------------------------------------------------------------------------------
//class : objectLoader
//------------------------------------------------------------------------------------------------


SB_SANDBOX::objectLoader::objectLoader()
{
    std::cout << "- - Loader online" << '\n';
    this->collectorLength = 0;
    this->collector = new void*[0];
    this->collectorType.clear();
};
SB_SANDBOX::objectLoader::~objectLoader()
{
    delete this->collector;
    std::cout << "- - Loader offline" << '\n';
};


VOID SB_SANDBOX::objectLoader::load()
{
    std::cout << "- - Loader running on load" << '\n';
};

template<typename _t>
VOID SB_SANDBOX::objectLoader::resourceControl(_t *data)
{

    unsigned int length = this->collectorLength;
    RESOURCE_COLLECTOR dummy = new RESOURCE_PTR[length + 1];
    if (length != 0)
    {
        for(int i(0); i < length; ++i)
        {
            //std::cout << __FUNCTION__ << " backup :" << i << "/" << this->collector[i] << '\n';
            dummy[i] = this->collector[i];
        };
    }

    delete this->collector;

    this->collector = dummy;
    //std::cout << __FUNCTION__ << " new :" << length << "/" << data << '\n';

    this->collector[length] = data;
    ++this->collectorLength;
}







VOID SB_SANDBOX::objectLoader::printCollectorPtr() {
    unsigned int length = this->collectorLength;

    for (int i(0); i < length; ++i)
    {
        unsigned int loopIterIdx(0);
        std::vector<SB_SANDBOX::TYPE_RESOURCE_CONTROL>::iterator loopTypeIter;
        for (loopTypeIter=this->collectorType.begin();loopTypeIter!=this->collectorType.end();++loopTypeIter)
        {
            if (i == loopIterIdx)
            {
                //auto xx = this->collector[i];
                std::cout << "address : " << static_cast<int>(*loopTypeIter) << "/" << this->collector[i] << " = " << typeid(*this->collector).name() << '\n';
            };
            ++loopIterIdx;
        };

    };
};
VOID SB_SANDBOX::objectLoader::printCollectorLength()
{
    std::cout << __FUNCTION__ << ":" << this->collectorLength << '\n';
}



VOID SB_SANDBOX::objectLoader::preloadPaintStruct(PAINTSTRUCT &data, LPCTSTR name) {
    std::vector<std::string>::iterator psIterBuff;
    BOOL sflag(FALSE);
    for (psIterBuff = this->collectorName.begin(); psIterBuff != this->collectorName.end(); ++psIterBuff)
    {
        std::string nameDummy(name);
        std::string nameBuffer(*psIterBuff);
        if (nameBuffer.compare(nameDummy) == 0)
        {
            sflag = TRUE;
            break;
        };
    };
    if (sflag != TRUE)
    {
        this->resourceControl<PAINTSTRUCT>(&data);
        this->collectorType.push_back(SB_SANDBOX::TYPE_RESOURCE_CONTROL::PAINTSTRUCT);
        this->collectorName.push_back(name);
    }
}

VOID SB_SANDBOX::objectLoader::preloadHdc(HDC &data, LPCTSTR name) {
    std::vector<std::string>::iterator psIterBuff;
    BOOL sflag(FALSE);
    for (psIterBuff = this->collectorName.begin(); psIterBuff != this->collectorName.end(); ++psIterBuff)
    {
        std::string nameDummy(name);
        std::string nameBuffer(*psIterBuff);
        if (nameBuffer.compare(nameDummy) == 0)
        {
            sflag = TRUE;
            break;
        };
    };
    if (sflag != TRUE)
    {
        this->resourceControl<HDC>(&data);
        this->collectorType.push_back(SB_SANDBOX::TYPE_RESOURCE_CONTROL::HDC);
        this->collectorName.push_back(name);
    }
}






VOID SB_SANDBOX::objectLoader::filterCollection(SB_SANDBOX::TYPE_RESOURCE_CONTROL type)
{
    unsigned int length = this->collectorLength;
    for (int i(0); i < length; ++i)
    {
        unsigned int loopIterIdx(0);
        std::vector<SB_SANDBOX::TYPE_RESOURCE_CONTROL>::iterator loopTypeIter;
        for (loopTypeIter=this->collectorType.begin();loopTypeIter!=this->collectorType.end();++loopTypeIter)
        {
            if (i == loopIterIdx && type == *loopTypeIter)
            {
                //results += this->collector[i];
                std::cout << "FILTERED - address : " << static_cast<int>(*loopTypeIter) << "/" << this->collector[i] << " = " << typeid(*this->collector).name() << '\n';
            };
            ++loopIterIdx;
        };
    };
}

PAINTSTRUCT* SB_SANDBOX::objectLoader::getResourcePaintStruct(LPCTSTR name)
{
    PAINTSTRUCT* returnValuePtr;
    VOID* p = this->resourceGripper(SB_SANDBOX::TYPE_RESOURCE_CONTROL::PAINTSTRUCT, name);
    returnValuePtr = reinterpret_cast<PAINTSTRUCT*>(p);
    return returnValuePtr;
}

HDC* SB_SANDBOX::objectLoader::getResourceHdc(LPCTSTR name)
{
    HDC* returnValuePtr;
    VOID* p = this->resourceGripper(SB_SANDBOX::TYPE_RESOURCE_CONTROL::HDC, name);
    returnValuePtr = reinterpret_cast<HDC*>(p);
    return returnValuePtr;
}


//이름 비교하고 해당하는 이름 있으면 그 이름이 맞는 타입인지 비교
VOID *SB_SANDBOX::objectLoader::resourceGripper(SB_SANDBOX::TYPE_RESOURCE_CONTROL type, LPCTSTR name)
{
    unsigned int loopIterIdx(0);
    std::vector<std::string>::iterator loopNameIter;
    BOOL isExists(FALSE);
    VOID* resultValue;
    std::string variableStringForComparing(name);
    for (loopNameIter=this->collectorName.begin();loopNameIter!=this->collectorName.end();++loopNameIter)
    {
        std::string stringBuffer(*loopNameIter);
        if (variableStringForComparing.compare(stringBuffer) == 0 && type == this->collectorType[loopIterIdx])
        {
            isExists = TRUE;
            resultValue = this->collector[loopIterIdx];
            break;
        };
        ++loopIterIdx;
    };
    if (isExists == FALSE) return nullptr;
    return resultValue;
}

