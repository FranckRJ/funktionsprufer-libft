#include <functional>

#include "libft.h"
#include "openFile.hpp"
#include "cppStrVal.hpp"
#include "baseVal.hpp"
#include "strVal.hpp"
#include "stdOutputGetter.hpp"
#include "putstrTest.hpp"

putstrTest::putstrTest()
{
#ifdef FT_PUTSTR_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int putstrTest::launchTest()
{
	putstrTest test;

	test.startTest("ft_putstr(char const *s)");

	return test.errCount;
}

void putstrTest::processTest()
{
#ifdef FT_PUTSTR_EXIST
	std::function<spCppStrVal(spStrVal)> baseFunction = [](spStrVal s) {return mkSpCppStrVal(std::string(s->getVal()));};
	std::function<spCppStrVal(spStrVal)> baseNullFunction = [](spStrVal s) {(void)s; return mkSpCppStrVal("");};
	std::function<spCppStrVal(spStrVal)> testFunction = [](spStrVal s)
	{
		{
			stdOutputGetter outputGetter(openFile::tmpfileName);
			ft_putstr(s->getVal());
		}
		return mkSpCppStrVal(openFile::getTmpfileContent());
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
#endif
}
