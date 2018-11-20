#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cstStrVal.hpp"
#include "cppStrVal.hpp"
#include "strncmpTest.hpp"

strncmpTest::strncmpTest()
{
#ifdef FT_STRNCMP_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strncmpTest::launchTest()
{
	strncmpTest test;

	test.startTest("ft_strncmp(const char *s1, const char *s2, size_t n)");

	return test.errCount;
}

void strncmpTest::processTest()
{
#ifdef FT_STRNCMP_EXIST
	spCstStrVal s1ParamTest = mkSpCstStrVal(nullptr);
	spCstStrVal s2ParamTest = mkSpCstStrVal(nullptr);
	std::function<spBaseVal<int>(spCstStrVal, spCstStrVal, spBaseVal<size_t>)> baseFunction =
		[&](spCstStrVal s1, spCstStrVal s2, spBaseVal<size_t> n)
		{
			return mkSpBaseVal<int>(strncmp(s1->getVal(), s2->getVal(), n->getVal()));
		};
	std::function<spBaseVal<int>(spCstStrVal, spCstStrVal, spBaseVal<size_t>)> testFunction =
		[&](spCstStrVal s1, spCstStrVal s2, spBaseVal<size_t> n)
		{
			return mkSpBaseVal<int>(ft_strncmp(s1->getVal(), s2->getVal(), n->getVal()));
		};

	if (!dontDoTestThatCrash)
	{
		for (int i = 1; i <= 2; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal(nullptr), mkSpBaseVal<size_t>(i));
		for (int i = 1; i <= 3; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal(""), mkSpBaseVal<size_t>(i));
		for (int i = 1; i <= 4; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal("bn"), mkSpBaseVal<size_t>(i));
		for (int i = 1; i <= 3; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal(""), mkSpCstStrVal(nullptr), mkSpBaseVal<size_t>(i));
		for (int i = 1; i <= 4; ++i)
			testThisFun(baseFunction, testFunction, mkSpCstStrVal("bn"), mkSpCstStrVal(nullptr), mkSpBaseVal<size_t>(i));
	}

	{
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal(nullptr), mkSpBaseVal<size_t>(0));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal(""), mkSpBaseVal<size_t>(0));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal("bn"), mkSpBaseVal<size_t>(0));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(""), mkSpCstStrVal(nullptr), mkSpBaseVal<size_t>(0));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("bn"), mkSpCstStrVal(nullptr), mkSpBaseVal<size_t>(0));
	}

	for (int i = 0; i <= 3; ++i)
	{
		char s1Tab[] = "";
		char s2Tab[] = "";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest, mkSpBaseVal<size_t>(i));
	}

	for (int i = 0; i <= 7; ++i)
	{
		char s1Tab[] = "salut";
		char s2Tab[] = "salut";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest, mkSpBaseVal<size_t>(i));
	}

	for (int i = 0; i <= 11; ++i)
	{
		char s1Tab[] = "salut\0oui";
		char s2Tab[] = "salut\0non";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest, mkSpBaseVal<size_t>(i));
	}

	for (int i = 0; i <= 6; ++i)
	{
		char s1Tab[] = "alut";
		char s2Tab[] = "ulut";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest, mkSpBaseVal<size_t>(i));
	}

	for (int i = 0; i <= 6; ++i)
	{
		char s1Tab[] = "sala";
		char s2Tab[] = "salu";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest, mkSpBaseVal<size_t>(i));
	}

	for (int i = 0; i <= 6; ++i)
	{
		char s1Tab[] = "sala";
		char s2Tab[] = "saba";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest, mkSpBaseVal<size_t>(i));
	}

	for (int i = 0; i <= 6; ++i)
	{
		char s1Tab[] = "trou";
		char s2Tab[] = "uort";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest, mkSpBaseVal<size_t>(i));
	}

	for (int i = 0; i <= 5; ++i)
	{
		char s1Tab[] = "_ok";
		char s2Tab[] = "aok";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest, mkSpBaseVal<size_t>(i));
	}

	for (int i = 0; i <= 5; ++i)
	{
		char s1Tab[] = "_ok";
		char s2Tab[] = "Aok";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest, mkSpBaseVal<size_t>(i));
	}

	for (int i = 0; i <= 5; ++i)
	{
		char s1Tab[] = "+ok";
		char s2Tab[] = "|ok";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest, mkSpBaseVal<size_t>(i));
	}

	for (int i = 0; i <= 4; ++i)
	{
		char s1Tab[] = {-5, -10, 0};
		char s2Tab[] = {-5, 0};
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest, mkSpBaseVal<size_t>(i));
	}

	for (int i = 0; i <= 4; ++i)
	{
		char s1Tab[] = {-5, -10, 0};
		char s2Tab[] = {-5, 50, 0};
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest, mkSpBaseVal<size_t>(i));
	}
#endif
}
