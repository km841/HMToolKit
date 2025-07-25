#pragma once
class hmObserver;
class hmCommand;
class hmObject;

class hmSubjectHelper
{
public:
	hmSubjectHelper();
	~hmSubjectHelper();

	unsigned long AddObserver(unsigned long event, hmCommand* cmd, float p);
	void RemoveObserver(unsigned long tag);
	void RemoveObservers(unsigned long event);

	hmTypeBool InvokeEvent(unsigned long event, void* callData, hmObject* self);


	std::vector<bool> ListModified;
	hmCommand* Focus1;
	hmCommand* Focus2;

protected:
	hmObserver* Start;
	unsigned long Count;
};

