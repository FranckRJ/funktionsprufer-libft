#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cstStrVal.hpp"
#include "cppStrVal.hpp"
#include "strsubTest.hpp"

strsubTest::strsubTest()
{
#ifdef FT_STRSUB_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strsubTest::launchTest()
{
	strsubTest test;

	test.startTest("ft_strsub(char const *s, unsigned int start, size_t len)");

	return test.errCount;
}

void strsubTest::processTest()
{
#ifdef FT_STRSUB_EXIST
	std::function<spStrVal(spCstStrVal, spBaseVal<unsigned int>, spBaseVal<size_t>)> baseFunction =
		[&](spCstStrVal s, spBaseVal<unsigned int> start, spBaseVal<size_t> len)
		{
			if (s->getVal() == nullptr)
			{
				return mkSpStrVal(nullptr);
			}
			else
			{
				std::string tmpVal = std::string(s->getVal()).substr(start->getVal(), len->getVal());
				char *cstr = new char[tmpVal.length() + 1];
				std::strcpy(cstr, tmpVal.c_str());
				return mkSpStrVal(cstr, "", true);
			}
		};
	std::function<spStrVal(spCstStrVal, spBaseVal<unsigned int>, spBaseVal<size_t>)> testFunction =
		[&](spCstStrVal s, spBaseVal<unsigned int> start, spBaseVal<size_t> len)
		{
			return mkSpStrVal(ft_strsub(s->getVal(), start->getVal(), len->getVal()), "", true);
		};

	testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpBaseVal<unsigned int>(0), mkSpBaseVal<size_t>(0));

	{
		testThisFun(baseFunction, testFunction, mkSpCstStrVal(""), mkSpBaseVal<unsigned int>(0), mkSpBaseVal<size_t>(0));
		for (int i = 0; i <= 8; ++i)
		{
			for (int j = 0; j <= (8 - i); ++j)
			{
				testThisFun(baseFunction, testFunction, mkSpCstStrVal("bon jour"), mkSpBaseVal<unsigned int>(i), mkSpBaseVal<size_t>(j));
			}
		}
	}
#endif
}
