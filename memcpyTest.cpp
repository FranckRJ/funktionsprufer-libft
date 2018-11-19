#include <functional>

#include "libft.h"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "baseVal.hpp"
#include "memcpyTest.hpp"

memcpyTest::memcpyTest()
{
#ifdef FT_MEMCPY_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int memcpyTest::launchTest()
{
	memcpyTest test;

	test.startTest("ft_memcpy(void *dst, const void *src, size_t n)");

	return test.errCount;
}

void memcpyTest::processTest()
{
#ifdef FT_MEMCPY_EXIST
	spMemVal testValForBase = mkSpMemVal(nullptr, 0, "dst");
	spMemVal testValForTest = mkSpMemVal(nullptr, 0, "dst");
	std::function<spAddrVal(spMemVal, spMemVal, spBaseVal<size_t>)> baseFunction =
		[&](spMemVal dst, spMemVal src, spBaseVal<size_t> n)
		{
			(void)dst;
			return mkSpAddrVal(memcpy(testValForBase->getVal(), src->getVal(), n->getVal()), testValForBase->getVal());
		};
	std::function<spAddrVal(spMemVal, spMemVal, spBaseVal<size_t>)> testFunction =
		[&](spMemVal dst, spMemVal src, spBaseVal<size_t> n)
		{
			(void)dst;
			return mkSpAddrVal(ft_memcpy(testValForTest->getVal(), src->getVal(), n->getVal()), testValForTest->getVal());
		};
	std::function<bool(bool)> testValsFun =
		[&](bool printRes) { return compareVals(printRes, std::pair<spMemVal, spMemVal>(testValForBase, testValForTest)); };

	if (!dontDoTestThatCrash)
	{
		char test[4] = {1, 2, 3, 4};
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpMemVal(test, sizeof(test), "src"), mkSpBaseVal<size_t>(50, "n"));
		char tabValForBase[4] = {5, 15, 13};
		char tabValForTest[4] = {5, 15, 13};
		testValForBase->setValAndLen(tabValForBase, sizeof(tabValForBase));
		testValForTest->setValAndLen(tabValForTest, sizeof(tabValForTest));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpMemVal(nullptr, 0, "src"), mkSpBaseVal<size_t>(50, "n"));
	}

	testValForBase->setValAndLen(nullptr, 0);
	testValForTest->setValAndLen(nullptr, 0);
	testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpMemVal(nullptr, 0, "src"), mkSpBaseVal<size_t>(50, "n"));

	for (int i = 0; i <= 4; ++i)
	{
		char test[4] = {1, 2, 3, 4};
		char tabValForBase[4] = {5, 15, 13};
		char tabValForTest[4] = {5, 15, 13};
		testValForBase->setValAndLen(tabValForBase, sizeof(tabValForBase));
		testValForTest->setValAndLen(tabValForTest, sizeof(tabValForTest));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpMemVal(test, sizeof(test), "src"), mkSpBaseVal<size_t>(i, "n"));
	}
#endif
}
