#include <functional>

#include "libft.h"
#include "voidVal.hpp"
#include "lstVal.hpp"
#include "cstStrVal.hpp"
#include "lstiterTest.hpp"

#if defined(FT_LSTITER_EXIST) && defined(TYPE_LST_EXIST)
static int count = 0;

static void lstiter_f(t_list *elem)
{
	((char*)(elem->content))[0] = '0' + count;
	++count;
}
#endif

lstiterTest::lstiterTest()
{
#if defined(FT_LSTITER_EXIST) && defined(TYPE_LST_EXIST)
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int lstiterTest::launchTest()
{
	lstiterTest test;

	test.startTest("ft_lstiter(t_list *lst, void (*f)(t_list *elem)");

	return test.errCount;
}

void lstiterTest::processTest()
{
#if defined(FT_LSTITER_EXIST) && defined(TYPE_LST_EXIST)
	char funProt[] = "void (*f)(t_list *elem)";
	spLstVal baseLst = mkSpLstVal(nullptr, "lst", true);
	spLstVal testLst = mkSpLstVal(nullptr, "lst", true);
	std::function<spVoidVal(spLstVal, spCstStrVal)> baseFunction =
		[&](spLstVal lst, spCstStrVal f)
		{
			count = 0;
			(void)lst;
			if (f->getVal() != nullptr)
			{
				t_list *tmpLst = baseLst->getVal();
				while (tmpLst != nullptr)
				{
					lstiter_f(tmpLst);
					tmpLst = tmpLst->next;
				}
			}
			return mkSpVoidVal();
		};
	std::function<spVoidVal(spLstVal, spCstStrVal)> testFunction =
		[&](spLstVal lst, spCstStrVal f)
		{
			count = 0;
			(void)lst;
			ft_lstiter(testLst->getVal(), (f->getVal() == nullptr ? nullptr : lstiter_f));
			return mkSpVoidVal();
		};
	auto testValsFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spLstVal, spLstVal>(baseLst, testLst));};

	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(nullptr, "f"));
	}
	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(funProt, "f"));
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

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(nullptr, "f"));
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

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(funProt, "f"));
	}
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

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(nullptr, "f"));
	}
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

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(funProt, "f"));
	}
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

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(nullptr, "f"));
	}
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

		testThisFunAndVals(baseFunction, testFunction, testValsFun, baseLst, mkSpCstStrVal(funProt, "f"));
	}
#endif
}
