#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "atoiTest.hpp"

atoiTest::atoiTest()
{
#ifdef FT_ATOI_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int atoiTest::launchTest()
{
	atoiTest test;

	test.startTest("ft_atoi(const char *str)");

	return test.errCount;
}

void atoiTest::processTest()
{
#ifdef FT_ATOI_EXIST
	spStrVal paramTest = mkSpStrVal(nullptr);
	std::function<spBaseVal<int>(spStrVal)> baseFunction =
		[&](spStrVal str)
		{
			return mkSpBaseVal<int>(atoi(str->getVal()));
		};
	std::function<spBaseVal<int>(spStrVal)> testFunction =
		[&](spStrVal str)
		{
			return mkSpBaseVal<int>(ft_atoi(str->getVal()));
		};

	if (!dontDoTestThatCrash)
	{
		testThisFun(baseFunction, testFunction, paramTest);
	}

	{
		char paramTab[] = "";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "0";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "5";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "-32";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "2147483647";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "-2147483648";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "2147483648";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "-2147483649";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "0123";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "10";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "-10";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "10159";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "-1052";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = " 59";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = " \t\v\n\r\f12";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "156 2";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "152k2";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = " 156 5";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = " \t+-35";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = " \t+35";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = " \t++35";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "35+2";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = " +   35+2";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
	{
		char paramTab[] = "sdf35+2";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest);
	}
#endif
}
