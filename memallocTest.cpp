#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "memallocTest.hpp"

memallocTest::memallocTest()
{
#ifdef FT_MEMALLOC_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int memallocTest::launchTest()
{
	memallocTest test;

	test.startTest("ft_memalloc(size_t size)");

	return test.errCount;
}

void memallocTest::processTest()
{
#ifdef FT_MEMALLOC_EXIST
	std::function<spMemVal(spBaseVal<size_t>)> baseFunction =
		[&](spBaseVal<size_t> size)
		{
			char *tab;
			try
			{
				tab = new char[size->getVal()];
				std::fill_n(tab, size->getVal(), 0);
			}
			catch (...)
			{
				tab = nullptr;
			}
			return mkSpMemVal(tab, size->getVal(), "", true);
		};
	std::function<spMemVal(spBaseVal<size_t>)> testFunction =
		[&](spBaseVal<size_t> size)
		{
			return mkSpMemVal(ft_memalloc(size->getVal()), size->getVal(), "", true);
		};

	if (!dontDoTestThatCrash)
	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<size_t>(-1));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<size_t>(-2));
	}

	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<size_t>(0));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<size_t>(1));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<size_t>(50));
	}
#endif
}
