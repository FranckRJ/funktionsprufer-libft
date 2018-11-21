#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "cstStrVal.hpp"
#include "strequTest.hpp"

strequTest::strequTest()
{
#ifdef FT_STREQU_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strequTest::launchTest()
{
	strequTest test;

	test.startTest("ft_strequ(char const *s1, char const *s2)");

	return test.errCount;
}

void strequTest::processTest()
{
#ifdef FT_STREQU_EXIST
	std::function<spBaseVal<int>(spCstStrVal, spCstStrVal)> baseFunction =
		[&](spCstStrVal s1, spCstStrVal s2)
		{
			if (s1->getVal() == nullptr || s2->getVal() == nullptr)
			{
				return mkSpBaseVal<int>(s1->getVal() == s2->getVal() ? 1 : 0);
			}
			else
			{
				return mkSpBaseVal<int>(std::string(s1->getVal()) == std::string(s2->getVal()) ? 1 : 0);
			}
		};
	std::function<spBaseVal<int>(spCstStrVal, spCstStrVal)> testFunction =
		[&](spCstStrVal s1, spCstStrVal s2)
		{
			return mkSpBaseVal<int>(ft_strequ(s1->getVal(), s2->getVal()));
		};

	if (!dontDoUnclearTest)
	{
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal(nullptr));
	}

	{
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("salut"), mkSpCstStrVal(nullptr));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(""), mkSpCstStrVal(nullptr));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal("salut"));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal(""));
	}

	{
		char tmpS1Tab[] = {-109, 30, -2, 0};
		char tmpS2Tab[] = {-109, 30, -2, 0};
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(tmpS1Tab), mkSpCstStrVal(tmpS2Tab));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(""), mkSpCstStrVal(""));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("s"), mkSpCstStrVal("s"));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("salut"), mkSpCstStrVal("salut"));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("sal\0ut"), mkSpCstStrVal("sal\0ut"));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("s"), mkSpCstStrVal("salut"));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("salut"), mkSpCstStrVal("s"));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("bon"), mkSpCstStrVal("bonjour"));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("bonjour"), mkSpCstStrVal("bon"));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("bonbon"), mkSpCstStrVal("bon"));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("bon"), mkSpCstStrVal("bonbon"));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("truc"), mkSpCstStrVal("machin"));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("exel"), mkSpCstStrVal("lexec"));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("___"), mkSpCstStrVal("..."));
	}
#endif
}
