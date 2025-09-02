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

	// 구현은 모두 숨긴다!
	// Information은 key/value로 이루어진 메타데이터 저장소
	// hmObjectBase같은 내부 객체를 다루는 함수인데 일반 사용자가 사용할 필요가 없음
	// 일반 사용자는 Get / Set을 통해 데이터 접근
	void SetAsObjectBase(hmInformationKey* key, hmObjectBase* value);
	const hmObjectBase* GetAsObjectBase(const hmInformationKey* key) const;
	hmObjectBase* GetAsObjectBase(hmInformationKey* key);

	hmInformationInternals* Internal;

private:
	friend class hmInformationKeyToInformationFriendship;
	// 파이프라인이 어떤 단계에서 알고리즘(hmAlgorithm)에게 무엇을 요구하는가?
	hmInformationRequestKey* Request;
};

