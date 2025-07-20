#include "pch.h"
#include "hmObject.h"

hmObject::hmObject()
	:ReferenceCount(0)
{
	this->MTime.Modified();
}

hmObject::~hmObject()
{
}

void hmObject::Register()
{
}

void hmObject::UnRegister()
{
}

int hmObject::GetReferenceCount()
{
	return 0;
}

std::wstring hmObject::GetClassName() const
{
	return std::wstring();
}

bool hmObject::IsA(const std::wstring& _wszTypeName) const
{
	return false;
}


