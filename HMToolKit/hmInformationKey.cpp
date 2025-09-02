#include "pch.h"
#include "hmInformationKey.h"
#include "hmInformationKeyLookup.h"
#include "hmInformation.h"
#include "hmObjectBase.h"
#include "hmInformationInternals.h"




const char * hmInformationKey::GetName()
{
	return this->Name;
}

const char * hmInformationKey::GetLocation()
{
	return this->Location;
}

int hmInformationKey::Has(const hmInformation * info) const
{
	return this->GetAsObjectBase(info) ? 1 : 0;
}

const hmObjectBase * hmInformationKey::GetAsObjectBase(const hmInformation * info) const
{
	return hmInformationKeyToInformationFriendship::GetAsObjectBase(info, this);
}

void hmInformationKey::SetAsObjectBase(hmInformation * info, hmObjectBase * newvalue)
{
	hmInformationKeyToInformationFriendship::SetAsObjectBase(info, this, newvalue);
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

void hmInformationKeyToInformationFriendship::SetAsObjectBase(hmInformation * info, hmInformationKey * key, hmObjectBase * value)
{
	info->SetAsObjectBase(key, value);
}

const hmObjectBase * hmInformationKeyToInformationFriendship::GetAsObjectBase(const hmInformation * info, const hmInformationKey * key)
{
	// ÇØ¾ßÇÔ
	return nullptr;
}
