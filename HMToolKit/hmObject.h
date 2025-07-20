#pragma once
#include "hmTimeStamp.h"

class hmObject
{
public:
	hmObject();
	virtual ~hmObject();


public:
	// 레퍼런스카운트
	void Register();
	void UnRegister();

	int GetReferenceCount();

	virtual std::wstring GetClassName() const;
	virtual bool IsA(const std::wstring& _wszTypeName) const;

protected:
	int ReferenceCount;
	hmTimeStamp MTime;
};

