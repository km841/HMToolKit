#include "pch.h"
#include "hmCommonInformationKeyManager.h"
#include "hmInformationKey.h"

// �̰� �� �ִ°�?
// ���� �����Ϸ����� ���� ��ü�� std::vector�� �ʱ�ȭ�ϴµ� ������ ������
// �׷��� ���������� �����ڸ� ȣ���� �� �ֵ��� wrapping �� ��
struct hmCommonInformationKeyManagerKeysType : public std::vector<hmInformationKey*>
{
	typedef std::vector<hmInformationKey*> Superclass;
	typedef Superclass::iterator iterator;
};

// ���ο��� ���� ���¸� �����ϱ� ���� ����
// �ν��Ͻ� �� ���� ��� �ִ��� ī��Ʈ��
static unsigned int hmCommonInformationKeyManagerCount;

// hmInformationKey�� ���������� �����ϴ� ��������
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
	// �̷��� �ʱ�ȭ�ϴ� ������ MacOS���� static ��ü�� ������ ������ ���̴� ��찡 ����
	// �ϴ� malloc���� �޸� ������ Ȯ���� �ڿ�, placement new�� ���� ����
	void* keys = malloc(sizeof(hmCommonInformationKeyManagerKeysType));
	hmCommonInformationKeyManagerKeys = new (keys) hmCommonInformationKeyManagerKeysType;
}

void hmCommonInformationKeyManager::ClassFinalize()
{
	if (hmCommonInformationKeyManagerKeys)
	{
		// ���� ���� ������ key�� ��� ����
		for (hmCommonInformationKeyManagerKeysType::iterator i =
			hmCommonInformationKeyManagerKeys->begin();
			i != hmCommonInformationKeyManagerKeys->end(); ++i)
		{
			hmInformationKey* key = *i;
			delete key;
		}

		// �̷��� �����ϰ� �ϴ� ������ Class Initialize���� �ߴ� ���� ��������
		// �Ҹ��� ���� ȣ�� -> free�� �޸� ���� ����
		hmCommonInformationKeyManagerKeys->~hmCommonInformationKeyManagerKeysType();
		free(hmCommonInformationKeyManagerKeys);
		hmCommonInformationKeyManagerKeys = nullptr;
	}
}
