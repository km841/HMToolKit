#pragma once
class hmObjectBase
{
public:
	static hmTypeBool IsTypeOf(const char* name);
	virtual hmTypeBool IsA(const char* name);

};

