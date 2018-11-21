#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "strncpyTest.hpp"

strncpyTest::strncpyTest()
{
#ifdef FT_STRNCPY_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strncpyTest::launchTest()
{
	strncpyTest test;

	test.startTest("ft_strncpy(char *dst, const char *src, size_t len)");

	return test.errCount;
}

void strncpyTest::processTest()
{
#ifdef FT_STRNCPY_EXIST
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

	if (!dontDoTestThatCrash)
	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(5, "len"));
		char paramTestTab[] = "bonjour";
		paramTest->setVal(paramTestTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(5, "len"));
		char baseValTab[] = ".............";
		char testValTab[] = ".............";
		paramTest->setVal(nullptr);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(5, "len"));
	}

	baseVal->setVal(nullptr);
	testVal->setVal(nullptr);

	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(0, "len"));
		char paramTestTab[] = "bonjour";
		paramTest->setVal(paramTestTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(0, "len"));
		char baseValTab[] = ".............";
		char testValTab[] = ".............";
		paramTest->setVal(nullptr);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(0, "len"));
	}

	baseVal->setVal(nullptr);
	testVal->setVal(nullptr);

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
#endif
}
