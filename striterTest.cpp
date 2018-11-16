#include <functional>

#include "libft.h"
#include "voidVal.hpp"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "striterTest.hpp"

static void striter_f(char *c)
{
	*c = *c + 1;
}

int striterTest::launchTest()
{
	striterTest test;

	test.startTest("ft_striter(char *s, void (*f)(char *))");

	return test.errCount;
}

void striterTest::processTest()
{
	char fStrParamTab[] = "void (*f)(char *)";
	spStrVal baseS = mkSpStrVal(nullptr);
	spStrVal testS = mkSpStrVal(nullptr);
	spStrVal ptrFunStrParam = mkSpStrVal(nullptr);
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

	if (!dontDoPotentialCrashTest)
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
}
