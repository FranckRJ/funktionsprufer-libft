#include <functional>
#include <string.h>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "voidVal.hpp"
#include "bzeroTest.hpp"

bzeroTest::bzeroTest()
{
#ifdef FT_BZERO_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int bzeroTest::launchTest()
{
	bzeroTest test;

	test.startTest("ft_bzero(void *s, size_t n)");

	return test.errCount;
}

void bzeroTest::processTest()
{
#ifdef FT_BZERO_EXIST
	spMemVal testValForBase = mkSpMemVal((char*)NULL, 0, "s");
	spMemVal testValForTest = mkSpMemVal((char*)NULL, 0, "s");
	std::function<spVoidVal(spMemVal, spBaseVal<size_t>)> baseFunction =
			[&](spMemVal _, spBaseVal<size_t> len) {(void)_; bzero(testValForBase->getVal(), len->getVal()); return mkSpVoidVal();};
	std::function<spVoidVal(spMemVal, spBaseVal<size_t>)> testFunction =
			[&](spMemVal _, spBaseVal<size_t> len) {(void)_; ft_bzero(testValForTest->getVal(), len->getVal()); return mkSpVoidVal();};
	std::function<bool(bool)> testValsFun =
		[&](bool printRes) { return compareVals(printRes, std::pair<spMemVal, spMemVal>(testValForBase, testValForTest)); };

	if (!dontDoPotentialCrashTest)
	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpBaseVal<size_t>(0, "n"));
	}

	for (int i = 0; i <= 4; ++i)
	{
		char tabValForBase[4] = {5, 15, 13};
		char tabValForTest[4] = {5, 15, 13};
		testValForBase->setValAndLen(tabValForBase, sizeof(tabValForBase));
		testValForTest->setValAndLen(tabValForTest, sizeof(tabValForTest));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpBaseVal<size_t>(i, "n"));
	}
#endif
}
