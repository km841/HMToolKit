#include "pch.h"
#include "hmInformationKeyLookup.h"

hmInformationKeyLookup * hmInformationKeyLookup::New()
{
	return nullptr;
}

hmInformationKey * hmInformationKeyLookup::Find(const std::string & name, const std::string & location)
{
	KeyMap& keys = Keys();
	KeyMap::iterator it = keys.find(std::make_pair(location, name));
	return it != keys.end() ? it->second : nullptr;
}


void hmInformationKeyLookup::RegisterKey(hmInformationKey * key, const std::string & name, const std::string & location)
{
	hmInformationKeyLookup::Keys().insert(std::make_pair(std::make_pair(location, name), key));
}

hmInformationKeyLookup::KeyMap & hmInformationKeyLookup::Keys()
{
	static hmInformationKeyLookup::KeyMap keys;
	return keys;
}
