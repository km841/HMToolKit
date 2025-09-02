#include "pch.h"
#include "hmCommonInformationKeyManager.h"
#include "hmInformationKey.h"

// 이게 왜 있는가?
// 옛날 컴파일러에선 정적 객체로 std::vector를 초기화하는데 문제가 생겼음
// 그래서 정상적으로 생성자를 호출할 수 있도록 wrapping 한 것
struct hmCommonInformationKeyManagerKeysType : public std::vector<hmInformationKey*>
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
	if (++hmCommonInformationKeyManagerCount == 1)
	{
		hmCommonInformationKeyManager::ClassInitialize();
	}
}

hmCommonInformationKeyManager::~hmCommonInformationKeyManager()
{
	if (--hmCommonInformationKeyManagerCount == 0)
	{
		hmCommonInformationKeyManager::ClassFinalize();
	}
}

void hmCommonInformationKeyManager::Register(hmInformationKey * key)
{
	hmCommonInformationKeyManagerKeys->push_back(key);
}

void hmCommonInformationKeyManager::ClassInitialize()
{
	// 이렇게 초기화하는 이유는 MacOS에서 static 객체의 생성자 로직이 꼬이는 경우가 있음
	// 일단 malloc으로 메모리 공간을 확보한 뒤에, placement new를 통해 생성
	void* keys = malloc(sizeof(hmCommonInformationKeyManagerKeysType));
	hmCommonInformationKeyManagerKeys = new (keys) hmCommonInformationKeyManagerKeysType;
}

void hmCommonInformationKeyManager::ClassFinalize()
{
	if (hmCommonInformationKeyManagerKeys)
	{
		// 전역 변수 내부의 key를 모두 삭제
		for (hmCommonInformationKeyManagerKeysType::iterator i =
			hmCommonInformationKeyManagerKeys->begin();
			i != hmCommonInformationKeyManagerKeys->end(); ++i)
		{
			hmInformationKey* key = *i;
			delete key;
		}

		// 이렇게 복잡하게 하는 이유는 Class Initialize에서 했던 것의 역순으로
		// 소멸자 직접 호출 -> free로 메모리 해제 해줌
		hmCommonInformationKeyManagerKeys->~hmCommonInformationKeyManagerKeysType();
		free(hmCommonInformationKeyManagerKeys);
		hmCommonInformationKeyManagerKeys = nullptr;
	}
}
