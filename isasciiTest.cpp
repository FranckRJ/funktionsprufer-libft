#include <functional>
#include <ctype.h>

#include "libft.h"
#include "baseVal.hpp"
#include "isasciiTest.hpp"

int isasciiTest::launchTest()
{
	isasciiTest test;

	test.startTest("ft_isascii(int c)");

	return test.errCount;
}

void isasciiTest::processTest()
{
	std::function<spBaseVal<int>(spBaseVal<int>)> baseFunction = [](spBaseVal<int> x) {return mkSpBaseVal<int>(isascii(x->getVal()));};
	std::function<spBaseVal<int>(spBaseVal<int>)> testFunction = [](spBaseVal<int> x) {return mkSpBaseVal<int>(ft_isascii(x->getVal()));};

	for (int letter = -300; letter <= 300; ++letter)
	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(letter));
	}
}
