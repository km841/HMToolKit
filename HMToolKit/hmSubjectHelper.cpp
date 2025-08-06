#include "pch.h"
#include "hmSubjectHelper.h"
#include "hmObserver.h"
#include "hmCommand.h"

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

hmTypeBool hmSubjectHelper::InvokeEvent(unsigned long event, void* callData, hmObject* self)
{
	bool focusHandled = false;
	this->ListModified.push_back(false);

	typedef std::vector<unsigned long> VisitedListType;
	VisitedListType visited;
	hmObserver* elem = this->Start;

	const unsigned long maxTag = this->Count;

	// InvokeEvent는 총 3개의 Loop로 이루어져 있음
	// 1. PassiveObserver Loop

	hmObserver* next;
	while (elem)
	{
		next = elem->Next;

		if (elem->Command->GetPassiveObserver() &&
		   (elem->Event == event || elem->Event == hmCommand::AnyEvent) && 
			elem->Tag < maxTag)
		{
			// Tag가 삽입될 적절한 위치를 찾는 로직
			// Tag를 왜 삽입 기준으로 삼는가? 그것은 Tag는 삽입 순서 기반의 고유 번호이기 때문
			// 삽입 순서? AddObserver가 되는 순서를 의미
			// Passive Observer 중에서도 Observer가 삽입된 순서로 정렬하기 위해서!! 이렇게 이터레이터를 찾는 것임
			VisitedListType::iterator vIter = std::lower_bound(visited.begin(), visited.end(), elem->Tag);

			// 아직 해당 태그가 붙은 옵저버를 방문하지 않았다면? 실행
			if (vIter == visited.end() || *vIter != elem->Tag)
			{
				visited.insert(vIter, elem->Tag);
				hmCommand* command = elem->Command;
				
				// 실제 vtk에선 해당 코드 실행 후 command에 대한 reference count를 감소시켜 가비지컬렉팅
				elem->Command->Execute(self, event, callData);
			}
			
			// back이 true인 경우는 Observer List에 변화가 생겼다는 의미로, InvokeEvent에서는 경고만 날려줌
			// 확인해보니 RemoveObserver에서  ListModified를 true로 바꿔주고 있는데,
			// InvokeEvent 도중 옵저버가 삭제되면 예기치못한 문제가 발생할 수 있기 때문에
			// 옵저버의 변화를 감지하는 것으로 생각됨
			// AddObserver에서는 이 값을 변화시키지 않고 있는데 단순히 옵저버가 추가되는 것은 이벤트를 처리하는데 있어서 문제를 일으키지 않는다고 판단했기 때문인듯
			if (this->ListModified.back())
			{
				//vtkGenericWarningMacro(
				//	<< "Passive observer should not call AddObserver or RemoveObserver in callback.");
				elem = this->Start;
				this->ListModified.back() = false;
			}
			else
			{
				elem = next;
			}

		}
	}

	// Focus, 즉 바로 처리할 커맨드가 있는지 검사
	if (this->Focus1 || this->Focus2)
	{
		elem = this->Start;

		// 연결리스트 순회
		while (elem)
		{
			next = elem->Next;
			// 두 포커스 중 하나라도 같고, 이벤트가 같거나, 모든 이벤트를 처리하는 커맨드거나, 실행시점에 추가된 옵저버인 경우
			if (((this->Focus1 == elem->Command) || (this->Focus2 == elem->Command)) &&
				(elem->Event == event || elem->Event == hmCommand::AnyEvent) && elem->Tag < maxTag) 
			{
				// 이미 방문한 노드인지 확인하기 위한 "이진 탐색"
				VisitedListType::iterator vIter = std::lower_bound(visited.begin(), visited.end(), elem->Tag);

				// vIter == visited.end라면 찾다가 맨 끝까지 간것이므로 중복 아님
				// *vIter != elem->Tag라면 Tag보다 큰 다른 값만 있는 것!
				// Tag는 옵저버를 구분하는 고유식별자!
				if (vIter == visited.end() || *vIter != elem->Tag)
				{
					// 포커스가 실행 되었으므로 루프 끝
					focusHandled = true;

					// 방문 등록
					visited.insert(vIter, elem->Tag);

					hmCommand* command = elem->Command;
					command->SetAbortFlag(0);

					elem->Command->Execute(self, event, callData);

					if (command->GetAbortFlag())
					{
						this->ListModified.pop_back();
						return 1;
					}
				}
			}

			// 리스트가 변경되었다면 처음으로 돌린다
			if (this->ListModified.back())
			{
				elem = this->Start;
				this->ListModified.back() = false;
			}
			else
			{
				elem = next;
			}
		}
	}

	// 포커스가 없을때 실행하는 remainder loop
	// 왜일까? 포커스를 위에서 execute했는데 아래껄 실행하지 않는 이유는?
	// focus에서 이벤트가 처리되었으면 remainder 자체를 돌지 않도록 처리
	// focus observer를 처리했다는 건 우선순위가 가장 높은 대상이 이벤트를 처리했다는 것
	// 예시로 마우스 클릭이 처리되었는데 다른 패널이 이 클릭을 또 받는건 비정상적
	// focusHandled로 단일 경로로 분리함으로써 observer가 중복 호출되거나 리스트가 변경되는 복잡한 환경에서 버그 발생 확률을 줄임
	if (!focusHandled)
	{
		// root node 시작
		elem = this->Start;
		while (elem)
		{
			// 다음 노드로 이동할때 씀
			next = elem->Next;
			if ((elem->Event == event || elem->Event == hmCommand::AnyEvent) && elem->Tag < maxTag)
			{
				VisitedListType::iterator vIter =
					std::lower_bound(visited.begin(), visited.end(), elem->Tag);

				if (vIter == visited.end() || *vIter != elem->Tag)
				{
					// Sorted insertion by tag to speed-up future searches at limited
					// insertion cost because it reuses the search iterator already at the
					// correct location
					// Tag값을 기준으로, 정렬된 상태로 삽입하면 이후 검색이 더 빨라진다!
					// 삽입 비용도 낮은데, 그 이유는 이전에 사용했던 이터레이터를 재사용하기 때문이다!!
					// 연결리스트가 정렬되어 있기 때문에 이진탐색을 빠르게 수행할 수 있음 (lower_bound)
					// 그리고 lower_bound에서 찾은 iterator를 바로 삽입에 사용하기 때문에 속도가 매우 빠름

					visited.insert(vIter, elem->Tag);
					hmCommand* command = elem->Command;

					// 실질적인 커맨드 실행
					elem->Command->Execute(self, event, callData);

					// AbortFlag 세워져 있으면 바로 종료
					if (command->GetAbortFlag())
					{
						this->ListModified.pop_back();
						return 1;
					}

				}
			}

			// 리스트 변경이 있었으면 처음으로 돌림
			if (this->ListModified.back())
			{
				elem = this->Start;
				this->ListModified.back() = false;
			}
			else
			{
				//아니면 다음으로 진행
				elem = next;
			}
		}
	}

	this->ListModified.pop_back();
	return 0;
}
