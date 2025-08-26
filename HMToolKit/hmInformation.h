#pragma once
#include "hmObject.h"
class hmInformationIntegerKey;
class hmInformation :
	public hmObject
{
public:
	static hmInformation* New();
	hmTypeMacro(hmInformation, hmObject);



	void Modified() override;
};

