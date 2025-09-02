#include "pch.h"
#include "hmDemandDrivenPipeline.h"
#include "hmInformation.h"
#include "hmInformationKey.h"
#include "hmInformationRequestKey.h"
#include "hmInformationIntegerKey.h"

// vtk 파이프라인 단계별로 데이터와 메타데이터를 주는 전역 키 생성 
hmInformationKeyMacro(hmDemandDrivenPipeline, REQUEST_DATA_OBJECT, Request);
/*
// 전역 키 생성
static hmInformationRequestKey* hmDemandDrivenPipeline_REQUEST_DATA_OBJECT =
	new hmInformationRequestKey("REQUEST_DATA_OBJECT", "hmDemandDrivenPipeline");

// 클래스 메서드 생성
hmInformationRequestKey* hmDemandDrivenPipeline::REQUEST_DATA_OBJECT()
{
	return hmDemandDrivenPipeline_REQUEST_DATA_OBJECT;
}
*/

hmTypeBool hmDemandDrivenPipeline::ProcessRequest(hmInformation * request, hmInformationVector ** inInfo, hmInformationVector * outInfo)
{
	// 중복 감지
	if (!this->CheckAlgorithm("ProcessRequest", request))
	{
		return 0;
	}

	if (this->Algorithm && request->Has(REQUEST_DATA_OBJECT()))
	{

	}

	return hmTypeBool();
}
