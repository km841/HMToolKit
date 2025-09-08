#pragma once
#include "hmObject.h"

// SphereSource 생성
//vtkSphereSource* sphere = vtkSphereSource::New();

// SphereSource의 0번 출력 포트 (vtkAlgorithmOutput 반환)
//vtkAlgorithmOutput* sphereOutput = sphere->GetOutputPort(0);

// ContourFilter 생성
//vtkContourFilter* contour = vtkContourFilter::New();

// ContourFilter 입력 0번 포트에 SphereSource의 출력 연결
//contour->SetInputConnection(0, sphereOutput);
class hmAlgorithm;

// 다른 알고리즘의 입력과 연결할 때 쓰는 프록시 객체
// 실제 데이터가 아닌 연결 지점을 의미
// 내부적으로는 단순히 어떤 알고리즘의 몇 번째 출력 포트인지를 저장
// vtkAlgorithmOutput = 전기 콘센트 소켓
// vtkAlgorithm::GetOuput = 실제 전류(데이터)
class hmAlgorithmOutput :
	public hmObject
{
public:

};

