#include <functional>

#include "libft.h"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "baseVal.hpp"
#include "memsetTest.hpp"

int memsetTest::launchTest()
{
	memsetTest test;

	test.startTest("ft_memset(void *b, int c, size_t len)");

	return test.errCount;
}

void memsetTest::processTest()
{
	spMemVal testValForBase = mkSpMemVal((char*)NULL, 0, "b");
	spMemVal testValForTest = mkSpMemVal((char*)NULL, 0, "b");
	std::function<spAddrVal(spMemVal, spBaseVal<int>, spBaseVal<size_t>)> baseFunction =
		[&](spMemVal b, spBaseVal<int> c, spBaseVal<size_t> len)
		{
			(void)b;
			return mkSpAddrVal(memset(testValForBase->getVal(), c->getVal(), len->getVal()), testValForBase->getVal());
		};
	std::function<spAddrVal(spMemVal, spBaseVal<int>, spBaseVal<size_t>)> testFunction =
		[&](spMemVal b, spBaseVal<int> c, spBaseVal<size_t> len)
		{
			(void)b;
			return mkSpAddrVal(ft_memset(testValForTest->getVal(), c->getVal(), len->getVal()), testValForTest->getVal());
		};
	std::function<bool(bool)> testValsFun =
		[&](bool printRes) { return compareVals(printRes, std::pair<spMemVal, spMemVal>(testValForBase, testValForTest)); };

	if (!dontDoPotentialCrashTest)
	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpBaseVal<int>(50, "c"), mkSpBaseVal<size_t>(0, "len"));
	}

	for (int i = 0; i <= 4; ++i)
	{
		char tabValForBase[4] = {5, 15, 13};
		char tabValForTest[4] = {5, 15, 13};
		testValForBase->setValAndLen(tabValForBase, sizeof(tabValForBase));
		testValForTest->setValAndLen(tabValForTest, sizeof(tabValForTest));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpBaseVal<int>(0, "c"), mkSpBaseVal<size_t>(i, "len"));
	}

	for (int i = 0; i <= 4; ++i)
	{
		char tabValForBase[4] = {5, 15, 13};
		char tabValForTest[4] = {5, 15, 13};
		testValForBase->setValAndLen(tabValForBase, sizeof(tabValForBase));
		testValForTest->setValAndLen(tabValForTest, sizeof(tabValForTest));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpBaseVal<int>(50, "c"), mkSpBaseVal<size_t>(i, "len"));
	}

	for (int i = 0; i <= 4; ++i)
	{
		char tabValForBase[4] = {5, 15, 13};
		char tabValForTest[4] = {5, 15, 13};
		testValForBase->setValAndLen(tabValForBase, sizeof(tabValForBase));
		testValForTest->setValAndLen(tabValForTest, sizeof(tabValForTest));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpBaseVal<int>(300, "c"), mkSpBaseVal<size_t>(i, "len"));
	}
}
