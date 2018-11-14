#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "strncpyTest.hpp"

int strncpyTest::launchTest()
{
	strncpyTest test;

	test.startTest("ft_strncpy(char *dst, const char *src, size_t len)");

	return test.errCount;
}

void strncpyTest::processTest()
{
	spStrVal paramTest = mkSpStrVal(nullptr, "src");
	spStrVal baseVal = mkSpStrVal(nullptr, "dst");
	spStrVal testVal = mkSpStrVal(nullptr, "dst");
	std::function<spAddrVal(spStrVal, spStrVal, spBaseVal<size_t>)> baseFunction =
		[&](spStrVal dst, spStrVal src, spBaseVal<size_t> len)
		{
			(void)dst;
			return mkSpAddrVal(strncpy(baseVal->getVal(), src->getVal(), len->getVal()), baseVal->getVal());
		};
	std::function<spAddrVal(spStrVal, spStrVal, spBaseVal<size_t>)> testFunction =
		[&](spStrVal dst, spStrVal src, spBaseVal<size_t> len)
		{
			(void)dst;
			return mkSpAddrVal(ft_strncpy(testVal->getVal(), src->getVal(), len->getVal()), testVal->getVal());
		};
	auto testValsFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spStrVal, spStrVal>(baseVal, testVal));};

	for (int i = 0; i <= 10; ++i)
	{
		char paramTestTab[] = "bonjour";
		char baseValTab[] = ".................................................";
		char testValTab[] = ".................................................";
		paramTest->setVal(paramTestTab);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(i, "len"));
	}
	for (int i = 0; i <= 3; ++i)
	{
		char paramTestTab[] = "";
		char baseValTab[] = ".................................................";
		char testValTab[] = ".................................................";
		paramTest->setVal(paramTestTab);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(i, "len"));
	}
	for (int i = 0; i <= 11; ++i)
	{
		char paramTestTab[] = "bon\0jour";
		char baseValTab[] = ".................................................";
		char testValTab[] = ".................................................";
		paramTest->setVal(paramTestTab);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(i, "len"));
	}
}
