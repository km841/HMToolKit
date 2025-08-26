#include "pch.h"
#include "hmCommonInformationKeyManager.h"

// 이게 왜 있는가?
// 옛날 컴파일러에선 정적 객체로 std::vector를 초기화하는데 문제가 생겼음
// 그래서 정상적으로 생성자를 호출할 수 있도록 wrapping 한 것
struct hmCommonInformationKeyManagerKeysType : public std::vector<hmInformationKey>
{
	typedef std::vector<hmInformationKey*> Superclass;
	typedef Superclass::iterator iterator;
};

// 내부에서 전역 상태를 추적하기 위한 변수
// 인스턴스 몇 개가 살아 있는지 카운트함
static unsigned int hmCommonInformationKeyManagerCount;

// hmInformationKey를 전역적으로 저장하는 컨테이터
static hmCommonInformationKeyManagerKeysType* hmCommonInformationKeyManagerKeys;


hmCommonInformationKeyManager::hmCommonInformationKeyManager()
{
}

hmCommonInformationKeyManager::~hmCommonInformationKeyManager()
{
}

void hmCommonInformationKeyManager::Register(hmInformationKey * key)
{
}

void hmCommonInformationKeyManager::ClassInitialize()
{
}

void hmCommonInformationKeyManager::ClassFinalize()
{
}
