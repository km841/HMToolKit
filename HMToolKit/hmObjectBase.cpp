#include "pch.h"
#include "hmObjectBase.h"

// Ŭ���� �̸� ���ڿ��� �޾Ƽ� ���� Ŭ������ ��ġ�ϴ��� �˻�
hmTypeBool hmObjectBase::IsTypeOf(const char * name)
{
	if (!strcmp("hmObjectBase", name))
	{
		return 1;
	}

	return 0;
}

// �ش� Ÿ������ �˻�
// C++�� dynamic_cast�� vtk ������� ������ ��
hmTypeBool hmObjectBase::IsA(const char * name)
{
	return this->hmObjectBase::IsTypeOf(name);
}
