#ifndef MEMALLOCTEST_HPP
#define MEMALLOCTEST_HPP

#include "absTest.hpp"

class memallocTest : absTest
{
public:
	memallocTest();
	static int launchTest();
protected:
	void processTest();
};

#endif
