#ifndef ADDRVAL_HPP
#define ADDRVAL_HPP

#include <string>
#include <memory>

#include "absVal.hpp"

class addrVal;

using spAddrVal = std::shared_ptr<addrVal>;

template <class... Args>
spAddrVal mkSpAddrVal(Args... args)
{
	return std::make_shared<addrVal>(std::forward<Args>(args)...);
}

class addrVal : public absVal<void*>
{
public:
	addrVal(void *newVal, void *newBaseVal, std::string newName = "", bool newNeedToFree = false);
	~addrVal();
	bool equalsSameType(spAbsVal<void*> cmpVal);
	template <class T>
	void setVal(T newVal);
	std::string valToString();
private:
	bool needToFree;
	void *baseVal;
};

#include "addrVal.tpp"

#endif
