#pragma once
#include "hmObject.h"
class hmInformation :
	public hmObject
{
public:
	static hmInformation* New();
	hmTypeMacro(hmInformation, hmObject);

	void Modified() override;
};

