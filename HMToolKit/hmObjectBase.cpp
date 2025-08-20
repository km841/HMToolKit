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

// 클래스 이름 문자열을 받아서 현재 클래스와 일치하는지 검사
hmTypeBool hmObjectBase::IsTypeOf(const char * name)
{
	if (!strcmp("hmObjectBase", name))
	{
		return 1;
	}

	return 0;
}

// 해당 타입인지 검사
// C++의 dynamic_cast를 vtk 방식으로 구현한 것
hmTypeBool hmObjectBase::IsA(const char * name)
{
	return this->hmObjectBase::IsTypeOf(name);
}
