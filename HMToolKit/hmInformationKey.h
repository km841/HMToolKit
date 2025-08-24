#pragma once
#include "hmObjectBase.h"

// 이런 클래스는 왜 존재하는가?
// vtkInformation 시스템 개요
// vtk 파이프라인에는 수많은 요청과 메타데이터를 주고받는다
// 1. 요청할 범위
// 2. 데이터의 전체 크기
// 3. 데이터의 특정 부분
// 4. 병렬처리 시 조각 부분

// 이런 정보들은 vtkInformation에 Dictionary key-value 형태로 저장되어 있음
// 여기서 key가 바로 hmInformationKey임
// 여기서 상속받는 hmInformationIntegerKey의 상속 이유는
// 그냥 string이나 int를 사용할 경우 들어온 키를 어떤 타입으로 해석할 것인지가 모호해짐
// 그래서 타입 안정성을 확보하기 위해 InformationIntegerKey와 같은 별도 객체를 사용
class hmInformationKey :
	public hmObjectBase
{
public:
	hmBaseTypeMacro(hmInformationKey, hmObjectBase);
	// 구현해야함

	// 키의 이름을 문자열로 리턴
	const char* GetName();

	// 키가 정의된 클래스 이름을 반환
	// 같은 키라도 어떤 클래스에서 정의되었는지를 알 수 있음
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

