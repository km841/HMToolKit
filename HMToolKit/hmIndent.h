#pragma once


// vtk PrintSelf에서 주로 쓰임
// 들여쓰기를 어떻게 할 것인가?에 대한 툴 클래스

class hmIndent;
std::ostream& operator<<(std::ostream& os, const hmIndent& o);
class hmIndent
{
public:
	explicit hmIndent(int ind = 0) { this->Indent = ind; }

	void Delete() { delete this; }
	static hmIndent* New();

	hmIndent GetNextIndent();

	friend std::ostream& operator<<(std::ostream& os, const hmIndent& o);

protected:
	int Indent;
};

