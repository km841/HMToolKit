#pragma once
#include "hmObjectBase.h"

// �̷� Ŭ������ �� �����ϴ°�?
// vtkInformation �ý��� ����
// vtk ���������ο��� ������ ��û�� ��Ÿ�����͸� �ְ�޴´�
// 1. ��û�� ����
// 2. �������� ��ü ũ��
// 3. �������� Ư�� �κ�
// 4. ����ó�� �� ���� �κ�

// �̷� �������� vtkInformation�� Dictionary key-value ���·� ����Ǿ� ����
// ���⼭ key�� �ٷ� hmInformationKey��
// ���⼭ ��ӹ޴� hmInformationIntegerKey�� ��� ������
// �׳� string�̳� int�� ����� ��� ���� Ű�� � Ÿ������ �ؼ��� �������� ��ȣ����
// �׷��� Ÿ�� �������� Ȯ���ϱ� ���� InformationIntegerKey�� ���� ���� ��ü�� ���
class hmInformationKey :
	public hmObjectBase
{
	// �����ؾ���

};

