#include <functional>

#include "libft.h"
#include "utils.hpp"
#include "cppStrVal.hpp"
#include "baseVal.hpp"
#include "strVal.hpp"
#include "stdOutputGetter.hpp"
#include "putendlTest.hpp"

putendlTest::putendlTest()
{
#ifdef FT_PUTENDL_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int putendlTest::launchTest()
{
	putendlTest test;

	test.startTest("ft_putendl(char const *s)");

	return test.errCount;
}

void putendlTest::processTest()
{
#ifdef FT_PUTENDL_EXIST
	std::function<spCppStrVal(spStrVal)> baseFunction = [](spStrVal s) {return mkSpCppStrVal(std::string(s->getVal()) + "\n");};
	std::function<spCppStrVal(spStrVal)> baseNullFunction = [](spStrVal s) {(void)s; return mkSpCppStrVal("\n");};
	std::function<spCppStrVal(spStrVal)> testFunction = [](spStrVal s)
	{
		{
			stdOutputGetter outputGetter;
			ft_putendl(s->getVal());
		}
		return mkSpCppStrVal(utils::tmpfileToString());
	};

	if (!dontDoPotentialCrashTest)
	{
		testThisFun(baseNullFunction, testFunction, mkSpStrVal(nullptr));
	}

	{
		char test[] = "Salut";
		testThisFun(baseFunction, testFunction, mkSpStrVal(test));
	}
	{
		char test[] = "";
		testThisFun(baseFunction, testFunction, mkSpStrVal(test));
	}
	{
		char test[] = "Sa l\nut.";
		testThisFun(baseFunction, testFunction, mkSpStrVal(test));
	}
	{
		char test[] = "Salut.\n";
		testThisFun(baseFunction, testFunction, mkSpStrVal(test));
	}
#endif
}
