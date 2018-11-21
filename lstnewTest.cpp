#include <functional>

#include "libft.h"
#include "baseVal.hpp"
#include "cstStrVal.hpp"
#include "lstVal.hpp"
#include "lstnewTest.hpp"

lstnewTest::lstnewTest()
{
#if defined(FT_LSTNEW_EXIST) && defined(TYPE_LST_EXIST)
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int lstnewTest::launchTest()
{
	lstnewTest test;

	test.startTest("ft_lstnew(void const *content, size_t content_size)");

	return test.errCount;
}

void lstnewTest::processTest()
{
#if defined(FT_LSTNEW_EXIST) && defined(TYPE_LST_EXIST)
	spCstStrVal contentParam = mkSpCstStrVal(nullptr, "content");
	spLstVal baseRet = mkSpLstVal(nullptr, "", true);
	spLstVal testRet = mkSpLstVal(nullptr, "", true);
	std::function<spLstVal(spCstStrVal, spBaseVal<size_t>)> baseFunction =
		[&](spCstStrVal content, spBaseVal<size_t> content_size)
		{
			t_list *lst = nullptr;
			try
			{
				lst = new t_list;
				lst->next = nullptr;
				if (content->getVal() != nullptr)
				{
					lst->content_size = content_size->getVal();
					lst->content = new char[lst->content_size];
					std::memcpy(lst->content, content->getVal(), lst->content_size);
				}
				else
				{
					lst->content = nullptr;
					lst->content_size = 0;
				}
				baseRet->setVal(lst);
				return baseRet;
			}
			catch (...)
			{
				if (lst != nullptr)
				{
					delete lst;
				}
				baseRet->setVal(nullptr);
				return baseRet;
			}
		};
	std::function<spLstVal(spCstStrVal, spBaseVal<size_t>)> testFunction =
		[&](spCstStrVal content, spBaseVal<size_t> content_size)
		{
			testRet->setVal((ft_lstnew(content->getVal(), content_size->getVal())));
			return testRet;
		};
	auto testValsFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spBaseVal<bool>, spBaseVal<bool>>(
					mkSpBaseVal<bool>(baseRet->getVal() == nullptr || (contentParam->getVal() == nullptr && baseRet->getVal()->content == nullptr)
						|| baseRet->getVal()->content != contentParam->getVal(), "ret->content != content"),
					mkSpBaseVal<bool>(testRet->getVal() == nullptr || (contentParam->getVal() == nullptr && testRet->getVal()->content == nullptr)
						|| testRet->getVal()->content != contentParam->getVal(), "ret->content != content")));};

	testThisFunAndVals(baseFunction, testFunction, testValsFun, contentParam, mkSpBaseVal<size_t>(0, "content_size"));
	testThisFunAndVals(baseFunction, testFunction, testValsFun, contentParam, mkSpBaseVal<size_t>(10, "content_size"));
	testThisFunAndVals(baseFunction, testFunction, testValsFun, contentParam, mkSpBaseVal<size_t>(-1, "content_size"));
	testThisFunAndVals(baseFunction, testFunction, testValsFun, contentParam, mkSpBaseVal<size_t>(-10, "content_size"));

	{
		char tab[] = "lol";
		contentParam->setVal(tab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, contentParam, mkSpBaseVal<size_t>(sizeof(tab), "content_size"));
	}
	{
		char tab[] = "";
		contentParam->setVal(tab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, contentParam, mkSpBaseVal<size_t>(sizeof(tab), "content_size"));
	}
	{
		char tab[] = "lol";
		contentParam->setVal(tab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, contentParam, mkSpBaseVal<size_t>(0, "content_size"));
	}
	{
		char tab[] = "lol";
		contentParam->setVal(tab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, contentParam, mkSpBaseVal<size_t>(-1, "content_size"));
	}
	{
		char tab[] = "lol";
		contentParam->setVal(tab);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, contentParam, mkSpBaseVal<size_t>(-10, "content_size"));
	}
#endif
}
