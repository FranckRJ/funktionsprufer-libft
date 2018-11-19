#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "strtrimTest.hpp"

#ifdef FT_STRTRIM_EXIST
namespace
{
	std::string& ltrim(std::string& str, const std::string& chars = " \t\n ")
	{
		str.erase(0, str.find_first_not_of(chars));
		return str;
	}

	std::string& rtrim(std::string& str, const std::string& chars = " \t\n ")
	{
		str.erase(str.find_last_not_of(chars) + 1);
		return str;
	}

	std::string& trim(std::string& str, const std::string& chars = " \t\n ")
	{
		return ltrim(rtrim(str, chars), chars);
	}
}
#endif

strtrimTest::strtrimTest()
{
#ifdef FT_STRTRIM_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strtrimTest::launchTest()
{
	strtrimTest test;

	test.startTest("ft_strtrim(char const *s)");

	return test.errCount;
}

void strtrimTest::processTest()
{
#ifdef FT_STRTRIM_EXIST
	spStrVal paramTest = mkSpStrVal(nullptr);
	spStrVal resultTest = mkSpStrVal(nullptr, "", true);
	std::function<spStrVal(spStrVal)> baseFunction =
		[&](spStrVal s)
		{
			if (s->getVal() != nullptr)
			{
				std::string tmpVal = s->getVal();
				trim(tmpVal);
				char *cstr = new char[tmpVal.length() + 1];
				std::strcpy(cstr, tmpVal.c_str());
				return mkSpStrVal(cstr, "", true);
			}
			else
			{
				return mkSpStrVal(nullptr);
			}
		};
	std::function<spStrVal(spStrVal)> testFunction =
		[&](spStrVal s)
		{
			resultTest->setVal(ft_strtrim(s->getVal()));
			return resultTest;
		};
	auto testValsFun =
		[&](bool printRes)
		{
			return compareVals(printRes, std::pair<spBaseVal<bool>, spBaseVal<bool>>(
						mkSpBaseVal<bool>(true, "result != s"),
						mkSpBaseVal<bool>(((resultTest->getVal() == nullptr && paramTest->getVal() == nullptr) ||
								(resultTest->getVal() != paramTest->getVal())), "result != s")));
		};

	if (!dontDoTestThatCrash)
	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, paramTest);
	}

	{
		char testVal[] = "";
		paramTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, paramTest);
	}

	{
		char testVal[] = "salut";
		paramTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, paramTest);
	}

	{
		char testVal[] = " sdfdsf";
		paramTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, paramTest);
	}

	{
		char testVal[] = "         sfsdfsdf";
		paramTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, paramTest);
	}

	{
		char testVal[] = " ";
		paramTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, paramTest);
	}

	{
		char testVal[] = "         ";
		paramTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, paramTest);
	}

	{
		char testVal[] = "sdfsdf ";
		paramTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, paramTest);
	}

	{
		char testVal[] = "sfsdf          ";
		paramTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, paramTest);
	}

	{
		char testVal[] = "  \n  \tsdfsdf\t\t\t";
		paramTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, paramTest);
	}

	{
		char testVal[] = " \tsdfs  \tsd   sdf\tsdfdsf\t";
		paramTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, paramTest);
	}

	{
		char testVal[] = "\vsdfdsf\f";
		paramTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, paramTest);
	}

	{
		char testVal[] = "\rsdfsdf       ";
		paramTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, paramTest);
	}

	{
		char testVal[] = "\n \t";
		paramTest->setVal(testVal);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, paramTest);
	}
#endif
}
