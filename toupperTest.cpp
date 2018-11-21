#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "toupperTest.hpp"

toupperTest::toupperTest()
{
#ifdef FT_TOUPPER_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int toupperTest::launchTest()
{
	toupperTest test;

	test.startTest("ft_toupper(int c)");

	return test.errCount;
}

void toupperTest::processTest()
{
#ifdef FT_TOUPPER_EXIST
	std::function<spBaseVal<int>(spBaseVal<int>)> baseFunction = [](spBaseVal<int> x) {return mkSpBaseVal<int>(toupper(x->getVal()));};
	std::function<spBaseVal<int>(spBaseVal<int>)> testFunction = [](spBaseVal<int> x) {return mkSpBaseVal<int>(ft_toupper(x->getVal()));};

	for (int letter = -300; letter <= 300; ++letter)
	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(letter));
	}
#endif
}
