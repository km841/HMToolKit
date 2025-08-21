#pragma once
#include "hmObject.h"

// 1. Update -> ProcessRequest
//  - ���� �帧 ���
// 2. REQUEST_INFORMATION / REQUEST_DATA / REQUEST_UPDATE_EXTENT
//  - � �ܰ迡�� � ���� �Ͼ���� Ȯ��
// 3. vtkDemandDrivenPipeline (vtkExecutive�� ����Ŭ����)
//  - ������ ���� ���̴� ����ü, ���⼭ Update ������ ��üȭ��
// 4. vtkStreamingDemandDrivenPipeline
//  - Extent ��� ��Ʈ���� / ��뷮 ������ ó�� �帧���� Ȯ��

class hmAlgorithm;
class hmInformation;
class hmInformationVector;
class hmExecutive :
    public hmObject
{
public:
	hmTypeMacro(hmExecutive, hmObject);

	// ����� ��� Output port�� ���� �����Ͱ� �ֽ� ���°� �ǵ��� ���������� ����
	virtual hmTypeBool Update();

	// Ư�� Output port�� ������ �� ���, ���Ͱ� ������? �� �� �ϳ��� ������Ʈ ����
	virtual hmTypeBool Update(int port);

	// ���� ��û�� ��ø�Ǿ� �߻��ϰ� �ִ��� üũ (A -> B -> A�� ����..)
	// ��� ��û�� ������ 1 ����
	// ������ 0 ����, ���� �޽��� ���
	int CheckAlgorithm(const char*, hmInformation* request);
	virtual hmTypeBool ProcessRequest(hmInformation* request, hmInformationVector** inInfo, hmInformationVector* outInfo);

protected:
	hmAlgorithm* Algorithm;
	int InAlgorithm;
};

