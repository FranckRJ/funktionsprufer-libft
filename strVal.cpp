#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>

#include "strVal.hpp"

strVal::strVal(char *newVal, std::string newName, bool newNeedToFree) : absVal<char*>(newVal, newName)
{
	needToFree = newNeedToFree;
}

strVal::~strVal()
{
	if (needToFree)
	{
		delete[] getVal();
	}
}

bool strVal::equalsSameType(spAbsVal<char*> cmpVal)
{
	strVal *ptrCmpVal = dynamic_cast<strVal*>(cmpVal.get());

	if (ptrCmpVal != nullptr)
	{
		return (std::string(getVal()) == std::string(ptrCmpVal->getVal()));
	}
	else
	{
		return false;
	}
}

std::string strVal::valToString()
{
	if (getVal() != NULL)
	{
		return std::string(getVal());
	}
	else
	{
		return "NULL";
	}
}
