#include <iostream>

#include "colors.hpp"

template <class Tret, class... Tpar>
void absTest::testThisFun(std::function<Tret(Tpar...)> baseFun,
						  std::function<Tret(Tpar...)> testFun,
						  Tpar... params)
{
	Tret baseRet;
	Tret testRet;
	bool success;

	if (isVerbose && !showOnlyErrors)
	{
		std::cout << "Parametre : ";
		printParamsVal(params...);
		std::cout << std::endl;
	}

	baseRet = baseFun(params...);
	testRet = testFun(params...);
	success = (baseRet->equalsAnyType(testRet));
	++testCount;

	if (isVerbose && showOnlyErrors && !success)
	{
		std::cout << "Parametre : ";
		printParamsVal(params...);
		std::cout << std::endl;
	}

	if (!success)
	{
		errCount += 1;
	}

	if ((!showOnlyErrors && isVerbose) || (showOnlyErrors && isVerbose && !success))
	{
		std::cout << "Retour fonction base : \"" << baseRet->valToString() << "\"" << std::endl;
		std::cout << "Retour fonction test : \"" << testRet->valToString() << "\"" << std::endl;

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

template <class Tvalbase, class Tvaltest>
void absTest::testThisVal(Tvalbase baseVal, Tvaltest testVal)
{
	bool success;

	success = (baseVal->equalsAnyType(testVal));
	++testCount;

	if (!success)
	{
		errCount += 1;
	}

	if ((!showOnlyErrors && isVerbose) || (showOnlyErrors && isVerbose && !success))
	{
		std::cout << "Valeur base : \"" << baseVal->valToString() << "\"" << std::endl;
		std::cout << "Valeur test : \"" << testVal->valToString() << "\"" << std::endl;

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

	if (isVerbose && !showOnlyErrors)
	{
		std::cout << "Parametre : ";
		printParamsVal(params...);
		std::cout << std::endl;
	}

	baseRet = baseFun(params...);
	testRet = testFun(params...);
	funSuccess = (baseRet->equalsAnyType(testRet));
	funAndValsSuccess = funSuccess && valsToTest(false);
	++testCount;

	if (isVerbose && showOnlyErrors && !funAndValsSuccess)
	{
		std::cout << "Parametre : ";
		printParamsVal(params...);
		std::cout << std::endl;
	}

	if (!funAndValsSuccess)
	{
		errCount += 1;
	}

	if ((!showOnlyErrors && isVerbose) || (showOnlyErrors && isVerbose && !funAndValsSuccess))
	{
		if (!baseRet->getIsVoidVal() && !testRet->getIsVoidVal())
		{
			std::cout << "Retour fonction base : \"" << baseRet->valToString() << "\"" << std::endl;
			std::cout << "Retour fonction test : \"" << testRet->valToString() << "\"";
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
	return fstSuccess && compareVals(printRes, othVals...);
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

template <class Tfstpar>
void absTest::printParamsVal(Tfstpar param)
{
	if (!param->getName().empty())
	{
		std::cout << param->getName() << "=";
	}
	std::cout << "\"" << param->valToString() << "\"";
}

template <class Tfstpar, class... Tothpar>
void absTest::printParamsVal(Tfstpar fstParam, Tothpar... othParams)
{
	printParamsVal(fstParam);
	std::cout << ", ";
	printParamsVal(othParams...);
}
