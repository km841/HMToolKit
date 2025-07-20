#include "pch.h"
#include "hmObserver.h"

hmObserver::hmObserver()
	: Command(nullptr)
	, Event(0)
	, Tag(0)
	, Next(nullptr)
	, Priority(0.0f)
{
}

hmObserver::~hmObserver()
{
}

void hmObserver::PrintSelf(std::wostream& os, hmIndent indent)
{
	//os << indent << L"vtkObserver (" << this << ")\n";
	//indent = indent.GetNextIndent();
	//os << indent << L"Event: " << this->Event << "\n";
	//os << indent << L"EventName: " << vtkCommand::GetStringFromEventId(this->Event) << "\n";
	//os << indent << L"Command: " << this->Command << "\n";
	//os << indent << L"Priority: " << this->Priority << "\n";
	//os << indent << L"Tag: " << this->Tag << "\n";
}
