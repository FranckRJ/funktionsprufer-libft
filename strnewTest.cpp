#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "strnewTest.hpp"

strnewTest::strnewTest()
{
#ifdef FT_STRNEW_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strnewTest::launchTest()
{
	strnewTest test;

	test.startTest("ft_strnew(size_t size)");

	return test.errCount;
}

void strnewTest::processTest()
{
#ifdef FT_STRNEW_EXIST
	std::function<spMemVal(spBaseVal<size_t>)> baseFunction =
		[&](spBaseVal<size_t> size)
		{
			size_t	size_to_use;

			size_to_use = size->getVal() + 1;
			if (size_to_use > size->getVal())
			{
				char *tab;
				try
				{
					tab = new char[size_to_use];
					std::fill_n(tab, size_to_use, '\0');
				}
				catch (...)
				{
					tab = nullptr;
				}
				return mkSpMemVal(tab, size_to_use, "", true);
			}
			else
			{
				return mkSpMemVal(nullptr, 0);
			}
		};
	std::function<spMemVal(spBaseVal<size_t>)> testFunction =
		[&](spBaseVal<size_t> size)
		{
			return mkSpMemVal(ft_strnew(size->getVal()), size->getVal() + 1, "", true);
		};

	if (!dontDoUnclearTest)
	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<size_t>(-1));
	}

	{
		testThisFun(baseFunction, testFunction, mkSpBaseVal<size_t>(-2));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<size_t>(-3));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<size_t>(0));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<size_t>(1));
		testThisFun(baseFunction, testFunction, mkSpBaseVal<size_t>(50));
	}
#endif
}
