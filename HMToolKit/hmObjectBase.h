#pragma once
class hmObjectBase
{

	virtual const char* GetClassNameInternal() const { return "hmObjectBase"; }

public:
	static hmObjectBase* New()
	{
		hmObjectBase* o = new hmObjectBase;
		//o->InitializeObjectBase();
		return o;
	}

	virtual void Delete() { /* UnRegister */ }

	const char* GetClassNameA() const;
	const char* GetClassNameW() const;

	void Print(std::ostream& os);

	static hmIdType GetNumberOfGenerationsFromBaseType(const char* name);
	virtual hmIdType GetNumberOfGenerationsFromBase(const char* name);

	static hmTypeBool IsTypeOf(const char* name);
	virtual hmTypeBool IsA(const char* name);

protected:
	// ReferenceCount / WeakPointer 등 멤버함수 초기화
	hmObjectBase() {}
	// Reference Count가 0보다 크면 에러 메시지
	virtual ~hmObjectBase() {}

};

