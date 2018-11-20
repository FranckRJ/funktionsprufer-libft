#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cstStrVal.hpp"
#include "cppStrVal.hpp"
#include "strcmpTest.hpp"

strcmpTest::strcmpTest()
{
#ifdef FT_STRCMP_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strcmpTest::launchTest()
{
	strcmpTest test;

	test.startTest("ft_strcmp(const char *s1, const char *s2)");

	return test.errCount;
}

void strcmpTest::processTest()
{
#ifdef FT_STRCMP_EXIST
	spCstStrVal s1ParamTest = mkSpCstStrVal(nullptr);
	spCstStrVal s2ParamTest = mkSpCstStrVal(nullptr);
	std::function<spBaseVal<int>(spCstStrVal, spCstStrVal)> baseFunction =
		[&](spCstStrVal s1, spCstStrVal s2)
		{
			return mkSpBaseVal<int>(strcmp(s1->getVal(), s2->getVal()));
		};
	std::function<spBaseVal<int>(spCstStrVal, spCstStrVal)> testFunction =
		[&](spCstStrVal s1, spCstStrVal s2)
		{
			return mkSpBaseVal<int>(ft_strcmp(s1->getVal(), s2->getVal()));
		};

	if (!dontDoTestThatCrash)
	{
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal(nullptr));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal(""));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpCstStrVal("bon"));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(""), mkSpCstStrVal(nullptr));
		testThisFun(baseFunction, testFunction, mkSpCstStrVal("bon"), mkSpCstStrVal(nullptr));
	}

	{
		char s1Tab[] = "";
		char s2Tab[] = "";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest);
	}
	{
		char s1Tab[] = "salut";
		char s2Tab[] = "salut";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest);
	}
	{
		char s1Tab[] = "salut\0oui";
		char s2Tab[] = "salut\0non";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest);
	}
	{
		char s1Tab[] = "alut";
		char s2Tab[] = "ulut";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest);
	}
	{
		char s1Tab[] = "sala";
		char s2Tab[] = "salu";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest);
	}
	{
		char s1Tab[] = "sala";
		char s2Tab[] = "saba";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest);
	}
	{
		char s1Tab[] = "trou";
		char s2Tab[] = "uort";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest);
	}
	{
		char s1Tab[] = "_ok";
		char s2Tab[] = "aok";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest);
	}
	{
		char s1Tab[] = "_ok";
		char s2Tab[] = "Aok";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest);
	}
	{
		char s1Tab[] = "+ok";
		char s2Tab[] = "|ok";
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest);
	}
	{
		char s1Tab[] = {-5, -10, 0};
		char s2Tab[] = {-5, 0};
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest);
	}
	{
		char s1Tab[] = {-5, -10, 0};
		char s2Tab[] = {-5, 50, 0};
		s1ParamTest->setVal(s1Tab);
		s2ParamTest->setVal(s2Tab);
		testThisFun(baseFunction, testFunction, s1ParamTest, s2ParamTest);
	}
#endif
}
