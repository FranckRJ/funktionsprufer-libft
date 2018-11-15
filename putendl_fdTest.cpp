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
#include "putendl_fdTest.hpp"

int putendl_fdTest::launchTest()
{
	putendl_fdTest test;

	test.startTest("ft_putendl_fd(char const *s, int fd)");

	return test.errCount;
}

void putendl_fdTest::processTest()
{
	std::function<spCppStrVal(spStrVal, spBaseVal<int>)> baseFunction =
		[&](spStrVal s, spBaseVal<int> fd)
		{
			(void)fd;
			if (s->getVal() != nullptr)
			{
				return mkSpCppStrVal(std::string(s->getVal()) + "\n");
			}
			else
			{
				return mkSpCppStrVal("\n");
			}
		};
	std::function<spCppStrVal(spStrVal, spBaseVal<int>)> testFunction =
		[&](spStrVal s, spBaseVal<int> fd)
		{
			ft_putendl_fd(s->getVal(), fd->getVal());
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

	{
		char test[] = "Salut.\n";
		int new_fd = open(utils::tmpfileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		testThisFun(baseFunction, testFunction, mkSpStrVal(test), mkSpBaseVal<int>(new_fd));
		close(new_fd);
	}
}
