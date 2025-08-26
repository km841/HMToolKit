#pragma once

// Information 키가 전역에서 관리되기 때문에
// 생명주기를 효율적으로 관리하기 위해서 Key가 생성될 때 스스로를 KeyManager에 등록함

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
	// 복사연산자, 대입연산자 삭제
	hmCommonInformationKeyManager(const hmCommonInformationKeyManager&) = delete;
	hmCommonInformationKeyManager& operator=(const hmCommonInformationKeyManager&) = delete;

	static void ClassInitialize();
	static void ClassFinalize();

	static hmCommonInformationKeyManager hmCommonInformationKeyManagerInstance;
};

