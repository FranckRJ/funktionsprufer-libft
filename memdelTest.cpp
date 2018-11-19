#include <functional>

#include "libft.h"
#include "voidVal.hpp"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "memdelTest.hpp"

memdelTest::memdelTest()
{
#ifdef FT_MEMDEL_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int memdelTest::launchTest()
{
	memdelTest test;

	test.startTest("ft_memdel(void **ap)");

	return test.errCount;
}

void memdelTest::processTest()
{
#ifdef FT_MEMDEL_EXIST
	spMemVal baseAp = mkSpMemVal(nullptr, 0, "ap");
	spMemVal testAp = mkSpMemVal(nullptr, 0, "ap");
	std::function<spVoidVal(spMemVal)> baseFunction =
		[&](spMemVal ap)
		{
			(void)ap;
			char *newAp = (char*)baseAp->getVal();
			if (newAp != nullptr)
			{
				delete newAp;
				newAp = nullptr;
				baseAp->setVal(newAp);
			}
			return mkSpVoidVal();
		};
	std::function<spVoidVal(spMemVal)> baseNullFunction =
		[&](spMemVal ap)
		{
			(void)ap;
			return mkSpVoidVal();
		};
	std::function<spVoidVal(spMemVal)> testFunction =
		[&](spMemVal ap)
		{
			(void)ap;
			void *newAp = testAp->getVal();
			ft_memdel(&newAp);
			testAp->setVal(newAp);
			return mkSpVoidVal();
		};
	std::function<spVoidVal(spMemVal)> testNullFunction =
		[&](spMemVal ap)
		{
			(void)ap;
			ft_memdel(nullptr);
			return mkSpVoidVal();
		};
	auto testValsFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spMemVal, spMemVal>(baseAp, testAp));};
	auto testNullValsFun =
		[&](bool printRes) {return compareVals(printRes,
				std::pair<spBaseVal<bool>, spBaseVal<bool>>(mkSpBaseVal<bool>(true, "pas crash"), mkSpBaseVal<bool>(true, "pas crash")));};

	if (!dontDoTestThatCrash)
	{
		testThisFunAndVals(baseNullFunction, testNullFunction, testNullValsFun, baseAp);
	}

	{
		baseAp->setVal(nullptr);
		testAp->setVal(nullptr);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseAp);
	}

	{
		baseAp->setVal(new char);
		testAp->setVal(new char);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseAp);
	}
#endif
}
