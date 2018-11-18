#ifndef MEMDELTEST_HPP
#define MEMDELTEST_HPP

#include "absTest.hpp"

class memdelTest : absTest
{
public:
	memdelTest();
	static int launchTest();
protected:
	void processTest();
};

#endif
