#include "pch.h"
#include "hmIndent.h"

// ������ �ð��� �迭 ũ�⸦ �˾ƾ� �ϹǷ� constexpr��
// constexpr�� ����� �迭 ���� �� ������ ��� ����
constexpr int HM_STD_INDENT = 2;
constexpr int HM_NUMBER_OF_BLANKS = 40;

static const char blanks[HM_NUMBER_OF_BLANKS + 1] = "                                        ";

hmIndent * hmIndent::New()
{
	return new hmIndent;
}

hmIndent hmIndent::GetNextIndent()
{
	int indent = this->Indent + HM_STD_INDENT;
	if (indent > HM_NUMBER_OF_BLANKS)
	{
		indent = HM_NUMBER_OF_BLANKS;
	}

	return hmIndent(indent);
}

std::ostream & operator<<(std::ostream & os, const hmIndent & ind)
{
	os << blanks + (HM_NUMBER_OF_BLANKS - ind.Indent);
	return os;
}
