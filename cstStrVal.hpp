#ifndef CSTSTRVAL_HPP
#define CSTSTRVAL_HPP

#include <string>
#include <memory>

#include "absVal.hpp"

class cstStrVal;

using spCstStrVal = std::shared_ptr<cstStrVal>;

template <class... Args>
spCstStrVal mkSpCstStrVal(Args... args)
{
	return std::make_shared<cstStrVal>(std::forward<Args>(args)...);
}

class cstStrVal : public absVal<const char*>
{
public:
	cstStrVal(const char *newVal, std::string newName = "", bool newNeedToFree = false);
	~cstStrVal();
	bool equalsSameType(spAbsVal<const char*> cmpVal);
	template <class T>
	void setVal(T newVal);
	std::string valToString();
private:
	bool needToFree;
};

#include "cstStrVal.tpp"

#endif
