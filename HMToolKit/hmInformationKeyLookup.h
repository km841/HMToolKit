#pragma once
#include "hmObject.h"

// Information Key�� ������ ã���ִ� ���� Ŭ����
// Ű �̸�(name)�� ���ǵ� Ŭ����(location)�� �˸� �����ϴ� informationKey�� ã�ƿ� �� ����
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
	// Identifier : Name/Location ��
	typedef std::pair<std::string, std::string> Identifier;
	typedef std::map<Identifier, hmInformationKey*> KeyMap;

	static KeyMap& Keys();

};

