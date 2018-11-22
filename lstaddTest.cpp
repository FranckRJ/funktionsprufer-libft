#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "lstVal.hpp"
#include "voidVal.hpp"
#include "lstaddTest.hpp"

lstaddTest::lstaddTest()
{
#if defined(FT_LSTADD_EXIST) && defined(TYPE_LST_EXIST)
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int lstaddTest::launchTest()
{
	lstaddTest test;

	test.startTest("ft_lstadd(t_list **alst, t_list *new)");

	return test.errCount;
}

void lstaddTest::processTest()
{
#if defined(FT_LSTADD_EXIST) && defined(TYPE_LST_EXIST)
	spLstVal baseLst = mkSpLstVal(nullptr, "*alst", true);
	spLstVal testLst = mkSpLstVal(nullptr, "*alst", true);
	spLstVal baseNewElem = mkSpLstVal(nullptr, "new");
	spLstVal testNewElem = mkSpLstVal(nullptr, "new");
	std::function<spVoidVal(spLstVal, spLstVal)> baseFunction =
		[&](spLstVal alst, spLstVal new_elem)
		{
			(void)alst;
			(void)new_elem;
			if (!(baseLst->getIsVoidVal()) && baseNewElem->getVal() != nullptr)
			{
				baseNewElem->getVal()->next = baseLst->getVal();
				baseLst->setValWithoutFree(baseNewElem->getVal());
			}
			return mkSpVoidVal();
		};
	std::function<spVoidVal(spLstVal, spLstVal)> testFunction =
		[&](spLstVal alst, spLstVal new_elem)
		{
			(void)alst;
			(void)new_elem;
			if (testLst->getIsVoidVal())
			{
				ft_lstadd(nullptr, testNewElem->getVal());
			}
			else
			{
				t_list *tmpLst = testLst->getVal();
				ft_lstadd(&tmpLst, testNewElem->getVal());
				testLst->setValWithoutFree(tmpLst);
			}
			return mkSpVoidVal();
		};
	auto testValsFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spLstVal, spLstVal>(baseLst, testLst), std::pair<spBaseVal<bool>, spBaseVal<bool>>(
					mkSpBaseVal<bool>(baseLst->getIsVoidVal() || baseLst->getVal() == baseNewElem->getVal(), "*alst == new"),
					mkSpBaseVal<bool>(testLst->getIsVoidVal() || testLst->getVal() == testNewElem->getVal(), "*alst == new")));};

	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, baseNewElem);
	}
	{
		t_list *newBaseNewElem = new t_list;
		newBaseNewElem->content = (void*)(new char[10]());
		newBaseNewElem->content_size = 10;
		newBaseNewElem->next = nullptr;
		baseNewElem->setVal(newBaseNewElem);

		t_list *newTestNewElem = new t_list;
		newTestNewElem->content = (void*)(new char[10]());
		newTestNewElem->content_size = 10;
		newTestNewElem->next = nullptr;
		testNewElem->setVal(newTestNewElem);

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, baseNewElem);
	}
	{
		t_list *newBaseLst = new t_list;
		newBaseLst->content = (void*)(new char[10]());
		newBaseLst->content_size = 10;
		newBaseLst->next = nullptr;
		baseLst->setVal(newBaseLst);

		t_list *newTestLst = new t_list;
		newTestLst->content = (void*)(new char[10]());
		newTestLst->content_size = 10;
		newTestLst->next = nullptr;
		testLst->setVal(newTestLst);

		baseNewElem->setVal(nullptr);
		testNewElem->setVal(nullptr);

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, baseNewElem);
	}
	{
		t_list *newBaseLst = new t_list;
		newBaseLst->content = (void*)(new char[10]());
		newBaseLst->content_size = 10;
		newBaseLst->next = nullptr;
		baseLst->setVal(newBaseLst);

		t_list *newTestLst = new t_list;
		newTestLst->content = (void*)(new char[10]());
		newTestLst->content_size = 10;
		newTestLst->next = nullptr;
		testLst->setVal(newTestLst);

		t_list *newBaseNewElem = new t_list;
		newBaseNewElem->content = (void*)(new char[10]());
		((char*)(newBaseNewElem->content))[0] = 'o';
		newBaseNewElem->content_size = 10;
		newBaseNewElem->next = nullptr;
		baseNewElem->setVal(newBaseNewElem);

		t_list *newTestNewElem = new t_list;
		newTestNewElem->content = (void*)(new char[10]());
		((char*)(newTestNewElem->content))[0] = 'o';
		newTestNewElem->content_size = 10;
		newTestNewElem->next = nullptr;
		testNewElem->setVal(newTestNewElem);

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, baseNewElem);
	}
	{
		baseLst->setName("alst");
		baseLst->setIsVoidVal(true);
		baseLst->setVal(nullptr);
		testLst->setName("alst");
		testLst->setIsVoidVal(true);
		testLst->setVal(nullptr);

		baseNewElem->setVal(nullptr);
		testNewElem->setVal(nullptr);

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, baseNewElem);
	}
	{
		baseLst->setName("alst");
		baseLst->setIsVoidVal(true);
		baseLst->setVal(nullptr);
		testLst->setName("alst");
		testLst->setIsVoidVal(true);
		testLst->setVal(nullptr);

		t_list *newBaseNewElem = new t_list;
		newBaseNewElem->content = (void*)(new char[10]());
		newBaseNewElem->content_size = 10;
		newBaseNewElem->next = nullptr;
		baseNewElem->setVal(newBaseNewElem);

		t_list *newTestNewElem = new t_list;
		newTestNewElem->content = (void*)(new char[10]());
		newTestNewElem->content_size = 10;
		newTestNewElem->next = nullptr;
		testNewElem->setVal(newTestNewElem);

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, baseNewElem);
	}
#endif
}
