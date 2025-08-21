#pragma once
#include "hmObject.h"

class hmInformation;
class hmInformationVectorInternals;

// �� �ڲ� Internals�� ���� �ɱ�?
// Internals�� �ƴ� Ŭ������ �ܼ� ������ ���Ҹ� �ϰ�, Internals������ ���� ����
// �̷��� �� ������ ����ڴ� ���� Ŭ������ ����ϱ� ������ ���� Ŭ������ �������̽��� ����
// ���� ������ Internals���� �����ϰ� ���������ν� �������̽� ����

class hmInformationVector :
	public hmObject
{
public:
	hmTypeMacro(hmInformationVector, hmObject);
	static hmInformationVector* New();

	int GetNumberOfInformationObjects() { return this->NumberOfInformationObjects; }

protected:
	int NumberOfInformationObjects;
};

