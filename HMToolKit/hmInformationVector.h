#pragma once
#include "hmObject.h"

class hmInformation;
class hmInformationVectorInternals;

// 왜 자꾸 Internals로 빼둔 걸까?
// Internals가 아닌 클래스는 단순 래퍼의 역할만 하고, Internals에서는 세부 구현
// 이렇게 한 이유는 사용자는 원본 클래스를 사용하기 때문에 원본 클래스의 인터페이스는 유지
// 세부 구현만 Internals에서 구현하고 변경함으로써 인터페이스 유지

class hmInformationVector :
	public hmObject
{
public:
	hmTypeMacro(hmInformationVector, hmObject);
	static hmInformationVector* New();

	int GetNumberOfInformationObjects() { return this->NumberOfInformationObjects; }

protected:
	int NumberOfInformationObjects;
};

