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
#include "putnbr_fdTest.hpp"

int putnbr_fdTest::launchTest()
{
	putnbr_fdTest test;

	test.startTest("ft_putnbr_fd(int n, int fd)");

	return test.errCount;
}

void putnbr_fdTest::processTest()
{
	std::function<spCppStrVal(spBaseVal<int>, spBaseVal<int>)> baseFunction =
		[&](spBaseVal<int> n, spBaseVal<int> fd)
		{
			(void)fd;
			return mkSpCppStrVal(std::to_string(n->getVal()));
		};
	std::function<spCppStrVal(spBaseVal<int>, spBaseVal<int>)> testFunction =
		[&](spBaseVal<int> n, spBaseVal<int> fd)
		{
			ft_putnbr_fd(n->getVal(), fd->getVal());
			return mkSpCppStrVal(utils::tmpfileToString());
		};

	{
		int new_fd = open(utils::tmpfileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(0), mkSpBaseVal<int>(new_fd));
		close(new_fd);
	}

	{
		int new_fd = open(utils::tmpfileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(5), mkSpBaseVal<int>(new_fd));
		close(new_fd);
	}

	{
		int new_fd = open(utils::tmpfileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(159), mkSpBaseVal<int>(new_fd));
		close(new_fd);
	}

	{
		int new_fd = open(utils::tmpfileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(2147483647), mkSpBaseVal<int>(new_fd));
		close(new_fd);
	}

	{
		int new_fd = open(utils::tmpfileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(2147483646), mkSpBaseVal<int>(new_fd));
		close(new_fd);
	}

	{
		int new_fd = open(utils::tmpfileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-2147483648), mkSpBaseVal<int>(new_fd));
		close(new_fd);
	}

	{
		int new_fd = open(utils::tmpfileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-2147483647), mkSpBaseVal<int>(new_fd));
		close(new_fd);
	}

	{
		int new_fd = open(utils::tmpfileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-159), mkSpBaseVal<int>(new_fd));
		close(new_fd);
	}

	{
		int new_fd = open(utils::tmpfileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-5), mkSpBaseVal<int>(new_fd));
		close(new_fd);
	}
}
