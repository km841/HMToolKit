#pragma once
class hmObject;
class hmCommand
{
public:
	virtual void Execute(hmObject* caller, unsigned long eventId, void* callData) = 0;

	static const char* GetStringFromEventId(unsigned int event);
	static unsigned int GetEventIdFromString(const char* event);

	static bool EventHasData(unsigned long event);

	void SetAbortFlag(hmTypeBool f) { this->AbortFlag = f; }
	hmTypeBool GetAbortFlag() { return this->AbortFlag; }

	void AbortFlagOn() { this->SetAbortFlag(1); }
	void AbortFlagOff() { this->SetAbortFlag(0); }

	void SetPassiveObserver(hmTypeBool f) { this->PassiveObserver = f; }
	hmTypeBool GetPassiveObserver() { return this->PassiveObserver; }

	void PassiveObserverOn() { return this->SetPassiveObserver(1); }
	void PassiveObserverOff() { return this->SetPassiveObserver(0); }

protected:
	hmCommand();
	virtual ~hmCommand() = default;

protected:
	hmTypeBool AbortFlag;
	hmTypeBool PassiveObserver;

	
};

