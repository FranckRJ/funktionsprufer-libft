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
	std::function<spCppStrVal(spStrVal, spBaseVal<int>)> baseFunction =
		[&](spStrVal s, spBaseVal<int> fd)
		{
			(void)fd;
			if (s->getVal() != nullptr)
			{
				return mkSpCppStrVal(std::string(s->getVal()));
			}
			else
			{
				return mkSpCppStrVal("");
			}
		};
	std::function<spCppStrVal(spStrVal, spBaseVal<int>)> testFunction =
		[&](spStrVal s, spBaseVal<int> fd)
		{
			ft_putstr_fd(s->getVal(), fd->getVal());
			return mkSpCppStrVal(utils::tmpfileToString());
		};

	if (!dontDoPotentialCrashTest)
	{
		int new_fd = open(utils::tmpfileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		testThisFun(baseFunction, testFunction, mkSpStrVal(nullptr), mkSpBaseVal<int>(new_fd));
		close(new_fd);
	}

	{
		char test[] = "Salut";
		int new_fd = open(utils::tmpfileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		testThisFun(baseFunction, testFunction, mkSpStrVal(test), mkSpBaseVal<int>(new_fd));
		close(new_fd);
	}

	{
		char test[] = "";
		int new_fd = open(utils::tmpfileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		testThisFun(baseFunction, testFunction, mkSpStrVal(test), mkSpBaseVal<int>(new_fd));
		close(new_fd);
	}

	{
		char test[] = "Sa l\nut.";
		int new_fd = open(utils::tmpfileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		testThisFun(baseFunction, testFunction, mkSpStrVal(test), mkSpBaseVal<int>(new_fd));
		close(new_fd);
	}
#endif
}
