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

	static hmIdType GetNumberOfGenerationsFromBaseType(const char* name);
	virtual hmIdType GetNumberOfGenerationsFromBase(const char* name);

	static hmTypeBool IsTypeOf(const char* name);
	virtual hmTypeBool IsA(const char* name);

};

