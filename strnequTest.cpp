#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cstStrVal.hpp"
#include "cppStrVal.hpp"
#include "strnequTest.hpp"

strnequTest::strnequTest()
{
#ifdef FT_STRNEQU_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strnequTest::launchTest()
{
	strnequTest test;

	test.startTest("ft_strnequ(char const *s1, char const *s2, size_t n)");

	return test.errCount;
}

void strnequTest::processTest()
{
#ifdef FT_STRNEQU_EXIST
	std::function<spBaseVal<int>(spCstStrVal, spCstStrVal, spBaseVal<size_t>)> baseFunction =
		[&](spCstStrVal s1, spCstStrVal s2, spBaseVal<size_t> n)
		{
			if (n->getVal() == 0)
			{
				return mkSpBaseVal<int>(1);
			}
			else if (s1->getVal() == nullptr || s2->getVal() == nullptr)
			{
				return mkSpBaseVal<int>(s1->getVal() == s2->getVal() ? 1 : 0);
			}
			else
			{
				return mkSpBaseVal<int>(std::string(s1->getVal()).substr(0, n->getVal()) ==
						std::string(s2->getVal()).substr(0, n->getVal()) ? 1 : 0);
			}
		};
	std::function<spBaseVal<int>(spCstStrVal, spCstStrVal, spBaseVal<size_t>)> testFunction =
		[&](spCstStrVal s1, spCstStrVal s2, spBaseVal<size_t> n)
		{
			return mkSpBaseVal<int>(ft_strnequ(s1->getVal(), s2->getVal(), n->getVal()));
		};

	{
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal(nullptr), mkSpBaseVal<size_t>(0));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal(nullptr), mkSpBaseVal<size_t>(1));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("salut"), mkSpCstStrVal(nullptr), mkSpBaseVal<size_t>(0));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("salut"), mkSpCstStrVal(nullptr), mkSpBaseVal<size_t>(1));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(""), mkSpCstStrVal(nullptr), mkSpBaseVal<size_t>(0));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(""), mkSpCstStrVal(nullptr), mkSpBaseVal<size_t>(1));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal("salut"), mkSpBaseVal<size_t>(0));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal("salut"), mkSpBaseVal<size_t>(1));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal(""), mkSpBaseVal<size_t>(0));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal(""), mkSpBaseVal<size_t>(1));
	}

	{
		char tmpS1Tab[] = {-109, 30, -2, 0};
		char tmpS2Tab[] = {-109, 30, -2, 0};
		for (int i = 0; i <= 5; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal(tmpS1Tab), mkSpCstStrVal(tmpS2Tab), mkSpBaseVal<size_t>(i));
		for (int i = 0; i <= 2; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal(""), mkSpCstStrVal(""), mkSpBaseVal<size_t>(i));
		for (int i = 0; i <= 3; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal("s"), mkSpCstStrVal("s"), mkSpBaseVal<size_t>(i));
		for (int i = 0; i <= 7; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal("salut"), mkSpCstStrVal("salut"), mkSpBaseVal<size_t>(i));
		for (int i = 0; i <= 8; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal("sal\0ut"), mkSpCstStrVal("sal\0ut"), mkSpBaseVal<size_t>(i));
		for (int i = 0; i <= 7; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal("s"), mkSpCstStrVal("salut"), mkSpBaseVal<size_t>(i));
		for (int i = 0; i <= 7; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal("salut"), mkSpCstStrVal("s"), mkSpBaseVal<size_t>(i));
		for (int i = 0; i <= 9; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal("bon"), mkSpCstStrVal("bonjour"), mkSpBaseVal<size_t>(i));
		for (int i = 0; i <= 9; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal("bonjour"), mkSpCstStrVal("bon"), mkSpBaseVal<size_t>(i));
		for (int i = 0; i <= 8; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal("bonbon"), mkSpCstStrVal("bon"), mkSpBaseVal<size_t>(i));
		for (int i = 0; i <= 8; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal("bon"), mkSpCstStrVal("bonbon"), mkSpBaseVal<size_t>(i));
		for (int i = 0; i <= 8; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal("truc"), mkSpCstStrVal("machin"), mkSpBaseVal<size_t>(i));
		for (int i = 0; i <= 6; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal("exel"), mkSpCstStrVal("lexec"), mkSpBaseVal<size_t>(i));
		for (int i = 0; i <= 5; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal("___"), mkSpCstStrVal("..."), mkSpBaseVal<size_t>(i));
	}
#endif
}
