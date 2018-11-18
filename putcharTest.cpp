#include <functional>

#include "libft.h"
#include "utils.hpp"
#include "cppStrVal.hpp"
#include "baseVal.hpp"
#include "stdOutputGetter.hpp"
#include "putcharTest.hpp"

putcharTest::putcharTest()
{
#ifdef FT_PUTCHAR_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int putcharTest::launchTest()
{
	putcharTest test;

	test.startTest("ft_putchar(char c)");

	return test.errCount;
}

void putcharTest::processTest()
{
#ifdef FT_PUTCHAR_EXIST
	std::function<spCppStrVal(spBaseVal<char>)> baseFunction = [](spBaseVal<char> c) {return mkSpCppStrVal(std::string(1, c->getVal()));};
	std::function<spCppStrVal(spBaseVal<char>)> testFunction = [](spBaseVal<char> c)
	{
		{
			stdOutputGetter outputGetter;
			ft_putchar(c->getVal());
		}
		return mkSpCppStrVal(utils::tmpfileToString());
	};

	for (int letter = -300; letter <= 300; ++letter)
	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<char>(letter));
	}
#endif
}
