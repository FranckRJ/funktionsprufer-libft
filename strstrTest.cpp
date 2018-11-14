#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "strstrTest.hpp"

int strstrTest::launchTest()
{
	strstrTest test;

	test.startTest("ft_strstr(const char *haystack, const char *needle)");

	return test.errCount;
}

void strstrTest::processTest()
{
	spStrVal hayParamTest = mkSpStrVal(nullptr);
	spStrVal neeParamTest = mkSpStrVal(nullptr);
	std::function<spAddrVal(spStrVal, spStrVal)> baseFunction =
		[&](spStrVal haystack, spStrVal needle)
		{
			return mkSpAddrVal(strstr(haystack->getVal(), needle->getVal()), haystack->getVal());
		};
	std::function<spAddrVal(spStrVal, spStrVal)> testFunction =
		[&](spStrVal haystack, spStrVal needle)
		{
			return mkSpAddrVal(ft_strstr(haystack->getVal(), needle->getVal()), haystack->getVal());
		};

	{
		char hayTab[] = "bononojour salut";
		char neeTab[] = "bon";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
	}
	{
		char hayTab[] = "bononojour salut";
		char neeTab[] = "bonn";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
	}
	{
		char hayTab[] = "bononojour salut";
		char neeTab[] = "lol";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
	}
	{
		char hayTab[] = "bononojour salut";
		char neeTab[] = "jour";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
	}
	{
		char hayTab[] = "bononojour salut";
		char neeTab[] = "lut";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
	}
	{
		char hayTab[] = "bononojour salut";
		char neeTab[] = "lutt";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
	}
	{
		char hayTab[] = "bononojour salut";
		char neeTab[] = "onojour";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
	}
	{
		char hayTab[] = "beal beau beaucoup";
		char neeTab[] = "beau";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
	}
	{
		char hayTab[] = "salut";
		char neeTab[] = "";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
	}
	{
		char hayTab[] = "";
		char neeTab[] = "salut";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
	}
	{
		char hayTab[] = "";
		char neeTab[] = "";
		hayParamTest->setVal(hayTab);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
	}
}
