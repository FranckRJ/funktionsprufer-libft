read -r -d '' VAR << EOM
#ifndef $(echo "$1"|awk '{print toupper($0)}')TEST_HPP
#define $(echo "$1"|awk '{print toupper($0)}')TEST_HPP

#include "absTest.hpp"

class ${1}Test : absTest
{
public:
	static int launchTest();
protected:
	void processTest();
};

#endif
EOM

read -r -d '' WAR << EOM
#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "cppStrVal.hpp"
#include "${1}Test.hpp"

int ${1}Test::launchTest()
{
	${1}Test test;

	test.startTest("ft_${1}()");

	return test.errCount;
}

void ${1}Test::processTest()
{
	std::function<> baseFunction =
		[&]()
		{
		};
	std::function<> testFunction =
		[&]()
		{
		};
	auto testValsFun =
		[&](bool printRes) {return compareVals(printRes, );};

	{
		testThisFun(baseFunction, testFunction);
	}
}
EOM

echo "$VAR" > ${1}Test.hpp
echo "$WAR" > ${1}Test.cpp
