template <class T>
void strVal::setVal(T newVal)
{
	if (needToFree && getVal() != nullptr)
	{
		delete[] getVal();
	}
	absVal::setVal(newVal);
}
