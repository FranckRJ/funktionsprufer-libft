#ifndef BZEROTEST_HPP
#define BZEROTEST_HPP

#include "absTest.hpp"

class bzeroTest : absTest
{
public:
	bzeroTest();
	static int launchTest();
protected:
	void processTest();
};

#endif
