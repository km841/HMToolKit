#pragma once
#include "hmObjectBase.h"
#include "hmTimeStamp.h"
#include "hmSubjectHelper.h"

class hmObject
	: public hmObjectBase
{
public:
	hmObject();
	virtual ~hmObject();

public:
	hmMTimeType GetMTime();
	void Modified();
	hmTypeBool InvokeEvent(unsigned long event, void* callData);

protected:
	hmTimeStamp MTime;
	hmSubjectHelper* SubjectHelper;
	std::wstring ObjectName;
};

