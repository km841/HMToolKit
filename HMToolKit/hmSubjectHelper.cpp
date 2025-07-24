#include "pch.h"
#include "hmSubjectHelper.h"
#include "hmObserver.h"

hmSubjectHelper::hmSubjectHelper()
	: Focus1(nullptr)
	, Focus2(nullptr)
	, Start(nullptr)
	, Count(1)
{
}

hmSubjectHelper::~hmSubjectHelper()
{
}

unsigned long hmSubjectHelper::AddObserver(unsigned long event, hmCommand* cmd, float p)
{
	hmObserver* elem;
	
	elem = new hmObserver;
	elem->Priority = p;
	elem->Next = nullptr;
	elem->Event = event;
	elem->Command = cmd;
	elem->Tag = this->Count;
	this->Count++;

	if (!this->Start)
	{
		this->Start = elem;
	}

	else
	{
		//insert high priority
		hmObserver* prev = nullptr;
		hmObserver* pos = this->Start;

		// 연결리스트 탐색을 통한 위치 추정
		while (pos->Priority >= elem->Priority && pos->Next)
		{
			prev = pos;
			pos = pos->Next;
		}

		if (pos->Priority > elem->Priority)
		{
			pos->Next = elem;
		}
		else
		{
			if (prev)
			{
				prev->Next = elem;
			}
			elem->Next = pos;

			if (pos == this->Start)
			{
				this->Start = elem;
			}
		}
	}

	return elem->Tag;
}
