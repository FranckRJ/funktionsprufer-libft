#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "itoaTest.hpp"

itoaTest::itoaTest()
{
#ifdef FT_ITOA_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int itoaTest::launchTest()
{
	itoaTest test;

	test.startTest("ft_itoa(int n)");

	return test.errCount;
}

void itoaTest::processTest()
{
#ifdef FT_ITOA_EXIST
	std::function<spStrVal(spBaseVal<int>)> baseFunction =
		[&](spBaseVal<int> n)
		{
			std::string tmpVal = std::to_string(n->getVal());
			char *cstr = new char[tmpVal.length() + 1];
			std::strcpy(cstr, tmpVal.c_str());
			return mkSpStrVal(cstr, "", true);
		};
	std::function<spStrVal(spBaseVal<int>)> testFunction =
		[&](spBaseVal<int> n)
		{
			return mkSpStrVal(ft_itoa(n->getVal()), "", true);
		};

	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(0));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-5));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(8));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-138));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(7539));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-2147483648));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(2147483647));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-2147483647));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(2147483646));
	}
#endif
}
