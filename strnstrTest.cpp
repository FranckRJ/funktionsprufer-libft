#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "strnstrTest.hpp"

int strnstrTest::launchTest()
{
	strnstrTest test;

	test.startTest("ft_strnstr(const char *haystack, const char *needle, size_t len)");

	return test.errCount;
}

void strnstrTest::processTest()
{
	spStrVal hayParamTest = mkSpStrVal(nullptr);
	spStrVal neeParamTest = mkSpStrVal(nullptr);
	std::function<spAddrVal(spStrVal, spStrVal, spBaseVal<size_t>)> baseFunction =
		[&](spStrVal haystack, spStrVal needle, spBaseVal<size_t> len)
		{
			return mkSpAddrVal(strnstr(haystack->getVal(), needle->getVal(), len->getVal()), haystack->getVal());
		};
	std::function<spAddrVal(spStrVal, spStrVal, spBaseVal<size_t>)> testFunction =
		[&](spStrVal haystack, spStrVal needle, spBaseVal<size_t> len)
		{
			return mkSpAddrVal(ft_strnstr(haystack->getVal(), needle->getVal(), len->getVal()), haystack->getVal());
		};

	for (int i = 0; i <= 5; ++i)
	{
		char hayTab[] = "bononojour salut";
		char neeTab[] = "bon";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest, mkSpBaseVal<size_t>(i));
	}
	for (int i = 0; i <= 6; ++i)
	{
		char hayTab[] = "bononojour salut";
		char neeTab[] = "bonn";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest, mkSpBaseVal<size_t>(i));
	}
	for (int i = 0; i <= 12; ++i)
	{
		char hayTab[] = "bononojour salut";
		char neeTab[] = "onojour";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest, mkSpBaseVal<size_t>(i));
	}
	for (int i = 0; i <= 18; ++i)
	{
		char hayTab[] = "bononojour salut";
		char neeTab[] = "jour";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest, mkSpBaseVal<size_t>(i));
	}
	for (int i = 0; i <= 18; ++i)
	{
		char hayTab[] = "bononojour salut";
		char neeTab[] = "salut";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest, mkSpBaseVal<size_t>(i));
	}
	for (int i = 0; i <= 18; ++i)
	{
		char hayTab[] = "bononojour salut";
		char neeTab[] = "salutt";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest, mkSpBaseVal<size_t>(i));
	}
	for (int i = 0; i <= 18; ++i)
	{
		char hayTab[] = "bononojour salut";
		char neeTab[] = "lol";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest, mkSpBaseVal<size_t>(i));
	}
	for (int i = 0; i <= 25; ++i)
	{
		char hayTab[] = "salut ok salut ok salut";
		char neeTab[] = "ok";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest, mkSpBaseVal<size_t>(i));
	}
	for (int i = 0; i <= 5; ++i)
	{
		char hayTab[] = "slt";
		char neeTab[] = "";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest, mkSpBaseVal<size_t>(i));
	}
	for (int i = 0; i <= 5; ++i)
	{
		char hayTab[] = "slt";
		char neeTab[] = "slt";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest, mkSpBaseVal<size_t>(i));
	}
	for (int i = 0; i <= 5; ++i)
	{
		char hayTab[] = "";
		char neeTab[] = "slt";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest, mkSpBaseVal<size_t>(i));
	}
	for (int i = 0; i <= 2; ++i)
	{
		char hayTab[] = "";
		char neeTab[] = "";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest, mkSpBaseVal<size_t>(i));
	}
}
