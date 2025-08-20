#pragma once
#include "pch.h"

// NewInstance�� thisClass ��ü�� �ƴ϶� ���� Ŭ�����ε� ��ȯ�� �� �ְ� �ص�
// NewInstance�� �߻� Ŭ������ �� �ֱ� ������ NewInstance�� ��ü�� ���� ���� ���� �� ����
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

// vtkTypeMacro�� ������, �߻� Ŭ������ �°� ������ ��ũ��
#define hmAbstractTypeMacro(thisClass, superclass)                                                \
  hmAbstractTypeMacroWithNewInstanceType(thisClass, superclass, thisClass, #thisClass)            \
                                                                                                   \
public:

// � Ŭ������ ���� Ŭ��������, ���� Ŭ�������� Ȯ���ϱ� ���� ��ũ��
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

// vtkTypeMacro ��� vtkObjectBase�� �������� ���� Ŭ������ �� ����ؾ� �ϴ� ��ũ��

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