#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "strcatTest.hpp"

strcatTest::strcatTest()
{
#ifdef FT_STRCAT_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strcatTest::launchTest()
{
	strcatTest test;

	test.startTest("ft_strcat(char *s1, const char *s2)");

	return test.errCount;
}

void strcatTest::processTest()
{
#ifdef FT_STRCAT_EXIST
	spStrVal paramTest = mkSpStrVal(nullptr, "s2");
	spStrVal baseVal = mkSpStrVal(nullptr, "s1");
	spStrVal testVal = mkSpStrVal(nullptr, "s1");
	std::function<spAddrVal(spStrVal, spStrVal)> baseFunction =
		[&](spStrVal dst, spStrVal src)
		{
			(void)dst;
			return mkSpAddrVal(strcat(baseVal->getVal(), src->getVal()), baseVal->getVal());
		};
	std::function<spAddrVal(spStrVal, spStrVal)> testFunction =
		[&](spStrVal dst, spStrVal src)
		{
			(void)dst;
			return mkSpAddrVal(ft_strcat(testVal->getVal(), src->getVal()), testVal->getVal());
		};
	auto testValsFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spStrVal, spStrVal>(baseVal, testVal));};

	if (!dontDoTestThatCrash)
	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest);
		char paramTestTab[] = "bonjour";
		paramTest->setVal(paramTestTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest);
		char baseValTab[] = ".............";
		char testValTab[] = ".............";
		paramTest->setVal(nullptr);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest);
	}

	baseVal->setVal(nullptr);
	testVal->setVal(nullptr);

	{
		char paramTestTab[] = "bonjour";
		char baseValTab[15] = "lol";
		char testValTab[15] = "lol";
		paramTest->setVal(paramTestTab);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest);
	}
	{
		char paramTestTab[] = "bonjour";
		char baseValTab[15] = "";
		char testValTab[15] = "";
		paramTest->setVal(paramTestTab);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest);
	}
	{
		char paramTestTab[] = "";
		char baseValTab[15] = "lol";
		char testValTab[15] = "lol";
		paramTest->setVal(paramTestTab);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest);
	}
	{
		char paramTestTab[] = "";
		char baseValTab[15] = "";
		char testValTab[15] = "";
		paramTest->setVal(paramTestTab);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest);
	}
#endif
}
