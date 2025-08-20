#pragma once
#include "pch.h"

// NewInstance가 thisClass 자체가 아니라 상위 클래스로도 반환될 수 있게 해둠
// NewInstance가 추상 클래스일 수 있기 때문에 NewInstance로 객체를 만들 수가 없을 수 있음
#define hmAbstractTypeMacroWithNewInstanceType(                                                   \
  thisClass, superclass, instanceType, thisClassName)                                              \
protected:                                                                                         \
  const char* GetClassNameInternal() const override                                                \
  {                                                                                                \
    return thisClassName;                                                                          \
  }                                                                                                \
                                                                                                   \
public:                                                                                            \
  typedef superclass Superclass;                                                                   \
  static hmTypeBool IsTypeOf(const char* type)                                                    \
  {                                                                                                \
    if (!strcmp(thisClassName, type))                                                              \
    {                                                                                              \
      return 1;                                                                                    \
    }                                                                                              \
    return superclass::IsTypeOf(type);                                                             \
  }                                                                                                \
  hmTypeBool IsA(const char* type) override                                                       \
  {                                                                                                \
    return this->thisClass::IsTypeOf(type);                                                        \
  }                                                                                                \
  static thisClass* SafeDownCast(hmObjectBase* o)                                                 \
  {                                                                                                \
    if (o && o->IsA(thisClassName))                                                                \
    {                                                                                              \
      return static_cast<thisClass*>(o);                                                           \
    }                                                                                              \
    return nullptr;                                                                                \
  }                                                                                                \
  instanceType* NewInstance() const                                                \
  {                                                                                                \
    return instanceType::SafeDownCast(this->NewInstanceInternal());                                \
  }                                                                                                \
  static hmIdType GetNumberOfGenerationsFromBaseType(const char* type)                            \
  {                                                                                                \
    if (!strcmp(thisClassName, type))                                                              \
    {                                                                                              \
      return 0;                                                                                    \
    }                                                                                              \
    return 1 + superclass::GetNumberOfGenerationsFromBaseType(type);                               \
  }                                                                                                \
  hmIdType GetNumberOfGenerationsFromBase(const char* type) override                              \
  {                                                                                                \
    return this->thisClass::GetNumberOfGenerationsFromBaseType(type);                              \
  }

// vtkTypeMacro와 같지만, 추상 클래스에 맞게 변형된 매크로
#define hmAbstractTypeMacro(thisClass, superclass)                                                \
  hmAbstractTypeMacroWithNewInstanceType(thisClass, superclass, thisClass, #thisClass)            \
                                                                                                   \
public:

// 어떤 클래스의 하위 클래스인지, 같은 클래스인지 확인하기 위한 매크로
#define hmTypeMacro(thisClass, superclass)                                                        \
  hmAbstractTypeMacro(thisClass, superclass)                                                      \
                                                                                                   \
protected:                                                                                         \
  hmObjectBase* NewInstanceInternal() const                                              \
  {                                                                                                \
    return thisClass::New();                                                                       \
  }                                                                                                \
                                                                                                   \
public:

// vtkTypeMacro 대신 vtkObjectBase의 직접적인 하위 클래스일 때 사용해야 하는 매크로

#define hmBaseTypeMacro(thisClass, superclass)                                                    \
  hmAbstractTypeMacro(thisClass, superclass)                                                      \
                                                                                                   \
protected:                                                                                         \
  virtual hmObjectBase* NewInstanceInternal() const                                               \
  {                                                                                                \
    return thisClass::New();                                                                       \
  }                                                                                                \
                                                                                                   \
public: