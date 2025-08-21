#pragma once
#include "hmExecutive.h"

// vtk�� ���� ���(Demand Driven) ���������� ������
// vtkAlgorithm�� �����Ű�� ����ü �� �ϳ�
// vtk ������������ pull-based(��û ���) ���̹Ƿ�, ���� �����ڰ� 
// �̷��̷��� �����͸� ����! ��� ��û�ϸ� �׶� �ʿ��� ��ŭ�� ó������
// �� �κ��� ���� ������ �ǽð� �������� �ٸ� �κ�
// ���� ������(customer)�� �̷��̷��� �����͸� ����! 
// �ϸ� �� ��û�� ������ �ҽ��� ����(upstream)���� ���ĵǸ鼭 �ʿ��� ��ŭ�� ����� ������
// �� ����� �ٷ� Demand-Driven �����

// ���������ο��� �پ��� REQUEST�� ����
// 1. REQUEST_DATA : ���� �����͸� ����϶�!
// 2. REQUEST_INFORMATION : �������� ��Ÿ������ �˷����! (����, Ÿ��)
// 3. REQUEST_UPDATE_EXTENT : �ʿ��� �κи� ������Ʈ�϶�! (��뷮 Streaming)
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

