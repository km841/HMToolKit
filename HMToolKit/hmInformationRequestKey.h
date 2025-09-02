#pragma once
#include "hmInformationKey.h"
class hmInformationRequestKey :
	public hmInformationKey
{
public:
	hmTypeMacro(hmInformationRequestKey, hmInformationKey);

	hmInformationRequestKey(const char* name, const char* location);
	~hmInformationRequestKey() override;
};

