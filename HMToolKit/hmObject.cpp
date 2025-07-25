#include "pch.h"
#include "hmObject.h"

hmObject::hmObject()
{
	this->SubjectHelper = nullptr;
	this->MTime.Modified();
}

hmObject::~hmObject()
{
	delete this->SubjectHelper;
	this->SubjectHelper = nullptr;
}

hmMTimeType hmObject::GetMTime()
{
	return this->MTime.GetMTime();
}

void hmObject::Modified()
{
	this->MTime.Modified();

}

hmTypeBool hmObject::InvokeEvent(unsigned long event, void* callData)
{
	if (this->SubjectHelper)
	{
		return this->SubjectHelper->InvokeEvent(event, callData, this);
	}

	return 0;
}


