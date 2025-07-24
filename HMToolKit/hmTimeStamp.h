#pragma once

class hmTimeStamp
{
public:
	hmTimeStamp() { ModifiedTime = 0; };
	static hmTimeStamp* New();
	void Delete();

	hmMTimeType GetMTime() const { return this->ModifiedTime; }

	bool operator>(hmTimeStamp& ts) { return (this->ModifiedTime > ts.ModifiedTime); }
	bool operator<(hmTimeStamp& ts) { return (this->ModifiedTime < ts.ModifiedTime); }

	operator hmMTimeType() const { return ModifiedTime; }

	void Modified();
	
private:
	hmMTimeType ModifiedTime;

};

