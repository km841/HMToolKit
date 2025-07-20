#include "pch.h"
#include "hmTimeStamp.h"

hmTimeStamp* hmTimeStamp::New()
{
	return new hmTimeStamp;
}

void hmTimeStamp::Delete()
{
	delete this;
}

void hmTimeStamp::Modified()
{
	static std::atomic<uint64_t> GlobalTimeStamp(0U);
	this->ModifiedTime = (hmMTimeType)++GlobalTimeStamp;
}