#ifndef PUTNBR_FDTEST_HPP
#define PUTNBR_FDTEST_HPP

#include "absTest.hpp"

class putnbr_fdTest : absTest
{
public:
	putnbr_fdTest();
	static int launchTest();
protected:
	void processTest();
};

#endif
