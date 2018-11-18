#include <functional>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "utils.hpp"
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
	std::function<spCppStrVal(spBaseVal<char>, spBaseVal<int>)> baseFunction =
		[&](spBaseVal<char> c, spBaseVal<int> fd)
		{
			(void)fd;
			return mkSpCppStrVal(std::string(1, c->getVal()));
		};
	std::function<spCppStrVal(spBaseVal<char>, spBaseVal<int>)> testFunction =
		[&](spBaseVal<char> c, spBaseVal<int> fd)
		{
			ft_putchar_fd(c->getVal(), fd->getVal());
			return mkSpCppStrVal(utils::tmpfileToString());
		};

	for (int letter = -300; letter <= 300; ++letter)
	{
		int new_fd = open(utils::tmpfileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		testThisFun(baseFunction, testFunction, mkSpBaseVal<char>(letter), mkSpBaseVal<int>(new_fd));
		close(new_fd);
	}
#endif
}
