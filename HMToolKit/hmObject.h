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

public:
	//Override
	virtual const char* GetClassNameInternal() const
	{
		return "hmObject";
	}

	static hmTypeBool IsTypeOf(const char* type)
	{
		if (!strcmp("hmObject", type))
		{
			return 1;
		}

		return 0;
	}

protected:
	hmTimeStamp MTime;
	hmSubjectHelper* SubjectHelper;
	std::wstring ObjectName;
};

