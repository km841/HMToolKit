#include "pch.h"
#include "hmAlgorithm.h"
#include "hmExecutive.h"

hmExecutive* hmAlgorithm::DefaultExecutivePrototype = nullptr;

int hmAlgorithm::GetNumberOfInputPorts()
{
	return 0;
}

int hmAlgorithm::GetNumberOfOutputPorts()
{
	return 0;
}

hmTypeBool hmAlgorithm::HasExecutive()
{
    return this->Executive ? 1 : 0;
}

hmExecutive* hmAlgorithm::GetExecutive()
{
    //if (!this->HasExecutive())
    //{
    //    hmExecutive* e = this->CreateDefaultExecutive();
    //    this->SetExecutive(e);
    //    e->Delete();
    //}
    return this->Executive;
}

void hmAlgorithm::SetExecutive(hmExecutive* executive)
{
}

// Default Executive를 둔 이유는 기본 Executive를 커스텀할 수 있도록 한 것
// SetDefaultExecutivePrototype을 통해 유저가 원하는 방향으로 커스텀할 수 있게끔 하기 위해
hmExecutive* hmAlgorithm::CreateDefaultExecutive()
{
    if (hmAlgorithm::DefaultExecutivePrototype)
    {
        return hmAlgorithm::DefaultExecutivePrototype->NewInstance();
    }

    // hmCompositePipeline
    return nullptr;
}
