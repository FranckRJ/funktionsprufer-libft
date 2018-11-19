#include <functional>

#include "libft.h"
#include "voidVal.hpp"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "striterTest.hpp"

#ifdef FT_STRITER_EXIST
static void striter_f(char *c)
{
	*c = *c + 1;
}
#endif

striterTest::striterTest()
{
#ifdef FT_STRITER_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int striterTest::launchTest()
{
	striterTest test;

	test.startTest("ft_striter(char *s, void (*f)(char *))");

	return test.errCount;
}

void striterTest::processTest()
{
#ifdef FT_STRITER_EXIST
	char fStrParamTab[] = "void (*f)(char *)";
	spStrVal baseS = mkSpStrVal(nullptr, "s");
	spStrVal testS = mkSpStrVal(nullptr, "s");
	spStrVal ptrFunStrParam = mkSpStrVal(nullptr, "f");
	std::function<spVoidVal(spStrVal, spStrVal)> baseFunction =
		[&](spStrVal s, spStrVal f)
		{
			(void)s;
			if (baseS->getVal() != nullptr && f->getVal() != nullptr)
			{
				char *str = baseS->getVal();
				for (size_t i = 0; i < strlen(str); ++i)
				{
					striter_f(str + i);
				}
			}
			return mkSpVoidVal();
		};
	std::function<spVoidVal(spStrVal, spStrVal)> testFunction =
		[&](spStrVal s, spStrVal f)
		{
			(void)s;
			if (f->getVal() != nullptr)
			{
				ft_striter(testS->getVal(), striter_f);
			}
			else
			{
				ft_striter(testS->getVal(), nullptr);
			}
			return mkSpVoidVal();
		};
	auto testValsFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spStrVal, spStrVal>(baseS, testS));};

	if (!dontDoTestThatCrash)
	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseS, ptrFunStrParam);
		ptrFunStrParam->setVal(fStrParamTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseS, ptrFunStrParam);
		char baseSTab[] = "salut";
		char testSTab[] = "salut";
		baseS->setVal(baseSTab);
		testS->setVal(testSTab);
		ptrFunStrParam->setVal(nullptr);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseS, ptrFunStrParam);
	}

	ptrFunStrParam->setVal(fStrParamTab);

	{
		char baseSTab[] = "";
		char testSTab[] = "";
		baseS->setVal(baseSTab);
		testS->setVal(testSTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseS, ptrFunStrParam);
	}

	{
		char baseSTab[] = "salut";
		char testSTab[] = "salut";
		baseS->setVal(baseSTab);
		testS->setVal(testSTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseS, ptrFunStrParam);
	}

	{
		char baseSTab[] = "sal\0ut";
		char testSTab[] = "sal\0ut";
		baseS->setVal(baseSTab);
		testS->setVal(testSTab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseS, ptrFunStrParam);
	}
#endif
}
