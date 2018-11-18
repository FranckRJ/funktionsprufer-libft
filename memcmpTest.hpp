#ifndef MEMCMPTEST_HPP
#define MEMCMPTEST_HPP

#include "absTest.hpp"

class memcmpTest : absTest
{
public:
	memcmpTest();
	static int launchTest();
protected:
	void processTest();
};

#endif
