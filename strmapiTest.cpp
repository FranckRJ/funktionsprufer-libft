#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "strmapiTest.hpp"

static char strmapi_f(unsigned int i, char c)
{
	(void)c;
	return '0' + i;
}

int strmapiTest::launchTest()
{
	strmapiTest test;

	test.startTest("ft_strmapi(char const *s, char (*f)(unsigned int, char))");

	return test.errCount;
}

void strmapiTest::processTest()
{
	char fStrParamTab[] = "char (*f)(unsigned int, char)";
	spStrVal baseS = mkSpStrVal(nullptr, "s");
	spStrVal testS = mkSpStrVal(nullptr, "s");
	spStrVal ptrFunStrParam = mkSpStrVal(nullptr, "f");
	std::function<spStrVal(spStrVal, spStrVal)> baseFunction =
		[&](spStrVal s, spStrVal f)
		{
			(void)s;
			char *new_str = nullptr;
			if (baseS->getVal() != nullptr && f->getVal() != nullptr)
			{
				char *str = baseS->getVal();
				new_str = strdup(str);
				for (size_t i = 0; i < strlen(str); ++i)
				{
					new_str[i] = strmapi_f(i, str[i]);
				}
			}
			return mkSpStrVal(new_str, "", true);
		};
	std::function<spStrVal(spStrVal, spStrVal)> testFunction =
		[&](spStrVal s, spStrVal f)
		{
			(void)s;
			char *new_str = nullptr;
			if (f->getVal() != nullptr)
			{
				new_str = ft_strmapi(testS->getVal(), strmapi_f);
			}
			else
			{
				new_str = ft_strmapi(testS->getVal(), nullptr);
			}
			return mkSpStrVal(new_str, "", true);
		};

	if (!dontDoPotentialCrashTest)
	{
		testThisFun(baseFunction, testFunction, baseS, ptrFunStrParam);
		ptrFunStrParam->setVal(fStrParamTab);
		testThisFun(baseFunction, testFunction, baseS, ptrFunStrParam);
		char baseSTab[] = "salut";
		char testSTab[] = "salut";
		baseS->setVal(baseSTab);
		testS->setVal(testSTab);
		ptrFunStrParam->setVal(nullptr);
		testThisFun(baseFunction, testFunction, baseS, ptrFunStrParam);
	}

	ptrFunStrParam->setVal(fStrParamTab);

	{
		char baseSTab[] = "";
		char testSTab[] = "";
		baseS->setVal(baseSTab);
		testS->setVal(testSTab);
		testThisFun(baseFunction, testFunction, baseS, ptrFunStrParam);
	}

	{
		char baseSTab[] = "salut";
		char testSTab[] = "salut";
		baseS->setVal(baseSTab);
		testS->setVal(testSTab);
		testThisFun(baseFunction, testFunction, baseS, ptrFunStrParam);
	}

	{
		char baseSTab[] = "sal\0ut";
		char testSTab[] = "sal\0ut";
		baseS->setVal(baseSTab);
		testS->setVal(testSTab);
		testThisFun(baseFunction, testFunction, baseS, ptrFunStrParam);
	}
}
