#include "pch.h"
#include "hmIndent.h"

// 컴파일 시간에 배열 크기를 알아야 하므로 constexpr씀
// constexpr로 만들면 배열 선언 시 개수로 사용 가능
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
