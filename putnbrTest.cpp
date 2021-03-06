#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "cppStrVal.hpp"
#include "stdOutputGetter.hpp"
#include "openFile.hpp"
#include "putnbrTest.hpp"

putnbrTest::putnbrTest()
{
#ifdef FT_PUTNBR_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int putnbrTest::launchTest()
{
	putnbrTest test;

	test.startTest("ft_putnbr(int n)");

	return test.errCount;
}

void putnbrTest::processTest()
{
#ifdef FT_PUTNBR_EXIST
	std::function<spCppStrVal(spBaseVal<int>)> baseFunction =
		[&](spBaseVal<int> n)
		{
			return mkSpCppStrVal(std::to_string(n->getVal()));
		};
	std::function<spCppStrVal(spBaseVal<int>)> testFunction =
		[&](spBaseVal<int> n)
		{
			{
				stdOutputGetter outputGetter(openFile::tmpfileName);
				ft_putnbr(n->getVal());
			}
			return mkSpCppStrVal(openFile::getTmpfileContent());
		};

	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(0));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(5));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(10));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(105));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(159));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(2147483647));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(2147483646));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-2147483648));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-2147483647));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-159));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-5));
	}
#endif
}
