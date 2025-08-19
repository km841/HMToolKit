#pragma once
#include "hmObject.h"
class hmExecutive :
    public hmObject
{
protected:
	const char* GetClassNameInternal() const override
	{
		return "hmExecutive";
	}


public:
	typedef hmObject Superclass;
	static hmTypeBool IsTypeOf(const char* type)
	{
		if (!strcmp("hmExecutive", type))
		{
			return 1;
		}

		return hmObject::IsTypeOf(type);
	}
};

