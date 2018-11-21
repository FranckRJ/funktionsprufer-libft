#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "strncatTest.hpp"

strncatTest::strncatTest()
{
#ifdef FT_STRNCAT_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strncatTest::launchTest()
{
	strncatTest test;

	test.startTest("ft_strncat(char *s1, const char *s2, size_t n)");

	return test.errCount;
}

void strncatTest::processTest()
{
#ifdef FT_STRNCAT_EXIST
	spStrVal paramTest = mkSpStrVal(nullptr, "s2");
	spStrVal baseVal = mkSpStrVal(nullptr, "s1");
	spStrVal testVal = mkSpStrVal(nullptr, "s1");
	std::function<spAddrVal(spStrVal, spStrVal, spBaseVal<size_t>)> baseFunction =
		[&](spStrVal dst, spStrVal src, spBaseVal<size_t> n)
		{
			(void)dst;
			return mkSpAddrVal(strncat(baseVal->getVal(), src->getVal(), n->getVal()), baseVal->getVal());
		};
	std::function<spAddrVal(spStrVal, spStrVal, spBaseVal<size_t>)> testFunction =
		[&](spStrVal dst, spStrVal src, spBaseVal<size_t> n)
		{
			(void)dst;
			return mkSpAddrVal(ft_strncat(testVal->getVal(), src->getVal(), n->getVal()), testVal->getVal());
		};
	auto testValsFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spStrVal, spStrVal>(baseVal, testVal));};

	if (!dontDoTestThatCrash)
	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(0, "n"));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(5, "n"));
		char paramTestTab[] = "bonjour";
		paramTest->setVal(paramTestTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(0, "n"));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(5, "n"));
		char baseValTab[] = ".............";
		char testValTab[] = ".............";
		paramTest->setVal(nullptr);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(5, "n"));
	}

	baseVal->setVal(nullptr);
	testVal->setVal(nullptr);

	{
		char baseValTab[] = ".............";
		char testValTab[] = ".............";
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(0, "n"));
	}

	baseVal->setVal(nullptr);
	testVal->setVal(nullptr);

	for (int i = 0; i <= 10; ++i)
	{
		char paramTestTab[] = "bonjour";
		char baseValTab[15] = "lol";
		char testValTab[15] = "lol";
		paramTest->setVal(paramTestTab);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(i, "n"));
	}
	for (int i = 0; i <= 10; ++i)
	{
		char paramTestTab[] = "bonjour";
		char baseValTab[15] = "";
		char testValTab[15] = "";
		paramTest->setVal(paramTestTab);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(i, "n"));
	}
	for (int i = 0; i <= 3; ++i)
	{
		char paramTestTab[] = "";
		char baseValTab[15] = "lol";
		char testValTab[15] = "lol";
		paramTest->setVal(paramTestTab);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(i, "n"));
	}
	for (int i = 0; i <= 3; ++i)
	{
		char paramTestTab[] = "";
		char baseValTab[15] = "";
		char testValTab[15] = "";
		paramTest->setVal(paramTestTab);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest, mkSpBaseVal<size_t>(i, "n"));
	}
#endif
}
