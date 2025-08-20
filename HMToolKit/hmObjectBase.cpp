#include "pch.h"
#include "hmObjectBase.h"

const char * hmObjectBase::GetClassNameA() const
{
	return GetClassNameInternal();
}

const char * hmObjectBase::GetClassNameW() const
{
	return GetClassNameInternal();
}

hmIdType hmObjectBase::GetNumberOfGenerationsFromBaseType(const char * name)
{
	if (!strcmp("hmObjectBase", name))
	{
		return 0;
	}

	return hmIdType();
}

hmIdType hmObjectBase::GetNumberOfGenerationsFromBase(const char * name)
{
	return this->hmObjectBase::GetNumberOfGenerationsFromBaseType(name);
}

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
