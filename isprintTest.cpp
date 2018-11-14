#include <functional>
#include <ctype.h>

#include "libft.h"
#include "baseVal.hpp"
#include "isprintTest.hpp"

int isprintTest::launchTest()
{
	isprintTest test;

	test.startTest("ft_isprint(int c)");

	return test.errCount;
}

void isprintTest::processTest()
{
	std::function<spBaseVal<int>(spBaseVal<int>)> baseFunction = [](spBaseVal<int> x) {return mkSpBaseVal<int>(isprint(x->getVal()));};
	std::function<spBaseVal<int>(spBaseVal<int>)> testFunction = [](spBaseVal<int> x) {return mkSpBaseVal<int>(ft_isprint(x->getVal()));};

	for (int letter = -300; letter <= 300; ++letter)
	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(letter));
	}
}
