#pragma once
#include "hmObjectBase.h"

// �̷� Ŭ������ �� �����ϴ°�?
// vtkInformation �ý��� ����
// vtk ���������ο��� ������ ��û�� ��Ÿ�����͸� �ְ�޴´�
// 1. ��û�� ����
// 2. �������� ��ü ũ��
// 3. �������� Ư�� �κ�
// 4. ����ó�� �� ���� �κ�

// �̷� �������� vtkInformation�� Dictionary key-value ���·� ����Ǿ� ����
// ���⼭ key�� �ٷ� hmInformationKey��
// ���⼭ ��ӹ޴� hmInformationIntegerKey�� ��� ������
// �׳� string�̳� int�� ����� ��� ���� Ű�� � Ÿ������ �ؼ��� �������� ��ȣ����
// �׷��� Ÿ�� �������� Ȯ���ϱ� ���� InformationIntegerKey�� ���� ���� ��ü�� ���
class hmInformationKey :
	public hmObjectBase
{
public:
	hmBaseTypeMacro(hmInformationKey, hmObjectBase);
	// �����ؾ���

	// Ű�� �̸��� ���ڿ��� ����
	const char* GetName();

	// Ű�� ���ǵ� Ŭ���� �̸��� ��ȯ
	// ���� Ű�� � Ŭ�������� ���ǵǾ������� �� �� ����
	const char* GetLocation();

	hmInformationKey(const char* name, const char* location);
	~hmInformationKey() override;

protected:
	char* Name;
	char* Location;

#define hmInformationKeySetStringMacro(name)                                                      \
  virtual void Set##name(const char* _arg)                                                         \
  {                                                                                                \
    if (this->name == nullptr && _arg == nullptr)                                                  \
    {                                                                                              \
      return;                                                                                      \
    }                                                                                              \
    if (this->name && _arg && (!strcmp(this->name, _arg)))                                         \
    {                                                                                              \
      return;                                                                                      \
    }                                                                                              \
    delete[] this->name;                                                                           \
    if (_arg)                                                                                      \
    {                                                                                              \
      size_t n = strlen(_arg) + 1;                                                                 \
      char* cp1 = new char[n];                                                                     \
      const char* cp2 = (_arg);                                                                    \
      this->name = cp1;                                                                            \
      do                                                                                           \
      {                                                                                            \
        *cp1++ = *cp2++;                                                                           \
      } while (--n);                                                                               \
    }                                                                                              \
    else                                                                                           \
    {                                                                                              \
      this->name = nullptr;                                                                        \
    }                                                                                              \
  }

	hmInformationKeySetStringMacro(Name);
	hmInformationKeySetStringMacro(Location);
};

