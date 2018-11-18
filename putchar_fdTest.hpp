#ifndef PUTCHAR_FDTEST_HPP
#define PUTCHAR_FDTEST_HPP

#include "absTest.hpp"

class putchar_fdTest : absTest
{
public:
	putchar_fdTest();
	static int launchTest();
protected:
	void processTest();
};

#endif
