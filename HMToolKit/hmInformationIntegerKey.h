#pragma once
#include "hmInformationKey.h"

class hmInformation;
class hmInformationIntegerKey :
	public hmInformationKey
{
public:
	hmTypeMacro(hmInformationIntegerKey, hmInformationKey);

	hmInformationIntegerKey(const char* name, const char* location);
	~hmInformationIntegerKey() override;

	static hmInformationIntegerKey* MakeKey(const char* name, const char* location)
	{
		return new hmInformationIntegerKey(name, location);
	}

	void Set(hmInformation* info, int);
	int Get(hmInformation* info);
};

