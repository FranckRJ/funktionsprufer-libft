#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "strVal.hpp"
#include "strlenTest.hpp"

int strlenTest::launchTest()
{
	strlenTest test;

	test.startTest("ft_strlen(const char *s)");

	return test.errCount;
}

void strlenTest::processTest()
{
	spStrVal valToTest = mkSpStrVal(nullptr);
	std::function<spBaseVal<size_t>(spStrVal)> baseFunction =
		[](spStrVal s)
		{
			return mkSpBaseVal<size_t>(strlen(s->getVal()));
		};
	std::function<spBaseVal<size_t>(spStrVal)> testFunction =
		[](spStrVal s)
		{
			return mkSpBaseVal<size_t>(ft_strlen(s->getVal()));
		};

	{
		char testVal[] = "bonjour";
		valToTest->setVal(testVal);
		testThisFun(baseFunction, testFunction, valToTest);
	}
	{
		char testVal[] = "";
		valToTest->setVal(testVal);
		testThisFun(baseFunction, testFunction, valToTest);
	}
	{
		char testVal[] = "bon\0jour";
		valToTest->setVal(testVal);
		testThisFun(baseFunction, testFunction, valToTest);
	}
}
