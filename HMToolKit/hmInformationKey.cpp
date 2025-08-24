#include "pch.h"
#include "hmInformationKey.h"
#include "hmInformationKeyLookup.h"

const char * hmInformationKey::GetName()
{
	return this->Name;
}

const char * hmInformationKey::GetLocation()
{
	return this->Location;
}

hmInformationKey::hmInformationKey(const char * name, const char * location)
{
	this->Name = nullptr;
	this->SetName(name);

	this->Location = nullptr;
	this->SetLocation(location);

	hmInformationKeyLookup::RegisterKey(this, name, location);
}

hmInformationKey::~hmInformationKey()
{
}
