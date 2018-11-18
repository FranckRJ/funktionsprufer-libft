#include <functional>

#include "libft.h"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "baseVal.hpp"
#include "memccpyTest.hpp"

memccpyTest::memccpyTest()
{
#ifdef FT_MEMCCPY_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int memccpyTest::launchTest()
{
	memccpyTest test;

	test.startTest("ft_memccpy(void *dst, const void *src, int c, size_t n)");

	return test.errCount;
}

void memccpyTest::processTest()
{
#ifdef FT_MEMCCPY_EXIST
	spMemVal testValForBase = mkSpMemVal(nullptr, 0, "dst");
	spMemVal testValForTest = mkSpMemVal(nullptr, 0, "dst");
	std::function<spAddrVal(spMemVal, spMemVal, spBaseVal<int>, spBaseVal<size_t>)> baseFunction =
		[&](spMemVal dst, spMemVal src, spBaseVal<int> c, spBaseVal<size_t> n)
		{
			(void)dst;
			return mkSpAddrVal(memccpy(testValForBase->getVal(), src->getVal(), c->getVal(), n->getVal()), testValForBase->getVal());
		};
	std::function<spAddrVal(spMemVal, spMemVal, spBaseVal<int>, spBaseVal<size_t>)> testFunction =
		[&](spMemVal dst, spMemVal src, spBaseVal<int> c, spBaseVal<size_t> n)
		{
			(void)dst;
			return mkSpAddrVal(ft_memccpy(testValForTest->getVal(), src->getVal(), c->getVal(), n->getVal()), testValForTest->getVal());
		};
	std::function<bool(bool)> testValsFun =
		[&](bool printRes) { return compareVals(printRes, std::pair<spMemVal, spMemVal>(testValForBase, testValForTest)); };

	if (!dontDoPotentialCrashTest)
	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpMemVal(nullptr, 0, "src"), mkSpBaseVal<int>(8, "c"), mkSpBaseVal<size_t>(0, "n"));
	}

	for (int i = 0; i <= 5; ++i)
	{
		char test[5] = {1, 2, 3, 4, 5};
		char tabValForBase[5] = {5, 15, 13, 2};
		char tabValForTest[5] = {5, 15, 13, 2};
		testValForBase->setValAndLen(tabValForBase, sizeof(tabValForBase));
		testValForTest->setValAndLen(tabValForTest, sizeof(tabValForTest));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpMemVal(test, sizeof(test), "src"), mkSpBaseVal<int>(8, "c"), mkSpBaseVal<size_t>(i, "n"));
	}

	for (int i = 0; i <= 5; ++i)
	{
		char test[5] = {1, 8, 3, 8, 5};
		char tabValForBase[5] = {5, 15, 13, 2};
		char tabValForTest[5] = {5, 15, 13, 2};
		testValForBase->setValAndLen(tabValForBase, sizeof(tabValForBase));
		testValForTest->setValAndLen(tabValForTest, sizeof(tabValForTest));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpMemVal(test, sizeof(test), "src"), mkSpBaseVal<int>(8, "c"), mkSpBaseVal<size_t>(i, "n"));
	}

	for (int i = 0; i <= 3; ++i)
	{
		char test[3] = {1, 2, 8};
		char tabValForBase[3] = {5, 15, 13};
		char tabValForTest[3] = {5, 15, 13};
		testValForBase->setValAndLen(tabValForBase, sizeof(tabValForBase));
		testValForTest->setValAndLen(tabValForTest, sizeof(tabValForTest));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpMemVal(test, sizeof(test), "src"), mkSpBaseVal<int>(8, "c"), mkSpBaseVal<size_t>(i, "n"));
	}
#endif
}
