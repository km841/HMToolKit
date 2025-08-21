#pragma once
#include "hmObject.h"

// 1. Update -> ProcessRequest
//  - 실행 흐름 잡기
// 2. REQUEST_INFORMATION / REQUEST_DATA / REQUEST_UPDATE_EXTENT
//  - 어떤 단계에서 어떤 일이 일어나는지 확인
// 3. vtkDemandDrivenPipeline (vtkExecutive의 서브클래스)
//  - 실제로 자주 쓰이는 구현체, 여기서 Update 로직이 구체화됨
// 4. vtkStreamingDemandDrivenPipeline
//  - Extent 기반 스트리밍 / 대용량 데이터 처리 흐름까지 확장

class hmAlgorithm;
class hmInformation;
class hmInformationVector;
class hmExecutive :
    public hmObject
{
public:
	hmTypeMacro(hmExecutive, hmObject);

	// 연결된 모든 Output port에 대해 데이터가 최신 상태가 되도록 파이프라인 실행
	virtual hmTypeBool Update();

	// 특정 Output port만 갱신할 때 사용, 필터가 여러개? 그 중 하나만 업데이트 가능
	virtual hmTypeBool Update(int port);

	// 같은 요청이 중첩되어 발생하고 있는지 체크 (A -> B -> A와 같은..)
	// 재귀 요청이 없으면 1 리턴
	// 있으면 0 리턴, 에러 메시지 출력
	int CheckAlgorithm(const char*, hmInformation* request);
	virtual hmTypeBool ProcessRequest(hmInformation* request, hmInformationVector** inInfo, hmInformationVector* outInfo);

protected:
	hmAlgorithm* Algorithm;
	int InAlgorithm;
};

