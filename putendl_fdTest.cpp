#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "openFile.hpp"
#include "putendl_fdTest.hpp"

putendl_fdTest::putendl_fdTest()
{
#ifdef FT_PUTENDL_FD_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int putendl_fdTest::launchTest()
{
	putendl_fdTest test;

	test.startTest("ft_putendl_fd(char const *s, int fd)");

	return test.errCount;
}

void putendl_fdTest::processTest()
{
#ifdef FT_PUTENDL_FD_EXIST
	std::function<spCppStrVal(spStrVal, spCppStrVal)> baseFunction =
		[&](spStrVal s, spCppStrVal fn)
		{
			(void)fn;
			if (s->getVal() != nullptr)
			{
				return mkSpCppStrVal(std::string(s->getVal()) + "\n");
			}
			else
			{
				return mkSpCppStrVal("\n");
			}
		};
	std::function<spCppStrVal(spStrVal, spCppStrVal)> testFunction =
		[&](spStrVal s, spCppStrVal fn)
		{
			openFile newFile(fn->getVal());
			ft_putendl_fd(s->getVal(), newFile.getFileDesc());
			return mkSpCppStrVal(newFile.getFileContent());
		};

	if (!dontDoTestThatCrash)
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

	{
		char test[] = "Salut.\n";
		testThisFun(baseFunction, testFunction, mkSpStrVal(test), mkSpCppStrVal(openFile::tmpfileName));
	}
#endif
}
