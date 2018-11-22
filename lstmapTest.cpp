#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "lstVal.hpp"
#include "cstStrVal.hpp"
#include "lstmapTest.hpp"

#if defined(FT_LSTMAP_EXIST) && defined(TYPE_LST_EXIST)
static int count = 0;
static int countUntilFail = -1;

static t_list *lstmap_f(t_list *elem)
{
	(void)elem;
	if (count != countUntilFail)
	{
		t_list *newLst = new t_list;
		newLst->content = (void*)(new char[5]());
		newLst->content_size = 5;
		newLst->next = nullptr;
		((char*)(newLst->content))[0] = '0' + count;
		++count;
		return newLst;
	}
	else
	{
		return nullptr;
	}
}
#endif

lstmapTest::lstmapTest()
{
#if defined(FT_LSTMAP_EXIST) && defined(TYPE_LST_EXIST)
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int lstmapTest::launchTest()
{
	lstmapTest test;

	test.startTest("ft_lstmap((t_list *lst, t_list *(*f)(t_list *elem))");

	return test.errCount;
}

void lstmapTest::processTest()
{
#if defined(FT_LSTMAP_EXIST) && defined(TYPE_LST_EXIST)
	char funProt[] = "t_list *(*f)(t_list *elem)";
	spLstVal baseLst = mkSpLstVal(nullptr, "lst", true);
	spLstVal testLst = mkSpLstVal(nullptr, "lst", true);
	spLstVal baseRet = mkSpLstVal(nullptr, "", true);
	spLstVal testRet = mkSpLstVal(nullptr, "", true);
	std::function<spLstVal(spLstVal, spCstStrVal, spBaseVal<int>)> baseFunction =
		[&](spLstVal def_lst, spCstStrVal f, spBaseVal<int> fail_at)
		{
			count = 0;
			(void)def_lst;
			(void)fail_at;
			if (f->getVal() != nullptr)
			{
				t_list *lst = baseLst->getVal();
				t_list *newLst = nullptr;
				t_list *curElem = nullptr;
				while (lst != nullptr)
				{
					if (newLst == nullptr)
					{
						newLst = lstmap_f(lst);
						curElem = newLst;
					}
					else
					{
						curElem->next = lstmap_f(lst);
						curElem = curElem->next;
					}
					if (curElem == nullptr)
					{
						baseRet->setVal(nullptr);
						return baseRet;
					}
					lst = lst->next;
				}
				baseRet->setVal(newLst);
				return baseRet;
			}
			else
			{
				baseRet->setVal(nullptr);
				return baseRet;
			}
		};
	std::function<spLstVal(spLstVal, spCstStrVal, spBaseVal<int>)> testFunction =
		[&](spLstVal def_lst, spCstStrVal f, spBaseVal<int> fail_at)
		{
			count = 0;
			(void)def_lst;
			(void)fail_at;
			testRet->setVal(ft_lstmap(testLst->getVal(), (f->getVal() == nullptr ? nullptr : lstmap_f)));
			return testRet;
		};
	auto testValsFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spLstVal, spLstVal>(baseLst, testLst), std::pair<spBaseVal<bool>, spBaseVal<bool>>(
					mkSpBaseVal<bool>(baseRet->getVal() == nullptr || baseRet->getVal() != baseLst->getVal(), "ret != lst"),
					mkSpBaseVal<bool>(testRet->getVal() == nullptr || testRet->getVal() != testLst->getVal(), "ret != lst")));};

	for (countUntilFail = -1; countUntilFail <= 0; ++countUntilFail)
	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(nullptr, "f"), mkSpBaseVal<int>(countUntilFail, "fail_at"));
	}
	for (countUntilFail = -1; countUntilFail <= 0; ++countUntilFail)
	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(funProt, "f"), mkSpBaseVal<int>(countUntilFail, "fail_at"));
	}
	for (countUntilFail = -1; countUntilFail <= 1; ++countUntilFail)
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

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(nullptr, "f"), mkSpBaseVal<int>(countUntilFail, "fail_at"));
	}
	for (countUntilFail = -1; countUntilFail <= 1; ++countUntilFail)
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

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(funProt, "f"), mkSpBaseVal<int>(countUntilFail, "fail_at"));
	}
	for (countUntilFail = -1; countUntilFail <= 2; ++countUntilFail)
	{
		t_list *newBaseLst = new t_list;
		newBaseLst->content = (void*)(new char[10]());
		newBaseLst->content_size = 10;
		newBaseLst->next = nullptr;
		t_list *newBaseLst2 = new t_list;
		newBaseLst2->content = (void*)(new char[10]());
		newBaseLst2->content_size = 10;
		newBaseLst2->next = newBaseLst;
		baseLst->setVal(newBaseLst2);

		t_list *newTestLst = new t_list;
		newTestLst->content = (void*)(new char[10]());
		newTestLst->content_size = 10;
		newTestLst->next = nullptr;
		t_list *newTestLst2 = new t_list;
		newTestLst2->content = (void*)(new char[10]());
		newTestLst2->content_size = 10;
		newTestLst2->next = newTestLst;
		testLst->setVal(newTestLst2);

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(nullptr, "f"), mkSpBaseVal<int>(countUntilFail, "fail_at"));
	}
	for (countUntilFail = -1; countUntilFail <= 2; ++countUntilFail)
	{
		t_list *newBaseLst = new t_list;
		newBaseLst->content = (void*)(new char[10]());
		newBaseLst->content_size = 10;
		newBaseLst->next = nullptr;
		t_list *newBaseLst2 = new t_list;
		newBaseLst2->content = (void*)(new char[10]());
		newBaseLst2->content_size = 10;
		newBaseLst2->next = newBaseLst;
		baseLst->setVal(newBaseLst2);

		t_list *newTestLst = new t_list;
		newTestLst->content = (void*)(new char[10]());
		newTestLst->content_size = 10;
		newTestLst->next = nullptr;
		t_list *newTestLst2 = new t_list;
		newTestLst2->content = (void*)(new char[10]());
		newTestLst2->content_size = 10;
		newTestLst2->next = newTestLst;
		testLst->setVal(newTestLst2);

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(funProt, "f"), mkSpBaseVal<int>(countUntilFail, "fail_at"));
	}
	for (countUntilFail = -1; countUntilFail <= 3; ++countUntilFail)
	{
		t_list *newBaseLst = new t_list;
		newBaseLst->content = (void*)(new char[10]());
		newBaseLst->content_size = 10;
		newBaseLst->next = nullptr;
		t_list *newBaseLst2 = new t_list;
		newBaseLst2->content = (void*)(new char[10]());
		newBaseLst2->content_size = 10;
		newBaseLst2->next = newBaseLst;
		t_list *newBaseLst3 = new t_list;
		newBaseLst3->content = (void*)(new char[10]());
		newBaseLst3->content_size = 10;
		newBaseLst3->next = newBaseLst2;
		baseLst->setVal(newBaseLst3);

		t_list *newTestLst = new t_list;
		newTestLst->content = (void*)(new char[10]());
		newTestLst->content_size = 10;
		newTestLst->next = nullptr;
		t_list *newTestLst2 = new t_list;
		newTestLst2->content = (void*)(new char[10]());
		newTestLst2->content_size = 10;
		newTestLst2->next = newTestLst;
		t_list *newTestLst3 = new t_list;
		newTestLst3->content = (void*)(new char[10]());
		newTestLst3->content_size = 10;
		newTestLst3->next = newTestLst2;
		testLst->setVal(newTestLst3);

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(nullptr, "f"), mkSpBaseVal<int>(countUntilFail, "fail_at"));
	}
	for (countUntilFail = -1; countUntilFail <= 3; ++countUntilFail)
	{
		t_list *newBaseLst = new t_list;
		newBaseLst->content = (void*)(new char[10]());
		newBaseLst->content_size = 10;
		newBaseLst->next = nullptr;
		t_list *newBaseLst2 = new t_list;
		newBaseLst2->content = (void*)(new char[10]());
		newBaseLst2->content_size = 10;
		newBaseLst2->next = newBaseLst;
		t_list *newBaseLst3 = new t_list;
		newBaseLst3->content = (void*)(new char[10]());
		newBaseLst3->content_size = 10;
		newBaseLst3->next = newBaseLst2;
		baseLst->setVal(newBaseLst3);

		t_list *newTestLst = new t_list;
		newTestLst->content = (void*)(new char[10]());
		newTestLst->content_size = 10;
		newTestLst->next = nullptr;
		t_list *newTestLst2 = new t_list;
		newTestLst2->content = (void*)(new char[10]());
		newTestLst2->content_size = 10;
		newTestLst2->next = newTestLst;
		t_list *newTestLst3 = new t_list;
		newTestLst3->content = (void*)(new char[10]());
		newTestLst3->content_size = 10;
		newTestLst3->next = newTestLst2;
		testLst->setVal(newTestLst3);

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(funProt, "f"), mkSpBaseVal<int>(countUntilFail, "fail_at"));
	}
#endif
}
