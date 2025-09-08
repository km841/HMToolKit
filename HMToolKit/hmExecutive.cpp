#include "pch.h"
#include "hmExecutive.h"
#include "hmAlgorithm.h"
#include "hmInformation.h"

hmTypeBool hmExecutive::Update()
{
	if (this->Algorithm->GetNumberOfOutputPorts())
	{
		return this->Update(0);
	}

	return this->Update(-1);
}

hmTypeBool hmExecutive::Update(int port)
{
	// Error, 구현되지 않았으므로 구현하라는 에러 메시지 출력
	return 0;
}

// InAlgorithm이 0이 아니라면 중복 실행된 것이므로 여기서 감지
int hmExecutive::CheckAlgorithm(const char *, hmInformation * request)
{
	if (this->InAlgorithm)
	{
		if (request)
		{
			std::ostringstream rqmsg;
			request->Print(rqmsg);
			// ErrorMsg 출력
		}
		else
		{
			// ErrorMsg 출력
		}

		return 0;
	}

	return 1;
}

hmTypeBool hmExecutive::ProcessRequest(hmInformation * request, hmInformationVector ** inInfo, hmInformationVector * outInfo)
{
	// 구현해야함


	return hmTypeBool();
}

int hmExecutive::ForwardDownstream(hmInformation * request)
{
	return 0;
}

// 내 알고리즘이 데이터를 받는 대상 : 입력 알고리즘
// 내가 밥을 먹으려면 밥해주는 사람 필요함 -> 밥해주는 사람 : 입력 알고리즘
// vtkPipeline은 여러 알고리즘들이 서로 연결된 그래프처럼 생김
// 

int hmExecutive::ForwardUpstream(hmInformation * request)
{
	return 0;
}
