#include <functional>
#include <utility>
#include <string.h>

#include "libft.h"
#include "baseVal.hpp"
#include "strVal.hpp"
#include "strlcatTest.hpp"

strlcatTest::strlcatTest()
{
#ifdef FT_STRLCAT_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strlcatTest::launchTest()
{
	strlcatTest test;

	test.startTest("ft_strlcat(char *dst, const char *src, size_t size)");

	return test.errCount;
}

void strlcatTest::processTest()
{
#ifdef FT_STRLCAT_EXIST
	spStrVal testValForBase = mkSpStrVal((char*)NULL, "dst");
	spStrVal testValForTest = mkSpStrVal((char*)NULL, "dst");
	std::function<spBaseVal<size_t>(spStrVal, spStrVal, spBaseVal<size_t>)> baseFunction =
			[&](spStrVal _, spStrVal src, spBaseVal<size_t> size)
			{
				(void)_;
				return mkSpBaseVal<size_t>(strlcat(testValForBase->getVal(), src->getVal(), size->getVal()));
			};
	std::function<spBaseVal<size_t>(spStrVal, spStrVal, spBaseVal<size_t>)> testFunction =
			[&](spStrVal _, spStrVal src, spBaseVal<size_t> size)
			{
				(void)_;
				return mkSpBaseVal<size_t>(ft_strlcat(testValForTest->getVal(), src->getVal(), size->getVal()));
			};
	std::function<bool(bool)> testValsFun =
		[&](bool printRes) { return compareVals(printRes, std::pair<spStrVal, spStrVal>(testValForBase, testValForTest)); };

	for (int i = 0; i < 10; ++i)
	{
		char test[] = "ok";
		char tabValForBase[10] = "123";
		char tabValForTest[10] = "123";
		testValForBase->setVal(tabValForBase);
		testValForTest->setVal(tabValForTest);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, testValForBase, mkSpStrVal(test), mkSpBaseVal<size_t>(i));
	}
#endif
}
