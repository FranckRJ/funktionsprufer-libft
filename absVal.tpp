#include <typeinfo>

template <class T>
absVal<T>::absVal(T newVal, std::string newName)
{
	val = newVal;
	name = newName;
}

template <class T>
template <class P>
bool absVal<T>::equalsAnyType(P cmpVal)
{
	if (typeid(val) == typeid(cmpVal->getVal()))
	{
		return equalsSameType(cmpVal);
	}
	else
	{
		return false;
	}
}

template <class T>
bool absVal<T>::equalsSameType(spAbsVal<T> cmpVal)
{
	return val == cmpVal->getVal();
}

template <class T>
T absVal<T>::getVal()
{
	return val;
}

template <class T>
std::string absVal<T>::getName()
{
	return name;
}

template <class T>
bool absVal<T>::getIsVoidVal()
{
	return isVoidVal;
}

template <class T>
void absVal<T>::setVal(T newVal)
{
	val = newVal;
}

template <class T>
void absVal<T>::setIsVoidVal(bool newVal)
{
	isVoidVal = newVal;
}
