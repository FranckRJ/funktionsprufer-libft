#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "strdupTest.hpp"

strdupTest::strdupTest()
{
#ifdef FT_STRDUP_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strdupTest::launchTest()
{
	strdupTest test;

	test.startTest("ft_strdup(const char *s1)");

	return test.errCount;
}

void strdupTest::processTest()
{
#ifdef FT_STRDUP_EXIST
	spStrVal baseRet = mkSpStrVal(nullptr, "", true);
	spStrVal testRet = mkSpStrVal(nullptr, "", true);
	spStrVal valToTest = mkSpStrVal(nullptr);
	std::function<spStrVal(spStrVal)> baseFunction =
		[&](spStrVal s1)
		{
			baseRet->setVal(strdup(s1->getVal()));
			return baseRet;
		};
	std::function<spStrVal(spStrVal)> testFunction =
		[&](spStrVal s1)
		{
			testRet->setVal(ft_strdup(s1->getVal()));
			return testRet;
		};
	auto testValsFun =
		[&](bool printRes)
		{
			return compareVals(printRes, std::pair<spBaseVal<bool>, spBaseVal<bool>>(
						mkSpBaseVal<bool>(baseRet->getVal() != valToTest->getVal(), "ret != s1"),
						mkSpBaseVal<bool>(testRet->getVal() != valToTest->getVal(), "ret != s1")));
		};

	if (!dontDoTestThatCrash)
	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, valToTest);
	}

	{
		char testVal[] = "bonjour";
		valToTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, valToTest);
	}
	{
		char testVal[] = "";
		valToTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, valToTest);
	}
	{
		char testVal[] = "bon\0jour";
		valToTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, valToTest);
	}
#endif
}
