#include <functional>

#include "libft.h"
#include "voidVal.hpp"
#include "memVal.hpp"
#include "strclrTest.hpp"

strclrTest::strclrTest()
{
#ifdef FT_STRCLR_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strclrTest::launchTest()
{
	strclrTest test;

	test.startTest("ft_strclr(char *s)");

	return test.errCount;
}

void strclrTest::processTest()
{
#ifdef FT_STRCLR_EXIST
	spMemVal baseS = mkSpMemVal(nullptr, 0, "s");
	spMemVal testS = mkSpMemVal(nullptr, 0, "s");
	std::function<spVoidVal(spMemVal)> baseFunction =
		[&](spMemVal s)
		{
			(void)s;
			if (baseS->getVal() != nullptr)
			{
				bzero(baseS->getVal(), strlen((char*)(baseS->getVal())));
			}
			return mkSpVoidVal();
		};
	std::function<spVoidVal(spMemVal)> testFunction =
		[&](spMemVal s)
		{
			(void)s;
			ft_strclr((char*)(testS->getVal()));
			return mkSpVoidVal();
		};
	auto testValsFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spMemVal, spMemVal>(baseS, testS));};

	testThisFunAndVals(baseFunction, testFunction, testValsFun, baseS);

	{
		char sValBase[] = "";
		char sValTest[] = "";
		baseS->setValAndLen(sValBase, sizeof(sValBase));
		testS->setValAndLen(sValTest, sizeof(sValTest));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseS);
	}

	{
		char sValBase[] = "O";
		char sValTest[] = "O";
		baseS->setValAndLen(sValBase, sizeof(sValBase));
		testS->setValAndLen(sValTest, sizeof(sValTest));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseS);
	}

	{
		char sValBase[] = "SALUT";
		char sValTest[] = "SALUT";
		baseS->setValAndLen(sValBase, sizeof(sValBase));
		testS->setValAndLen(sValTest, sizeof(sValTest));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseS);
	}

	{
		char sValBase[] = "SAL\0UT";
		char sValTest[] = "SAL\0UT";
		baseS->setValAndLen(sValBase, sizeof(sValBase));
		testS->setValAndLen(sValTest, sizeof(sValTest));
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseS);
	}
#endif
}
