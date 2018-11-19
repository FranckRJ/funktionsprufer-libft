#include <functional>

#include "libft.h"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "baseVal.hpp"
#include "memmoveTest.hpp"

memmoveTest::memmoveTest()
{
#ifdef FT_MEMMOVE_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int memmoveTest::launchTest()
{
	memmoveTest test;

	test.startTest("ft_memmove(void *dst, const void *src, size_t len)");

	return test.errCount;
}

void memmoveTest::processTest()
{
#ifdef FT_MEMMOVE_EXIST
	spMemVal testValForBase = mkSpMemVal(nullptr, 0, "dst");
	spMemVal testValForTest = mkSpMemVal(nullptr, 0, "dst");
	std::function<spAddrVal(spMemVal, spMemVal, spBaseVal<size_t>)> baseFunction =
		[&](spMemVal dst, spMemVal src, spBaseVal<size_t> len)
		{
			(void)dst;
			return mkSpAddrVal(memmove(testValForBase->getVal(), src->getVal(), len->getVal()), testValForBase->getVal());
		};
	std::function<spAddrVal(spMemVal, spMemVal, spBaseVal<size_t>)> testFunction =
		[&](spMemVal dst, spMemVal src, spBaseVal<size_t> len)
		{
			(void)dst;
			return mkSpAddrVal(ft_memmove(testValForTest->getVal(), src->getVal(), len->getVal()), testValForTest->getVal());
		};
	std::function<spAddrVal(spMemVal, spMemVal, spBaseVal<size_t>, spBaseVal<int>)> baseFunctionDecal =
		[&](spMemVal dst, spMemVal src, spBaseVal<size_t> len, spBaseVal<int> decal)
		{
			(void)dst;
			(void)src;
			return mkSpAddrVal(memmove(testValForBase->getVal(), ((char*)testValForBase->getVal()) + decal->getVal(), len->getVal()), testValForBase->getVal());
		};
	std::function<spAddrVal(spMemVal, spMemVal, spBaseVal<size_t>, spBaseVal<int>)> testFunctionDecal =
		[&](spMemVal dst, spMemVal src, spBaseVal<size_t> len, spBaseVal<int> decal)
		{
			(void)dst;
			(void)src;
			return mkSpAddrVal(ft_memmove(testValForTest->getVal(), ((char*)testValForTest->getVal()) + decal->getVal(), len->getVal()), testValForTest->getVal());
		};
	std::function<bool(bool)> testValsFun =
		[&](bool printRes) { return compareVals(printRes, std::pair<spMemVal, spMemVal>(testValForBase, testValForTest)); };

	if (!dontDoTestThatCrash)
	{
		char test[4] = {1, 2, 3, 4};
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpMemVal(test, sizeof(test), "src"), mkSpBaseVal<size_t>(50, "len"));
		char tabValForBase[4] = {5, 15, 13};
		char tabValForTest[4] = {5, 15, 13};
		testValForBase->setValAndLen(tabValForBase, sizeof(tabValForBase));
		testValForTest->setValAndLen(tabValForTest, sizeof(tabValForTest));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpMemVal(nullptr, 0, "src"), mkSpBaseVal<size_t>(50, "len"));
	}

	testValForBase->setValAndLen(nullptr, 0);
	testValForTest->setValAndLen(nullptr, 0);
	testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpMemVal(nullptr, 0, "src"), mkSpBaseVal<size_t>(50, "len"));

	for (int i = 0; i <= 4; ++i)
	{
		char test[4] = {1, 2, 3, 4};
		char tabValForBase[4] = {5, 15, 13};
		char tabValForTest[4] = {5, 15, 13};
		testValForBase->setValAndLen(tabValForBase, sizeof(tabValForBase));
		testValForTest->setValAndLen(tabValForTest, sizeof(tabValForTest));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpMemVal(test, sizeof(test), "src"), mkSpBaseVal<size_t>(i, "len"));
	}

	for (int i = 0; i <= 5; ++i)
	{
		char tabValForBase[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		char tabValForTest[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		testValForBase->setValAndLen(tabValForBase, sizeof(tabValForBase));
		testValForTest->setValAndLen(tabValForTest, sizeof(tabValForTest));
		testThisFunAndVals(baseFunctionDecal, testFunctionDecal, testValsFun, testValForBase, mkSpMemVal(tabValForBase + i, 5, "src"), mkSpBaseVal<size_t>(5, "len"), mkSpBaseVal<int>(i, "(decalage)"));
	}

	for (int i = 0; i >= -5; --i)
	{
		char tabValForBase[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		char tabValForTest[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		testValForBase->setValAndLen(tabValForBase + 5, sizeof(tabValForBase) - 5);
		testValForTest->setValAndLen(tabValForTest + 5, sizeof(tabValForTest) - 5);
		testThisFunAndVals(baseFunctionDecal, testFunctionDecal, testValsFun, testValForBase, mkSpMemVal(tabValForBase + 5 + i, 5, "src"), mkSpBaseVal<size_t>(5, "len"), mkSpBaseVal<int>(i, "(decalage)"));
	}
#endif
}
