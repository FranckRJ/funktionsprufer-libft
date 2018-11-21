#include <functional>

#include "libft.h"
#include "voidVal.hpp"
#include "lstVal.hpp"
#include "cstStrVal.hpp"
#include "lstdelTest.hpp"

#if defined(FT_LSTDEL_EXIST) && defined(TYPE_LST_EXIST)
static void lstdel_del(void *content, size_t content_size)
{
	(void)content_size;
	if (content != nullptr)
	{
		delete[] static_cast<const char*>(content);
	}
}
#endif

lstdelTest::lstdelTest()
{
#if defined(FT_LSTDEL_EXIST) && defined(TYPE_LST_EXIST)
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int lstdelTest::launchTest()
{
	lstdelTest test;

	test.startTest("ft_lstdel(t_list **alst, void (*del)(void *, size_t))");

	return test.errCount;
}

void lstdelTest::processTest()
{
#if defined(FT_LSTDEL_EXIST) && defined(TYPE_LST_EXIST)
	char funProt[] = "void (*del)(void *, size_t)";
	spLstVal baseVal = mkSpLstVal(nullptr, "*alst");
	spLstVal testVal = mkSpLstVal(nullptr, "*alst");
	std::function<spVoidVal(spLstVal, spCstStrVal)> baseFunction =
		[&](spLstVal alst, spCstStrVal del)
		{
			(void)alst;
			t_list *tmpLst = baseVal->getVal();
			if (!(baseVal->getIsVoidVal()))
			{
				t_list *oldLst = tmpLst;
				t_list *curLst = oldLst;
				while (curLst != nullptr)
				{
					if (del->getVal() != nullptr)
					{
						lstdel_del(curLst->content, curLst->content_size);
					}
					oldLst = curLst;
					curLst = curLst->next;
					delete oldLst;
				}
				tmpLst = nullptr;
			}
			baseVal->setVal(tmpLst);
			return mkSpVoidVal();
		};
	std::function<spVoidVal(spLstVal, spCstStrVal)> testFunction =
		[&](spLstVal alst, spCstStrVal del)
		{
			(void)alst;
			t_list *tmpLst = testVal->getVal();
			ft_lstdel(testVal->getIsVoidVal() ? nullptr : &tmpLst, del->getVal() == nullptr ? nullptr : lstdel_del);
			testVal->setVal(tmpLst);
			return mkSpVoidVal();
		};
	auto testValsFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spLstVal, spLstVal>(baseVal, testVal));};

	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, mkSpCstStrVal(nullptr, "del"));
	}
	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, mkSpCstStrVal(funProt, "del"));
	}
	if (!dontDoUnclearTest)
	{
		t_list *newLstBase = new t_list;
		newLstBase->content = (void*)(new const char[10]());
		newLstBase->content_size = 10;
		newLstBase->next = nullptr;
		baseVal->setVal(newLstBase);
		t_list *newLstTest = new t_list;
		newLstTest->content = (void*)(new const char[10]());
		newLstTest->content_size = 10;
		newLstTest->next = nullptr;
		testVal->setVal(newLstTest);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, mkSpCstStrVal(nullptr, "del"));
	}
	if (!dontDoUnclearTest)
	{
		t_list *newLstBase = new t_list;
		newLstBase->content = nullptr;
		newLstBase->content_size = 0;
		newLstBase->next = nullptr;
		baseVal->setVal(newLstBase);
		t_list *newLstTest = new t_list;
		newLstTest->content = nullptr;
		newLstTest->content_size = 0;
		newLstTest->next = nullptr;
		testVal->setVal(newLstTest);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, mkSpCstStrVal(nullptr, "del"));
	}
	{
		t_list *newLstBase = new t_list;
		newLstBase->content = (void*)(new const char[10]());
		newLstBase->content_size = 10;
		newLstBase->next = nullptr;
		baseVal->setVal(newLstBase);
		t_list *newLstTest = new t_list;
		newLstTest->content = (void*)(new const char[10]());
		newLstTest->content_size = 10;
		newLstTest->next = nullptr;
		testVal->setVal(newLstTest);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, mkSpCstStrVal(funProt, "del"));
	}
	{
		t_list *newLstBase = new t_list;
		newLstBase->content = nullptr;
		newLstBase->content_size = 0;
		newLstBase->next = nullptr;
		baseVal->setVal(newLstBase);
		t_list *newLstTest = new t_list;
		newLstTest->content = nullptr;
		newLstTest->content_size = 0;
		newLstTest->next = nullptr;
		testVal->setVal(newLstTest);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, mkSpCstStrVal(funProt, "del"));
	}
	if (!dontDoUnclearTest)
	{
		t_list *newLstBase = new t_list;
		newLstBase->content = (void*)(new const char[10]());
		newLstBase->content_size = 10;
		baseVal->setVal(newLstBase);
		t_list *newLstBase2 = new t_list;
		newLstBase->next = newLstBase2;
		newLstBase2->content = (void*)(new const char[10]());
		newLstBase2->content_size = 10;
		newLstBase2->next = nullptr;

		t_list *newLstTest = new t_list;
		newLstTest->content = (void*)(new const char[10]());
		newLstTest->content_size = 10;
		testVal->setVal(newLstTest);
		t_list *newLstTest2 = new t_list;
		newLstTest->next = newLstTest2;
		newLstTest2->content = (void*)(new const char[10]());
		newLstTest2->content_size = 10;
		newLstTest2->next = nullptr;

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, mkSpCstStrVal(nullptr, "del"));
	}
	{
		t_list *newLstBase = new t_list;
		newLstBase->content = (void*)(new const char[10]());
		newLstBase->content_size = 10;
		baseVal->setVal(newLstBase);
		t_list *newLstBase2 = new t_list;
		newLstBase->next = newLstBase2;
		newLstBase2->content = (void*)(new const char[10]());
		newLstBase2->content_size = 10;
		newLstBase2->next = nullptr;

		t_list *newLstTest = new t_list;
		newLstTest->content = (void*)(new const char[10]());
		newLstTest->content_size = 10;
		testVal->setVal(newLstTest);
		t_list *newLstTest2 = new t_list;
		newLstTest->next = newLstTest2;
		newLstTest2->content = (void*)(new const char[10]());
		newLstTest2->content_size = 10;
		newLstTest2->next = nullptr;

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, mkSpCstStrVal(funProt, "del"));
	}
	{
		baseVal->setIsVoidVal(true);
		baseVal->setVal(nullptr);
		baseVal->setName("alst");
		testVal->setIsVoidVal(true);
		testVal->setVal(nullptr);
		testVal->setName("alst");
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, mkSpCstStrVal(nullptr, "del"));
	}
	{
		baseVal->setIsVoidVal(true);
		baseVal->setVal(nullptr);
		baseVal->setName("alst");
		testVal->setIsVoidVal(true);
		testVal->setVal(nullptr);
		testVal->setName("alst");
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseVal, mkSpCstStrVal(funProt, "del"));
	}
#endif
}
