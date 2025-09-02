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
	vtkObject ���� �� �ݵ�� ȣ��Ǵ� �Լ�
	�޸� ���� ���� �ý���(vtkDebugLeaks)�� ȣ���
	��ü ���� �� ��ϵǰ� �Ҹ�� �� �����Ǿ, ���α׷� ���� �� ���⼭ �������� Ȯ��
	*/
	void InitializeObjectBase() {}

	void Print(std::ostream& os);

	static hmIdType GetNumberOfGenerationsFromBaseType(const char* name);
	virtual hmIdType GetNumberOfGenerationsFromBase(const char* name);

	static hmTypeBool IsTypeOf(const char* name);
	virtual hmTypeBool IsA(const char* name);

protected:
	// ReferenceCount / WeakPointer �� ����Լ� �ʱ�ȭ
	hmObjectBase() {}
	// Reference Count�� 0���� ũ�� ���� �޽���
	virtual ~hmObjectBase() {}

};

