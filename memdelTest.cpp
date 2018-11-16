#include <functional>

#include "libft.h"
#include "voidVal.hpp"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "memdelTest.hpp"

int memdelTest::launchTest()
{
	memdelTest test;

	test.startTest("ft_memdel(void **ap)");

	return test.errCount;
}

void memdelTest::processTest()
{
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
	std::function<spVoidVal(spMemVal)> testFunction =
		[&](spMemVal ap)
		{
			(void)ap;
			void *newAp = testAp->getVal();
			ft_memdel(&newAp);
			testAp->setVal(newAp);
			return mkSpVoidVal();
		};
	auto testValsFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spMemVal, spMemVal>(baseAp, testAp));};

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
}
