#ifndef ABSTEST_HPP
#define ABSTEST_HPP

#include <string>
#include <functional>

class absTest
{
public:
	static bool isVerbose;
	static bool showOnlyErrors;
	static bool dontDoPotentialCrashTest;
	virtual ~absTest() = default;
protected:
	void startTest(std::string funName);
	virtual void processTest() = 0;
	template <class Tret, class... Tpar>
	void testThisFun(std::function<Tret(Tpar...)> baseFun,
					 std::function<Tret(Tpar...)> testFun,
					 Tpar... params);
	template <class Tvalbase, class Tvaltest>
	void testThisVal(Tvalbase baseVal, Tvaltest testVal);
	template <class Tret, class... Tpar>
	void testThisFunAndVals(std::function<Tret(Tpar...)> baseFun,
							std::function<Tret(Tpar...)> testFun,
							std::function<bool(bool)> valsToTest,
							Tpar... params);
	template <class Tfstval, class... Tothval>
	bool compareVals(bool printRes, Tfstval fstVal, Tothval... othVals);
	template <class Tfstval>
	bool compareVals(bool printRes, Tfstval val);
private:
	template <class Tfstpar>
	void printParamsVal(Tfstpar param);
	template <class Tfstpar, class... Tothpar>
	void printParamsVal(Tfstpar fstParam, Tothpar... othParams);
	void msgTestBegin(std::string funName);
	void msgTestEnd();
protected:
	int testCount = 0;
	int errCount = 0;
};

#include "absTest.tpp"

#endif
