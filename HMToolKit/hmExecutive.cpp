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
	// Error, �������� �ʾ����Ƿ� �����϶�� ���� �޽��� ���
	return 0;
}

// InAlgorithm�� 0�� �ƴ϶�� �ߺ� ����� ���̹Ƿ� ���⼭ ����
int hmExecutive::CheckAlgorithm(const char *, hmInformation * request)
{
	if (this->InAlgorithm)
	{
		if (request)
		{
			std::ostringstream rqmsg;
			request->Print(rqmsg);
			// ErrorMsg ���
		}
		else
		{
			// ErrorMsg ���
		}

		return 0;
	}

	return 1;
}

hmTypeBool hmExecutive::ProcessRequest(hmInformation * request, hmInformationVector ** inInfo, hmInformationVector * outInfo)
{
	// �����ؾ���


	return hmTypeBool();
}

int hmExecutive::ForwardDownstream(hmInformation * request)
{
	return 0;
}

// �� �˰����� �����͸� �޴� ��� : �Է� �˰���
// ���� ���� �������� �����ִ� ��� �ʿ��� -> �����ִ� ��� : �Է� �˰���
// vtkPipeline�� ���� �˰������ ���� ����� �׷���ó�� ����
// 

int hmExecutive::ForwardUpstream(hmInformation * request)
{
	return 0;
}
