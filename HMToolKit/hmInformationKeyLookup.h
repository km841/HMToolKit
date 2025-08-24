#pragma once
#include "hmObject.h"

// Information Key를 빠르게 찾아주는 헬퍼 클래스
// 키 이름(name)과 정의된 클래스(location)을 알면 대응하는 informationKey를 찾아올 수 있음
class hmInformationKey;
class hmInformationKeyLookup :
	public hmObject
{
public:
	static hmInformationKeyLookup* New();
	hmTypeMacro(hmInformationKeyLookup, hmObject);

	static hmInformationKey* Find(const std::string& name, const std::string& location);

protected:
	hmInformationKeyLookup() = default;
	~hmInformationKeyLookup() = default;

	friend class hmInformationKey;

	static void RegisterKey(hmInformationKey* key, const std::string& name, const std::string& location);

private:
	// Identifier : Name/Location 쌍
	typedef std::pair<std::string, std::string> Identifier;
	typedef std::map<Identifier, hmInformationKey*> KeyMap;

	static KeyMap& Keys();

};

