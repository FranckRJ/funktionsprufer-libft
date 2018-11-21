#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "isdigitTest.hpp"

isdigitTest::isdigitTest()
{
#ifdef FT_ISDIGIT_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int isdigitTest::launchTest()
{
	isdigitTest test;

	test.startTest("ft_isdigit(int c)");

	return test.errCount;
}

void isdigitTest::processTest()
{
#ifdef FT_ISDIGIT_EXIST
	std::function<spBaseVal<int>(spBaseVal<int>)> baseFunction = [](spBaseVal<int> x) {return mkSpBaseVal<int>(isdigit(x->getVal()));};
	std::function<spBaseVal<int>(spBaseVal<int>)> testFunction = [](spBaseVal<int> x) {return mkSpBaseVal<int>(ft_isdigit(x->getVal()));};

	for (int letter = -300; letter <= 300; ++letter)
	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(letter));
	}
#endif
}
