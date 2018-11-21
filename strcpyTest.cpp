#include <functional>

#include "libft.h"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "strcpyTest.hpp"

strcpyTest::strcpyTest()
{
#ifdef FT_STRCPY_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strcpyTest::launchTest()
{
	strcpyTest test;

	test.startTest("ft_strcpy(char *dst, const char *src)");

	return test.errCount;
}

void strcpyTest::processTest()
{
#ifdef FT_STRCPY_EXIST
	spStrVal paramTest = mkSpStrVal(nullptr, "src");
	spStrVal baseVal = mkSpStrVal(nullptr, "dst");
	spStrVal testVal = mkSpStrVal(nullptr, "dst");
	std::function<spAddrVal(spStrVal, spStrVal)> baseFunction =
		[&](spStrVal dst, spStrVal src)
		{
			(void)dst;
			return mkSpAddrVal(strcpy(baseVal->getVal(), src->getVal()), baseVal->getVal());
		};
	std::function<spAddrVal(spStrVal, spStrVal)> testFunction =
		[&](spStrVal dst, spStrVal src)
		{
			(void)dst;
			return mkSpAddrVal(ft_strcpy(testVal->getVal(), src->getVal()), testVal->getVal());
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
		char baseValTab[15];
		char testValTab[15];
		paramTest->setVal(paramTestTab);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest);
	}
	{
		char paramTestTab[] = "";
		char baseValTab[15];
		char testValTab[15];
		paramTest->setVal(paramTestTab);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest);
	}
	{
		char paramTestTab[] = "bon\0jour";
		char baseValTab[15];
		char testValTab[15];
		paramTest->setVal(paramTestTab);
		baseVal->setVal(baseValTab);
		testVal->setVal(testValTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, paramTest);
	}
#endif
}
