#include "pch.h"
#include "hmCommonInformationKeyManager.h"

// �̰� �� �ִ°�?
// ���� �����Ϸ����� ���� ��ü�� std::vector�� �ʱ�ȭ�ϴµ� ������ ������
// �׷��� ���������� �����ڸ� ȣ���� �� �ֵ��� wrapping �� ��
struct hmCommonInformationKeyManagerKeysType : public std::vector<hmInformationKey>
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
