#pragma once
#include "hmObjectBase.h"
#include "hmTimeStamp.h"
#include "hmSubjectHelper.h"

class hmObject
	: public hmObjectBase
{
public:
	hmBaseTypeMacro(hmObject, hmObjectBase);

	hmObject();
	virtual ~hmObject();

public:
	virtual hmMTimeType GetMTime();
	virtual void Modified();

	hmTypeBool InvokeEvent(unsigned long event, void* callData);

protected:
	hmTimeStamp MTime;
	hmSubjectHelper* SubjectHelper;
	std::wstring ObjectName;
};

