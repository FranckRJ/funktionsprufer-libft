#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cstStrVal.hpp"
#include "cppStrVal.hpp"
#include "openFile.hpp"
#include "putchar_fdTest.hpp"

putchar_fdTest::putchar_fdTest()
{
#ifdef FT_PUTCHAR_FD_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int putchar_fdTest::launchTest()
{
	putchar_fdTest test;

	test.startTest("ft_putchar_fd(char c, int fd)");

	return test.errCount;
}

void putchar_fdTest::processTest()
{
#ifdef FT_PUTCHAR_FD_EXIST
	std::function<spCppStrVal(spBaseVal<char>, spCppStrVal)> baseFunction =
		[&](spBaseVal<char> c, spCppStrVal fn)
		{
			(void)fn;
			if (!(fn->getVal().empty()))
			{
				return mkSpCppStrVal(std::string(1, c->getVal()));
			}
			else
			{
				return mkSpCppStrVal("");
			}
		};
	std::function<spCppStrVal(spBaseVal<char>, spCppStrVal)> testFunction =
		[&](spBaseVal<char> c, spCppStrVal fn)
		{
			openFile newFile(fn->getVal());
			ft_putchar_fd(c->getVal(), newFile.getFileDesc());
			return mkSpCppStrVal(newFile.getFileContent());
		};

	testThisFun(baseFunction, testFunction, mkSpBaseVal<char>('a'), mkSpCppStrVal(""));

	for (int letter = -300; letter <= 300; ++letter)
	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<char>(letter), mkSpCppStrVal(openFile::tmpfileName));
	}
#endif
}
