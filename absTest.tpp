#include <iostream>
#include <unistd.h>

#include "colors.hpp"

template <class Tret, class... Tpar>
bool absTest::crashTestThisFun(std::function<Tret(Tpar...)> funToTest,
							   Tpar... params)
{
	pid_t childPid = 0;
	int childStatus = 0;
	if ((childPid = fork()) == 0)
	{
		funToTest(params...);
		exit(0);
	}
	else
	{
		waitpid(childPid, &childStatus, 0);
	}
	return childStatus != 0;
}

template <class Tret, class... Tpar>
void absTest::testThisFun(std::function<Tret(Tpar...)> baseFun,
						  std::function<Tret(Tpar...)> testFun,
						  Tpar... params)
{
	Tret baseRet;
	Tret testRet;
	bool success;
	std::string strForParams = (isVerbose ? paramsToString(params...) : "");

	baseRet = buildPtrValOfPtr(baseRet);
	testRet = buildPtrValOfPtr(testRet);

	baseRet->setIsCrashVal(crashTestThisFun(baseFun, params...));
	testRet->setIsCrashVal(crashTestThisFun(testFun, params...));

	if (!(baseRet->getIsCrashVal()))
	{
		baseRet = baseFun(params...);
	}
	if (!(testRet->getIsCrashVal()))
	{
		testRet = testFun(params...);
	}
	success = (baseRet->equalsAnyType(testRet));
	++testCount;

	if (isVerbose && (!showOnlyErrors || (showOnlyErrors && !success)))
	{
		std::cout << "Parametre : " << strForParams << std::endl;
	}

	if (!success)
	{
		errCount += 1;
	}

	if ((!showOnlyErrors && isVerbose) || (showOnlyErrors && isVerbose && !success))
	{
		std::cout << "Retour fonction base : \"" << baseRet->valToStringOrCrash() << "\"" << std::endl;
		std::cout << "Retour fonction test : \"" << testRet->valToStringOrCrash() << "\"" << std::endl;

		if (success)
		{
			std::cout << colors::bold() + colors::green() << "OK" << colors::reset() << std::endl;
		}
		else
		{
			std::cout << colors::bold() + colors::red() << " --- ERREUR" << colors::reset() << std::endl;
		}
	}
}

template <class Tret, class... Tpar>
void absTest::testThisFunAndVals(std::function<Tret(Tpar...)> baseFun,
								 std::function<Tret(Tpar...)> testFun,
								 std::function<bool(bool)> valsToTest,
								 Tpar... params)
{
	Tret baseRet;
	Tret testRet;
	bool funAndValsSuccess;
	bool funSuccess;
	std::string strForParams = (isVerbose ? paramsToString(params...) : "");

	baseRet = buildPtrValOfPtr(baseRet);
	testRet = buildPtrValOfPtr(testRet);

	baseRet->setIsCrashVal(crashTestThisFun(baseFun, params...));
	testRet->setIsCrashVal(crashTestThisFun(testFun, params...));

	if (!(baseRet->getIsCrashVal()))
	{
		baseRet = baseFun(params...);
	}
	if (!(testRet->getIsCrashVal()))
	{
		testRet = testFun(params...);
	}
	funSuccess = (baseRet->equalsAnyType(testRet));
	funAndValsSuccess = funSuccess && valsToTest(false);
	++testCount;

	if (isVerbose && (!showOnlyErrors || (showOnlyErrors && !funAndValsSuccess)))
	{
		std::cout << "Parametre : " << strForParams << std::endl;
	}

	if (!funAndValsSuccess)
	{
		errCount += 1;
	}

	if ((!showOnlyErrors && isVerbose) || (showOnlyErrors && isVerbose && !funAndValsSuccess))
	{
		if (!baseRet->getIsVoidVal() && !testRet->getIsVoidVal())
		{
			std::cout << "Retour fonction base : \"" << baseRet->valToStringOrCrash() << "\"" << std::endl;
			std::cout << "Retour fonction test : \"" << testRet->valToStringOrCrash() << "\"";
			if (!funSuccess)
			{
				std::cout << colors::bold() + colors::red() << " <----- ERREUR !!!" << colors::reset();
			}
			std::cout << std::endl;
		}

		valsToTest(true);

		if (funAndValsSuccess)
		{
			std::cout << colors::bold() + colors::green() << "OK" << colors::reset() << std::endl;
		}
		else
		{
			std::cout << colors::bold() + colors::red() << " --- ERREUR" << colors::reset() << std::endl;
		}
	}
}

template <class Tfstval, class... Tothval>
bool absTest::compareVals(bool printRes, Tfstval fstVal, Tothval... othVals)
{
	bool fstSuccess = compareVals(printRes, fstVal);
	return compareVals(printRes, othVals...) && fstSuccess;
}

template <class Tfstval>
bool absTest::compareVals(bool printRes, Tfstval val)
{
	bool success = val.first->equalsAnyType(val.second);

	if (printRes && ((!showOnlyErrors && isVerbose) || (showOnlyErrors && isVerbose && !success)))
	{
		std::cout << val.first->getName() << " base vaut : \"" << val.first->valToString() << "\"" << std::endl;
		std::cout << val.second->getName() << " test vaut : \"" << val.second->valToString() << "\"";
		if (!success)
		{
			std::cout << colors::bold() + colors::red() << " <----- ERREUR !!!" << colors::reset();
		}
		std::cout << std::endl;
	}

	return success;
}

template <class Tptr>
std::shared_ptr<Tptr> absTest::buildPtrValOfPtr(std::shared_ptr<Tptr> thisPtr)
{
	(void)thisPtr;
	return std::make_shared<Tptr>();
}

template <class Tfstpar>
std::string absTest::paramsToString(Tfstpar param)
{
	std::string newStr;
	if (!param->getName().empty())
	{
		newStr += param->getName() + "=";
	}
	newStr += "\"" + param->valToString() + "\"";
	return newStr;
}

template <class Tfstpar, class... Tothpar>
std::string absTest::paramsToString(Tfstpar fstParam, Tothpar... othParams)
{
	std::string newStr;
	newStr += paramsToString(fstParam);
	newStr += ", ";
	newStr += paramsToString(othParams...);
	return newStr;
}
