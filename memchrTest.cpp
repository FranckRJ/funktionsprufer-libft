#include <functional>

#include "libft.h"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "baseVal.hpp"
#include "memchrTest.hpp"

memchrTest::memchrTest()
{
#ifdef FT_MEMCHR_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int memchrTest::launchTest()
{
	memchrTest test;

	test.startTest("ft_memchr(const void *s, int c, size_t n)");

	return test.errCount;
}

void memchrTest::processTest()
{
#ifdef FT_MEMCHR_EXIST
	spMemVal testVal = mkSpMemVal(nullptr, 0);
	std::function<spAddrVal(spMemVal, spBaseVal<int>, spBaseVal<size_t>)> baseFunction =
		[](spMemVal s, spBaseVal<int> c, spBaseVal<size_t> n)
		{
			return mkSpAddrVal(memchr(s->getVal(), c->getVal(), n->getVal()), s->getVal());
		};
	std::function<spAddrVal(spMemVal, spBaseVal<int>, spBaseVal<size_t>)> testFunction =
		[](spMemVal s, spBaseVal<int> c, spBaseVal<size_t> n)
		{
			return mkSpAddrVal(ft_memchr(s->getVal(), c->getVal(), n->getVal()), s->getVal());
		};

	if (!dontDoPotentialCrashTest)
	{
		testThisFun(baseFunction, testFunction, testVal, mkSpBaseVal<int>(50), mkSpBaseVal<size_t>(0));
	}

	{
		char test[] = {1, 2, 3, 4, 5};
		testVal->setValAndLen(test, sizeof(test));
		testThisFun(baseFunction, testFunction, testVal, mkSpBaseVal<int>(8), mkSpBaseVal<size_t>(sizeof(test)));
	}

	{
		char test[] = {8, 2, 3, 4, 5};
		testVal->setValAndLen(test, sizeof(test));
		testThisFun(baseFunction, testFunction, testVal, mkSpBaseVal<int>(8), mkSpBaseVal<size_t>(sizeof(test)));
	}

	{
		char test[] = {1, 2, 8, 4, 5};
		testVal->setValAndLen(test, sizeof(test));
		testThisFun(baseFunction, testFunction, testVal, mkSpBaseVal<int>(8), mkSpBaseVal<size_t>(sizeof(test)));
	}

	{
		char test[] = {1, 2, 3, 4, 8};
		testVal->setValAndLen(test, sizeof(test));
		testThisFun(baseFunction, testFunction, testVal, mkSpBaseVal<int>(8), mkSpBaseVal<size_t>(sizeof(test)));
	}

	{
		char test[] = {1, 8, 3, 8, 5};
		testVal->setValAndLen(test, sizeof(test));
		testThisFun(baseFunction, testFunction, testVal, mkSpBaseVal<int>(8), mkSpBaseVal<size_t>(sizeof(test)));
	}

	{
		char test[] = {1, 2, -44, 4, 5};
		testVal->setValAndLen(test, sizeof(test));
		testThisFun(baseFunction, testFunction, testVal, mkSpBaseVal<int>(-300), mkSpBaseVal<size_t>(sizeof(test)));
	}

	{
		char test[] = {1, 2, -8, 4, 5};
		testVal->setValAndLen(test, sizeof(test));
		testThisFun(baseFunction, testFunction, testVal, mkSpBaseVal<int>(-8), mkSpBaseVal<size_t>(sizeof(test)));
	}
#endif
}
