#include <functional>
#include <vector>

#include "libft.h"
#include "baseVal.hpp"
#include "memVal.hpp"
#include "addrVal.hpp"
#include "strVal.hpp"
#include "strTabVal.hpp"
#include "cstStrVal.hpp"
#include "strsplitTest.hpp"

strsplitTest::strsplitTest()
{
#ifdef FT_STRSPLIT_EXIST
	funToTestExist = true;
#else
	funToTestExist = false;
#endif
}

int strsplitTest::launchTest()
{
	strsplitTest test;

	test.startTest("ft_strsplit(char const *s, char c)");

	return test.errCount;
}

void strsplitTest::processTest()
{
#ifdef FT_STRSPLIT_EXIST
	std::function<spStrTabVal(spCstStrVal, spBaseVal<char>)> baseFunction =
		[&](spCstStrVal s, spBaseVal<char> c)
		{
			if (s->getVal() == nullptr)
			{
				return mkSpStrTabVal(nullptr);
			}
			else
			{
				std::string str = std::string(s->getVal());
				std::string sep = std::string(1, c->getVal());
				std::vector<std::string> listOfSubStr;
				size_t idxFind = 0;
				std::string subStr;

				while ((idxFind = str.find(sep)) != std::string::npos)
				{
					subStr = str.substr(0, idxFind);
					if (subStr.length() > 0)
					{
						listOfSubStr.push_back(subStr);
					}
					str.erase(0, idxFind + sep.length());
				}
				if (str.length() > 0)
				{
					listOfSubStr.push_back(str);
				}
				char **newTab = new char*[listOfSubStr.size() + 1];
				for (size_t i = 0; i < listOfSubStr.size(); ++i)
				{
					char *cstr = new char[listOfSubStr[i].length() + 1];
					std::strcpy(cstr, listOfSubStr[i].c_str());
					newTab[i] = cstr;
				}
				newTab[listOfSubStr.size()] = nullptr;
				return mkSpStrTabVal(newTab, -1, "", true);
			}
		};
	std::function<spStrTabVal(spCstStrVal, spBaseVal<char>)> testFunction =
		[&](spCstStrVal s, spBaseVal<char> c)
		{
			return mkSpStrTabVal(ft_strsplit(s->getVal(), c->getVal()), -1, "", true);
		};

	testThisFun(baseFunction, testFunction, mkSpCstStrVal(nullptr), mkSpBaseVal<char>('a'));

	testThisFun(baseFunction, testFunction, mkSpCstStrVal(""), mkSpBaseVal<char>(','));
	testThisFun(baseFunction, testFunction, mkSpCstStrVal("salut bonjour"), mkSpBaseVal<char>(','));
	testThisFun(baseFunction, testFunction, mkSpCstStrVal("salut,ok"), mkSpBaseVal<char>(','));
	testThisFun(baseFunction, testFunction, mkSpCstStrVal("salut,,,,,ok"), mkSpBaseVal<char>(','));
	testThisFun(baseFunction, testFunction, mkSpCstStrVal(",salut"), mkSpBaseVal<char>(','));
	testThisFun(baseFunction, testFunction, mkSpCstStrVal(",,,salut"), mkSpBaseVal<char>(','));
	testThisFun(baseFunction, testFunction, mkSpCstStrVal(",,,salut,ok"), mkSpBaseVal<char>(','));
	testThisFun(baseFunction, testFunction, mkSpCstStrVal("ok,"), mkSpBaseVal<char>(','));
	testThisFun(baseFunction, testFunction, mkSpCstStrVal("ok,,,,"), mkSpBaseVal<char>(','));
	testThisFun(baseFunction, testFunction, mkSpCstStrVal("salut,ok,,,,"), mkSpBaseVal<char>(','));
	testThisFun(baseFunction, testFunction, mkSpCstStrVal(",,,,salut,,,ok,,,"), mkSpBaseVal<char>(','));
	testThisFun(baseFunction, testFunction, mkSpCstStrVal(","), mkSpBaseVal<char>(','));
	testThisFun(baseFunction, testFunction, mkSpCstStrVal(",,,,"), mkSpBaseVal<char>(','));
#endif
}
