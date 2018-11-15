#include <functional>
#include <ctype.h>

#include "libft.h"
#include "baseVal.hpp"
#include "isalnumTest.hpp"

int isalnumTest::launchTest()
{
	isalnumTest test;

	test.startTest("ft_isalnum(int c)");

	return test.errCount;
}

void isalnumTest::processTest()
{
	std::function<spBaseVal<int>(spBaseVal<int>)> baseFunction = [](spBaseVal<int> x) {return mkSpBaseVal<int>(isalnum(x->getVal()));};
	std::function<spBaseVal<int>(spBaseVal<int>)> testFunction = [](spBaseVal<int> x) {return mkSpBaseVal<int>(ft_isalnum(x->getVal()));};

	for (int letter = -300; letter <= 300; ++letter)
	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(letter));
	}
}
