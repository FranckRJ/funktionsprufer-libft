#include <functional>
#include <ctype.h>

#include "libft.h"
#include "baseVal.hpp"
#include "tolowerTest.hpp"

int tolowerTest::launchTest()
{
	tolowerTest test;

	test.startTest("ft_tolower(int c)");

	return test.errCount;
}

void tolowerTest::processTest()
{
	std::function<spBaseVal<int>(spBaseVal<int>)> baseFunction = [](spBaseVal<int> x) {return mkSpBaseVal<int>(tolower(x->getVal()));};
	std::function<spBaseVal<int>(spBaseVal<int>)> testFunction = [](spBaseVal<int> x) {return mkSpBaseVal<int>(ft_tolower(x->getVal()));};

	for (int letter = -300; letter <= 300; ++letter)
	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(letter));
	}
}
