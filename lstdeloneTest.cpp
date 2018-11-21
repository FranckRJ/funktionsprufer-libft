#include <functional>

#include "libft.h"
#include "voidVal.hpp"
#include "cstStrVal.hpp"
#include "lstVal.hpp"
#include "lstdeloneTest.hpp"

#if defined(FT_LSTDELONE_EXIST) && defined(TYPE_LST_EXIST)
static void lstdelone_del(void *content, size_t content_size)
{
	(void)content_size;
	if (content != nullptr)
	{
		delete[] static_cast<const char*>(content);
	}
}
#endif

lstdeloneTest::lstdeloneTest()
{
#if defined(FT_LSTDELONE_EXIST) && defined(TYPE_LST_EXIST)
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int lstdeloneTest::launchTest()
{
	lstdeloneTest test;

	test.startTest("ft_lstdelone((t_list **alst, void (*del)(void *, size_t))");

	return test.errCount;
}

void lstdeloneTest::processTest()
{
#if defined(FT_LSTDELONE_EXIST) && defined(TYPE_LST_EXIST)
	char funProt[] = "void (*del)(void *, size_t)";
	spLstVal baseVal = mkSpLstVal(nullptr, "*alst");
	spLstVal testVal = mkSpLstVal(nullptr, "*alst");
	std::function<spVoidVal(spLstVal, spCstStrVal)> baseFunction =
		[&](spLstVal alst, spCstStrVal del)
		{
			(void)alst;
			t_list *tmpLst = baseVal->getVal();
			if (!(baseVal->getIsVoidVal()) && tmpLst != nullptr)
			{
				if (del->getVal() != nullptr)
				{
					lstdelone_del(tmpLst->content, tmpLst->content_size);
				}
				delete tmpLst;
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
			ft_lstdelone(testVal->getIsVoidVal() ? nullptr : &tmpLst, del->getVal() == nullptr ? nullptr : lstdelone_del);
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
