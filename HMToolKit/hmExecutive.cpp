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

		if (getenv("DASHBOARD_TEST_FROM_CTEST") || getenv("DART_TEST_FROM_DART"))
		{
			abort();
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
