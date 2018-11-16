#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cstStrVal.hpp"
#include "cppStrVal.hpp"
#include "strjoinTest.hpp"

int strjoinTest::launchTest()
{
	strjoinTest test;

	test.startTest("ft_strjoin(char const *s1, char const *s2)");

	return test.errCount;
}

void strjoinTest::processTest()
{
	spCstStrVal s1Test = mkSpCstStrVal(nullptr);
	spCstStrVal s2Test = mkSpCstStrVal(nullptr);
	spStrVal resTest = mkSpStrVal(nullptr, "", true);
	std::function<spStrVal(spCstStrVal, spCstStrVal)> baseFunction =
		[&](spCstStrVal s1, spCstStrVal s2)
		{
			if (s1->getVal() != nullptr && s2->getVal() != nullptr)
			{
				std::string tmpVal = std::string(s1->getVal()) + std::string(s2->getVal());
				char *cstr = new char[tmpVal.length() + 1];
				std::strcpy(cstr, tmpVal.c_str());
				return mkSpStrVal(cstr, "", true);
			}
			else
			{
				return mkSpStrVal(nullptr);
			}
		};
	std::function<spStrVal(spCstStrVal, spCstStrVal)> testFunction =
		[&](spCstStrVal s1, spCstStrVal s2)
		{
			resTest->setVal(ft_strjoin(s1->getVal(), s2->getVal()));
			return resTest;
		};
	auto testValsFun =
		[&](bool printRes)
		{
			return compareVals(printRes, std::pair<spBaseVal<bool>, spBaseVal<bool>>(
						mkSpBaseVal<bool>(true, "res != s1 && res != s2"),
						mkSpBaseVal<bool>(((resTest->getVal() == nullptr && (s1Test->getVal() == nullptr || s2Test->getVal() == nullptr)) ||
								(resTest->getVal() != s1Test->getVal() && resTest->getVal() != s2Test->getVal())), "res != s1 && res != s2")));
		};

	if (!dontDoPotentialCrashTest)
	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, s1Test, s2Test);
		char s1Val[] = "lol";
		s1Test->setVal(s1Val);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, s1Test, s2Test);
		char s2Val[] = "lol";
		s1Test->setVal(nullptr);
		s2Test->setVal(s2Val);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, s1Test, s2Test);
	}

	{
		char s1Val[] = "";
		char s2Val[] = "";
		s1Test->setVal(s1Val);
		s2Test->setVal(s2Val);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, s1Test, s2Test);
	}

	{
		char s1Val[] = "salut";
		char s2Val[] = "";
		s1Test->setVal(s1Val);
		s2Test->setVal(s2Val);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, s1Test, s2Test);
	}

	{
		char s1Val[] = "";
		char s2Val[] = "salut";
		s1Test->setVal(s1Val);
		s2Test->setVal(s2Val);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, s1Test, s2Test);
	}

	{
		char s1Val[] = "s";
		char s2Val[] = "";
		s1Test->setVal(s1Val);
		s2Test->setVal(s2Val);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, s1Test, s2Test);
	}

	{
		char s1Val[] = "";
		char s2Val[] = "s";
		s1Test->setVal(s1Val);
		s2Test->setVal(s2Val);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, s1Test, s2Test);
	}

	{
		char s1Val[] = "salut";
		char s2Val[] = "truc";
		s1Test->setVal(s1Val);
		s2Test->setVal(s2Val);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, s1Test, s2Test);
	}

	{
		char s1Val[] = "t";
		char s2Val[] = "salut";
		s1Test->setVal(s1Val);
		s2Test->setVal(s2Val);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, s1Test, s2Test);
	}

	{
		char s1Val[] = "ok bonjour";
		char s2Val[] = "non pas";
		s1Test->setVal(s1Val);
		s2Test->setVal(s2Val);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, s1Test, s2Test);
	}

	{
		char s1Val[] = "ok\0mdr";
		char s2Val[] = "ah";
		s1Test->setVal(s1Val);
		s2Test->setVal(s2Val);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, s1Test, s2Test);
	}

	{
		char s1Val[] = "ah\0truc";
		char s2Val[] = "oh\0machin";
		s1Test->setVal(s1Val);
		s2Test->setVal(s2Val);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, s1Test, s2Test);
	}
}
