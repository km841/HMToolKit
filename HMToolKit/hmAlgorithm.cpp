#include "pch.h"
#include "hmAlgorithm.h"

hmExecutive* hmAlgorithm::DefaultExecutivePrototype = nullptr;

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

hmExecutive* hmAlgorithm::CreateDefaultExecutive()
{
    if (hmAlgorithm::DefaultExecutivePrototype)
    {
        //return hmAlgorithm::DefaultExecutivePrototype->NewInstance();
    }

    // hmCompositePipeline
    return nullptr;
}
