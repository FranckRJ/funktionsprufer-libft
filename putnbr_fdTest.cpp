#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "openFile.hpp"
#include "putnbr_fdTest.hpp"

putnbr_fdTest::putnbr_fdTest()
{
#ifdef FT_PUTNBR_FD_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int putnbr_fdTest::launchTest()
{
	putnbr_fdTest test;

	test.startTest("ft_putnbr_fd(int n, int fd)");

	return test.errCount;
}

void putnbr_fdTest::processTest()
{
#ifdef FT_PUTNBR_FD_EXIST
	std::function<spCppStrVal(spBaseVal<int>, spCppStrVal)> baseFunction =
		[&](spBaseVal<int> n, spCppStrVal fn)
		{
			(void)fn;
			return mkSpCppStrVal(std::to_string(n->getVal()));
		};
	std::function<spCppStrVal(spBaseVal<int>, spCppStrVal)> testFunction =
		[&](spBaseVal<int> n, spCppStrVal fn)
		{
			openFile newFile(fn->getVal());
			ft_putnbr_fd(n->getVal(), newFile.getFileDesc());
			return mkSpCppStrVal(newFile.getFileContent());
		};

	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(0), mkSpCppStrVal(openFile::tmpfileName));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(5), mkSpCppStrVal(openFile::tmpfileName));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(159), mkSpCppStrVal(openFile::tmpfileName));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(2147483647), mkSpCppStrVal(openFile::tmpfileName));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(2147483646), mkSpCppStrVal(openFile::tmpfileName));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-2147483648), mkSpCppStrVal(openFile::tmpfileName));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-2147483647), mkSpCppStrVal(openFile::tmpfileName));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-159), mkSpCppStrVal(openFile::tmpfileName));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(-5), mkSpCppStrVal(openFile::tmpfileName));
	}
#endif
}
