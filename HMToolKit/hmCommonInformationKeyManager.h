#pragma once

// Information Ű�� �������� �����Ǳ� ������
// �����ֱ⸦ ȿ�������� �����ϱ� ���ؼ� Key�� ������ �� �����θ� KeyManager�� �����

/* ::Example::

VTK_ABI_NAMESPACE_BEGIN
vtkInformationIntegerKey::vtkInformationIntegerKey(const char* name, const char* location)
  : vtkInformationKey(name, location)
{
  vtkCommonInformationKeyManager::Register(this);
}

*/

class hmInformationKey;

class hmCommonInformationKeyManager
{
public:
	hmCommonInformationKeyManager();
	~hmCommonInformationKeyManager();

	static void Register(hmInformationKey* key);

private:
	// ���翬����, ���Կ����� ����
	hmCommonInformationKeyManager(const hmCommonInformationKeyManager&) = delete;
	hmCommonInformationKeyManager& operator=(const hmCommonInformationKeyManager&) = delete;

	static void ClassInitialize();
	static void ClassFinalize();

	static hmCommonInformationKeyManager hmCommonInformationKeyManagerInstance;
};

