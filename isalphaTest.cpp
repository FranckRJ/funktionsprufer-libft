#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "isalphaTest.hpp"

isalphaTest::isalphaTest()
{
#ifdef FT_ISALPHA_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int isalphaTest::launchTest()
{
	isalphaTest test;

	test.startTest("ft_isalpha(int c)");

	return test.errCount;
}

void isalphaTest::processTest()
{
#ifdef FT_ISALPHA_EXIST
	std::function<spBaseVal<int>(spBaseVal<int>)> baseFunction = [](spBaseVal<int> x) {return mkSpBaseVal<int>(isalpha(x->getVal()));};
	std::function<spBaseVal<int>(spBaseVal<int>)> testFunction = [](spBaseVal<int> x) {return mkSpBaseVal<int>(ft_isalpha(x->getVal()));};

	for (int letter = -300; letter <= 300; ++letter)
	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<int>(letter));
	}
#endif
}
