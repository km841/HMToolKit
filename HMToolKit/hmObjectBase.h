#pragma once
class hmObjectBase
{

	virtual const char* GetClassNameInternal() const { return "hmObjectBase"; }

public:
	static hmObjectBase* New()
	{
		hmObjectBase* o = new hmObjectBase;
		o->InitializeObjectBase();
		return o;
	}

	virtual void Delete() { /* UnRegister */ }

	const char* GetClassNameA() const;
	const char* GetClassNameW() const;

	/*
	#ifdef VTK_DEBUG_LEAKS
	vtkDebugLeaks::ConstructClass(this);
	#endif // VTK_DEBUG_LEAKS
	vtkObject 생성 시 반드시 호출되는 함수
	메모리 누수 추적 시스템(vtkDebugLeaks)가 호출됨
	객체 생성 시 등록되고 소멸될 때 삭제되어서, 프로그램 종료 시 여기서 누수여부 확인
	*/
	void InitializeObjectBase() {}

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

