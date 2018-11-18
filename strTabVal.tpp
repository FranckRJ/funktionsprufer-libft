template <class T>
void strTabVal::setVal(T newVal)
{
	if (needToFree)
	{
		deleteCurrentTab();
	}
	absVal::setVal(newVal);
}
