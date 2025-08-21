#pragma once
#include "hmExecutive.h"

// vtk는 수요 기반(Demand Driven) 파이프라인 엔진임
// vtkAlgorithm을 실행시키는 구현체 중 하나
// vtk 파이프라인은 pull-based(요청 기반) 모델이므로, 최종 수요자가 
// 이러이러한 데이터를 원해! 라고 요청하면 그때 필요한 만큼만 처리해줌
// 이 부분이 게임 엔진의 실시간 렌더링과 다른 부분
// 최종 수요자(customer)가 이러이러한 데이터를 원해! 
// 하면 이 요청이 데이터 소스나 필터(upstream)으로 전파되면서 필요한 만큼만 계산을 수행함
// 이 방식이 바로 Demand-Driven 방식임

// 파이프라인에는 다양한 REQUEST가 있음
// 1. REQUEST_DATA : 실제 데이터를 계산하라!
// 2. REQUEST_INFORMATION : 데이터의 메타정보를 알려줘라! (범위, 타입)
// 3. REQUEST_UPDATE_EXTENT : 필요한 부분만 업데이트하라! (대용량 Streaming)
class hmInformation;
class hmInformationVector;
class hmDemandDrivenPipeline :
	public hmExecutive
{
public:
	static hmDemandDrivenPipeline* New();
	hmTypeMacro(hmDemandDrivenPipeline, hmExecutive);

	hmTypeBool ProcessRequest(hmInformation* request, hmInformationVector** inInfo, hmInformationVector* outInfo) override;
};

