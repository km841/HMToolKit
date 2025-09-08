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

	// 실행할 알고리즘이 있고, 
	// 요청이 REQUEST_DATA_OBJECT ( 즉, 출력 데이터 객체를 만들어달라는 요청)
	// 일 때만 실행
	// REQUEST_DATA_OBJECT는 vtkDataObject를 생성/갱신하는 단계
	if (this->Algorithm && request->Has(REQUEST_DATA_OBJECT()))
	{
		// 파이프라인이 변경된 시간이 데이터 객체 수정 시간보다 과거라면, 이미 최신
		if (this->PipelineMTime < this->DataObjectTime.GetMTime())
		{
			return 1;
		}

		// 여기로 내려왔다는 건 파이프라인이 최신이 아니라는 것
		// 업데이트가 필요하다는 얘기

	}

	return hmTypeBool();
}
