template <class T>
void cstStrVal::setVal(T newVal)
{
	if (needToFree && getVal() != nullptr)
	{
		delete[] getVal();
	}
	absVal::setVal(newVal);
}
