#pragma once


// vtk PrintSelf���� �ַ� ����
// �鿩���⸦ ��� �� ���ΰ�?�� ���� �� Ŭ����

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

