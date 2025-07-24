#include "pch.h"
#include "hmCommand.h"

const char* hmCommand::GetStringFromEventId(unsigned int event)
{
	return nullptr;
}

unsigned int hmCommand::GetEventIdFromString(const char* event)
{
	return 0;
}

bool hmCommand::EventHasData(unsigned long event)
{
	return false;
}

hmCommand::hmCommand()
	: AbortFlag(0)
	, PassiveObserver(0)
{
}
