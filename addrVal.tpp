template <class T>
void addrVal::setVal(T newVal)
{
	if (needToFree && getVal() != nullptr)
	{
		delete[] static_cast<char*>(getVal());
	}
	absVal::setVal(newVal);
}
