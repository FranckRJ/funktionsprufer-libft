#include <iostream>

#include "colors.hpp"
#include "absTest.hpp"

bool absTest::isVerbose = false;
bool absTest::showOnlyErrors = false;
bool absTest::dontDoPotentialCrashTest = false;

void absTest::startTest(std::string funName)
{
	msgTestBegin(funName);
	processTest();
	msgTestEnd();
}

void absTest::msgTestBegin(std::string funName)
{
	std::cout << " --- Test de " << funName << " ---" << std::endl;
}

void absTest::msgTestEnd()
{
	if (!isVerbose)
	{
		std::cout << "Tests passes : " << testCount - errCount << "/" << testCount;
		if (errCount > 0)
		{
			std::cout << colors::bold() + colors::red() << " <----------------- ERREUR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << colors::reset();
		}
		std::cout << std::endl;
	}
	else if (isVerbose && showOnlyErrors && errCount == 0)
	{
		std::cout << "Pas d'erreurs." << std::endl;
	}
	std::cout << std::endl;
}
