#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "strrchrTest.hpp"

strrchrTest::strrchrTest()
{
#ifdef FT_STRRCHR_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strrchrTest::launchTest()
{
	strrchrTest test;

	test.startTest("ft_strrchr(const char *s, int c)");

	return test.errCount;
}

void strrchrTest::processTest()
{
#ifdef FT_STRRCHR_EXIST
	spStrVal paramTest = mkSpStrVal(nullptr);
	std::function<spAddrVal(spStrVal, spBaseVal<int>)> baseFunction =
		[&](spStrVal s, spBaseVal<int> c)
		{
			return mkSpAddrVal(strrchr(s->getVal(), c->getVal()), s->getVal());
		};
	std::function<spAddrVal(spStrVal, spBaseVal<int>)> testFunction =
		[&](spStrVal s, spBaseVal<int> c)
		{
			return mkSpAddrVal(ft_strrchr(s->getVal(), c->getVal()), s->getVal());
		};

	if (!dontDoTestThatCrash)
	{
		testThisFun(baseFunction, testFunction, paramTest, mkSpBaseVal<int>('a'));
	}

	{
		char paramTab[] = "bonjour";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest, mkSpBaseVal<int>('a'));
		testThisFun(baseFunction, testFunction, paramTest, mkSpBaseVal<int>('b'));
		testThisFun(baseFunction, testFunction, paramTest, mkSpBaseVal<int>('r'));
		testThisFun(baseFunction, testFunction, paramTest, mkSpBaseVal<int>('o'));
		testThisFun(baseFunction, testFunction, paramTest, mkSpBaseVal<int>(0));
	}

	{
		char paramTab[] = "";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest, mkSpBaseVal<int>('K'));
		testThisFun(baseFunction, testFunction, paramTest, mkSpBaseVal<int>(0));
	}

	{
		char paramTab[] = "bon\0jour";
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest, mkSpBaseVal<int>('n'));
		testThisFun(baseFunction, testFunction, paramTest, mkSpBaseVal<int>('u'));
	}

	{
		char paramTab[] = {1, -8, 3, -44, 5};
		paramTest->setVal(paramTab);
		testThisFun(baseFunction, testFunction, paramTest, mkSpBaseVal<int>(-8));
		testThisFun(baseFunction, testFunction, paramTest, mkSpBaseVal<int>(-300));
	}
#endif
}
