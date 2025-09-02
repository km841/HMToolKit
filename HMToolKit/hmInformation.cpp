#include "pch.h"
#include "hmInformation.h"
#include "hmInformationKey.h"
#include "hmInformationInternals.h"

hmStandardNewMacro(hmInformation);

int hmInformation::Has(const hmInformationKey * key) const
{
	return key->Has(this) ? 1 : 0;
}

void hmInformation::Modified()
{
	this->Superclass::Modified();
}

hmInformation::hmInformation()
{
	this->Internal = new hmInformationInternals;

	this->Request = nullptr;
}

hmInformation::~hmInformation()
{
}

void hmInformation::SetAsObjectBase(hmInformationKey * key, hmObjectBase * value)
{
}

const hmObjectBase * hmInformation::GetAsObjectBase(const hmInformationKey * key) const
{
	return nullptr;
}

hmObjectBase * hmInformation::GetAsObjectBase(hmInformationKey * key)
{
	return nullptr;
}
