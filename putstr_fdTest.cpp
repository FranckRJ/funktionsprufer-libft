#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cstStrVal.hpp"
#include "cppStrVal.hpp"
#include "openFile.hpp"
#include "putstr_fdTest.hpp"

putstr_fdTest::putstr_fdTest()
{
#ifdef FT_PUTSTR_FD_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int putstr_fdTest::launchTest()
{
	putstr_fdTest test;

	test.startTest("ft_putstr_fd(char const *s, int fd)");

	return test.errCount;
}

void putstr_fdTest::processTest()
{
#ifdef FT_PUTSTR_FD_EXIST
	std::function<spCppStrVal(spStrVal, spCppStrVal)> baseFunction =
		[&](spStrVal s, spCppStrVal fn)
		{
			(void)fn;
			if (s->getVal() != nullptr)
			{
				return mkSpCppStrVal(std::string(s->getVal()));
			}
			else
			{
				return mkSpCppStrVal("");
			}
		};
	std::function<spCppStrVal(spStrVal, spCppStrVal)> testFunction =
		[&](spStrVal s, spCppStrVal fn)
		{
			openFile newFile(fn->getVal());
			ft_putstr_fd(s->getVal(), newFile.getFileDesc());
			return mkSpCppStrVal(newFile.getFileContent());
		};

	if (!dontDoPotentialCrashTest)
	{
		testThisFun(baseFunction, testFunction, mkSpStrVal(nullptr), mkSpCppStrVal(openFile::tmpfileName));
	}

	{
		char test[] = "Salut";
		testThisFun(baseFunction, testFunction, mkSpStrVal(test), mkSpCppStrVal(openFile::tmpfileName));
	}

	{
		char test[] = "";
		testThisFun(baseFunction, testFunction, mkSpStrVal(test), mkSpCppStrVal(openFile::tmpfileName));
	}

	{
		char test[] = "Sa l\nut.";
		testThisFun(baseFunction, testFunction, mkSpStrVal(test), mkSpCppStrVal(openFile::tmpfileName));
	}
#endif
}
