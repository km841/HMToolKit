#include "pch.h"
#include "hmDemandDrivenPipeline.h"
#include "hmInformation.h"
#include "hmInformationKey.h"
#include "hmInformationRequestKey.h"
#include "hmInformationIntegerKey.h"

// vtk ���������� �ܰ躰�� �����Ϳ� ��Ÿ�����͸� �ִ� ���� Ű ���� 
hmInformationKeyMacro(hmDemandDrivenPipeline, REQUEST_DATA_OBJECT, Request);
/*
// ���� Ű ����
static hmInformationRequestKey* hmDemandDrivenPipeline_REQUEST_DATA_OBJECT =
	new hmInformationRequestKey("REQUEST_DATA_OBJECT", "hmDemandDrivenPipeline");

// Ŭ���� �޼��� ����
hmInformationRequestKey* hmDemandDrivenPipeline::REQUEST_DATA_OBJECT()
{
	return hmDemandDrivenPipeline_REQUEST_DATA_OBJECT;
}
*/

hmTypeBool hmDemandDrivenPipeline::ProcessRequest(hmInformation * request, hmInformationVector ** inInfo, hmInformationVector * outInfo)
{
	// �ߺ� ����
	if (!this->CheckAlgorithm("ProcessRequest", request))
	{
		return 0;
	}

	// ������ �˰����� �ְ�, 
	// ��û�� REQUEST_DATA_OBJECT ( ��, ��� ������ ��ü�� �����޶�� ��û)
	// �� ���� ����
	// REQUEST_DATA_OBJECT�� vtkDataObject�� ����/�����ϴ� �ܰ�
	if (this->Algorithm && request->Has(REQUEST_DATA_OBJECT()))
	{
		// ������������ ����� �ð��� ������ ��ü ���� �ð����� ���Ŷ��, �̹� �ֽ�
		if (this->PipelineMTime < this->DataObjectTime.GetMTime())
		{
			return 1;
		}

		// ����� �����Դٴ� �� ������������ �ֽ��� �ƴ϶�� ��
		// ������Ʈ�� �ʿ��ϴٴ� ���

	}

	return hmTypeBool();
}
