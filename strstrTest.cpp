#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "strstrTest.hpp"

strstrTest::strstrTest()
{
#ifdef FT_STRSTR_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strstrTest::launchTest()
{
	strstrTest test;

	test.startTest("ft_strstr(const char *haystack, const char *needle)");

	return test.errCount;
}

void strstrTest::processTest()
{
#ifdef FT_STRSTR_EXIST
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

	if (!dontDoTestThatCrash)
	{
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
		char hayTab[] = "bonjour";
		hayParamTest->setVal(hayTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
		char hayTab2[] = "";
		hayParamTest->setVal(hayTab2);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
		char neeTab[] = "bon";
		hayParamTest->setVal(nullptr);
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
	}

	hayParamTest->setVal(nullptr);
	neeParamTest->setVal(nullptr);

	{
		char neeTab[] = "";
		neeParamTest->setVal(neeTab);
		testThisFun(baseFunction, testFunction, hayParamTest, neeParamTest);
	}

	hayParamTest->setVal(nullptr);
	neeParamTest->setVal(nullptr);

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
#endif
}
