#pragma once
#include "hmObject.h"
class hmInformationIntegerKey;
class hmInformationKey;
class hmInformationInternals;
class hmInformationRequestKey;
class hmInformation :
	public hmObject
{
public:
	static hmInformation* New();
	hmTypeMacro(hmInformation, hmObject);

	virtual int Has(const hmInformationKey* key) const;

	void Modified() override;

protected:
	hmInformation();
	~hmInformation() override;

	// ������ ��� �����!
	// Information�� key/value�� �̷���� ��Ÿ������ �����
	// hmObjectBase���� ���� ��ü�� �ٷ�� �Լ��ε� �Ϲ� ����ڰ� ����� �ʿ䰡 ����
	// �Ϲ� ����ڴ� Get / Set�� ���� ������ ����
	void SetAsObjectBase(hmInformationKey* key, hmObjectBase* value);
	const hmObjectBase* GetAsObjectBase(const hmInformationKey* key) const;
	hmObjectBase* GetAsObjectBase(hmInformationKey* key);

	hmInformationInternals* Internal;

private:
	friend class hmInformationKeyToInformationFriendship;
	// ������������ � �ܰ迡�� �˰���(hmAlgorithm)���� ������ �䱸�ϴ°�?
	hmInformationRequestKey* Request;
};

