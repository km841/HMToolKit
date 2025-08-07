#pragma once
#include "hmObject.h"

class hmExecutive;

class hmAlgorithm :
    public hmObject
{
public:
    static hmAlgorithm* New();

    enum DesiredOutputPrecision
    {
        SINGLE_PRECISION,
        DOUBLE_PRECISION,
        DEFAULT_PRECISION,
    };

    // 이 구문은 Executive가 있는지 확인만 하고 생성하지 않음
    hmTypeBool HasExecutive();

    // HasExecutive로 Executive가 있는지 확인하고 없다면, 기본 Executive를 생성
    hmExecutive* GetExecutive();


    // Executive를 세팅함
    // Executive가 기존에 있었다면 삭제함
    // 웬만하면 기본 Executive를 쓰는게 좋음 고급 개발자용 기능임
    virtual void SetExecutive(hmExecutive* executive);

    virtual hmExecutive* CreateDefaultExecutive();

protected:
    static hmExecutive* DefaultExecutivePrototype;

private:
    hmExecutive* Executive;
};

