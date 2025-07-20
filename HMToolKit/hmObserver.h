#pragma once
#include "hmIndent.h"

class hmCommand;
class hmObserver
{
public:
	hmObserver();
	~hmObserver();

	void PrintSelf(std::wostream& os, hmIndent indent);

	hmCommand* Command;
	unsigned long Event;
	unsigned long Tag;
	hmObserver* Next;
	float Priority;
};

