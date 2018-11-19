#include <functional>

#include "libft.h"
#include "memVal.hpp"
#include "baseVal.hpp"
#include "memcmpTest.hpp"

memcmpTest::memcmpTest()
{
#ifdef FT_MEMCMP_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int memcmpTest::launchTest()
{
	memcmpTest test;

	test.startTest("ft_memcmp(const void *s1, const void *s2, size_t n)");

	return test.errCount;
}

void memcmpTest::processTest()
{
#ifdef FT_MEMCMP_EXIST
	spMemVal testS1 = mkSpMemVal(nullptr, 0);
	spMemVal testS2 = mkSpMemVal(nullptr, 0);
	std::function<spBaseVal<int>(spMemVal, spMemVal, spBaseVal<size_t>)> baseFunction =
		[](spMemVal s1, spMemVal s2, spBaseVal<size_t> n)
		{
			return mkSpBaseVal<int>(memcmp(s1->getVal(), s2->getVal(), n->getVal()));
		};
	std::function<spBaseVal<int>(spMemVal, spMemVal, spBaseVal<size_t>)> testFunction =
		[](spMemVal s1, spMemVal s2, spBaseVal<size_t> n)
		{
			return mkSpBaseVal<int>(ft_memcmp(s1->getVal(), s2->getVal(), n->getVal()));
		};

	if (!dontDoTestThatCrash)
	{
		testThisFun(baseFunction, testFunction, testS1, testS2, mkSpBaseVal<size_t>(4));
		char tabS1[4] = {1, 2, 3, 4};
		testS1->setValAndLen(tabS1, sizeof(tabS1));
		testThisFun(baseFunction, testFunction, testS1, testS2, mkSpBaseVal<size_t>(4));
		char tabS2[4] = {1, 2, 3, 4};
		testS1->setValAndLen(nullptr, 0);
		testS2->setValAndLen(tabS2, sizeof(tabS2));
		testThisFun(baseFunction, testFunction, testS1, testS2, mkSpBaseVal<size_t>(4));
	}

	testThisFun(baseFunction, testFunction, testS1, testS2, mkSpBaseVal<size_t>(0));

	{
		char newTestS1[] = "";
		char newTestS2[] = "";
		testS1->setValAndLen(newTestS1, sizeof(newTestS1));
		testS2->setValAndLen(newTestS2, sizeof(newTestS2));
		testThisFun(baseFunction, testFunction, testS1, testS2, mkSpBaseVal<size_t>(sizeof(newTestS1)));
	}

	{
		char newTestS1[] = {50, 30, 20};
		char newTestS2[] = {50, 30, 20};
		testS1->setValAndLen(newTestS1, sizeof(newTestS1));
		testS2->setValAndLen(newTestS2, sizeof(newTestS2));
		testThisFun(baseFunction, testFunction, testS1, testS2, mkSpBaseVal<size_t>(sizeof(newTestS1)));
	}

	{
		char newTestS1[] = {30, 30, 20};
		char newTestS2[] = {50, 30, 20};
		testS1->setValAndLen(newTestS1, sizeof(newTestS1));
		testS2->setValAndLen(newTestS2, sizeof(newTestS2));
		testThisFun(baseFunction, testFunction, testS1, testS2, mkSpBaseVal<size_t>(sizeof(newTestS1)));
	}

	{
		char newTestS1[] = {30, 30, 20};
		char newTestS2[] = {10, 30, 20};
		testS1->setValAndLen(newTestS1, sizeof(newTestS1));
		testS2->setValAndLen(newTestS2, sizeof(newTestS2));
		testThisFun(baseFunction, testFunction, testS1, testS2, mkSpBaseVal<size_t>(sizeof(newTestS1)));
	}

	{
		char newTestS1[] = {30, 10, 20};
		char newTestS2[] = {30, 30, 20};
		testS1->setValAndLen(newTestS1, sizeof(newTestS1));
		testS2->setValAndLen(newTestS2, sizeof(newTestS2));
		testThisFun(baseFunction, testFunction, testS1, testS2, mkSpBaseVal<size_t>(sizeof(newTestS1)));
	}

	{
		char newTestS1[] = {30, 30, 20};
		char newTestS2[] = {30, 10, 20};
		testS1->setValAndLen(newTestS1, sizeof(newTestS1));
		testS2->setValAndLen(newTestS2, sizeof(newTestS2));
		testThisFun(baseFunction, testFunction, testS1, testS2, mkSpBaseVal<size_t>(sizeof(newTestS1)));
	}

	{
		char newTestS1[] = {30, 30, 20};
		char newTestS2[] = {30, 30, 30};
		testS1->setValAndLen(newTestS1, sizeof(newTestS1));
		testS2->setValAndLen(newTestS2, sizeof(newTestS2));
		testThisFun(baseFunction, testFunction, testS1, testS2, mkSpBaseVal<size_t>(sizeof(newTestS1)));
	}

	{
		char newTestS1[] = {30, 30, 30};
		char newTestS2[] = {30, 30, 20};
		testS1->setValAndLen(newTestS1, sizeof(newTestS1));
		testS2->setValAndLen(newTestS2, sizeof(newTestS2));
		testThisFun(baseFunction, testFunction, testS1, testS2, mkSpBaseVal<size_t>(sizeof(newTestS1)));
	}
#endif
}
