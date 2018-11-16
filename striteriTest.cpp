#include <functional>

#include "libft.h"
#include "voidVal.hpp"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "striteriTest.hpp"

static void striteri_f(unsigned int i, char *c)
{
	*c = '0' + i;
}

int striteriTest::launchTest()
{
	striteriTest test;

	test.startTest("ft_striteri(char *s, void (*f)(unsigned int, char *))");

	return test.errCount;
}

void striteriTest::processTest()
{
	char fStrParamTab[] = "void (*f)(unsigned int, char *)";
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
					striteri_f(i, str + i);
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
				ft_striteri(testS->getVal(), striteri_f);
			}
			else
			{
				ft_striteri(testS->getVal(), nullptr);
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
