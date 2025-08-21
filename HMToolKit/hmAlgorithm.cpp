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

// Default Executive�� �� ������ �⺻ Executive�� Ŀ������ �� �ֵ��� �� ��
// SetDefaultExecutivePrototype�� ���� ������ ���ϴ� �������� Ŀ������ �� �ְԲ� �ϱ� ����
hmExecutive* hmAlgorithm::CreateDefaultExecutive()
{
    if (hmAlgorithm::DefaultExecutivePrototype)
    {
        return hmAlgorithm::DefaultExecutivePrototype->NewInstance();
    }

    // hmCompositePipeline
    return nullptr;
}
