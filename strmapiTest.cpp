#include <functional>

#include "libft.h"
#include "strVal.hpp"
#include "strmapiTest.hpp"

#ifdef FT_STRMAPI_EXIST
static char strmapi_f(unsigned int i, char c)
{
	(void)c;
	return '0' + i;
}
#endif

strmapiTest::strmapiTest()
{
#ifdef FT_STRMAPI_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strmapiTest::launchTest()
{
	strmapiTest test;

	test.startTest("ft_strmapi(char const *s, char (*f)(unsigned int, char))");

	return test.errCount;
}

void strmapiTest::processTest()
{
#ifdef FT_STRMAPI_EXIST
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
#endif
}
