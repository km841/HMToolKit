#pragma once
#include "hmObject.h"

// SphereSource ����
//vtkSphereSource* sphere = vtkSphereSource::New();

// SphereSource�� 0�� ��� ��Ʈ (vtkAlgorithmOutput ��ȯ)
//vtkAlgorithmOutput* sphereOutput = sphere->GetOutputPort(0);

// ContourFilter ����
//vtkContourFilter* contour = vtkContourFilter::New();

// ContourFilter �Է� 0�� ��Ʈ�� SphereSource�� ��� ����
//contour->SetInputConnection(0, sphereOutput);
class hmAlgorithm;

// �ٸ� �˰����� �Է°� ������ �� ���� ���Ͻ� ��ü
// ���� �����Ͱ� �ƴ� ���� ������ �ǹ�
// ���������δ� �ܼ��� � �˰����� �� ��° ��� ��Ʈ������ ����
// vtkAlgorithmOutput = ���� �ܼ�Ʈ ����
// vtkAlgorithm::GetOuput = ���� ����(������)
class hmAlgorithmOutput :
	public hmObject
{
public:

};

