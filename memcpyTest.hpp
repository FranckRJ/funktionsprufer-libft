#ifndef MEMCPYTEST_HPP
#define MEMCPYTEST_HPP

#include "absTest.hpp"

class memcpyTest : absTest
{
public:
	memcpyTest();
	static int launchTest();
protected:
	void processTest();
};

#endif
