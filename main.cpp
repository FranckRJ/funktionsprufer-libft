#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <string>
#include <functional>

#include "colors.hpp"
#include "memsetTest.hpp"
#include "bzeroTest.hpp"
#include "memcpyTest.hpp"
#include "memccpyTest.hpp"
#include "memmoveTest.hpp"
#include "memchrTest.hpp"
#include "memcmpTest.hpp"
#include "strlenTest.hpp"
#include "strdupTest.hpp"
#include "strcpyTest.hpp"
#include "strncpyTest.hpp"
#include "strcatTest.hpp"
#include "strncatTest.hpp"
#include "strlcatTest.hpp"
#include "strchrTest.hpp"
#include "strrchrTest.hpp"
#include "strstrTest.hpp"
#include "strnstrTest.hpp"
#include "strcmpTest.hpp"
#include "strncmpTest.hpp"
#include "atoiTest.hpp"
#include "isalphaTest.hpp"
#include "isdigitTest.hpp"
#include "isalnumTest.hpp"
#include "isasciiTest.hpp"
#include "isprintTest.hpp"
#include "tolowerTest.hpp"
#include "toupperTest.hpp"
#include "memallocTest.hpp"
#include "memdelTest.hpp"
#include "strnewTest.hpp"
#include "strdelTest.hpp"
#include "strclrTest.hpp"
#include "striterTest.hpp"
#include "striteriTest.hpp"
#include "strmapTest.hpp"
#include "strmapiTest.hpp"
#include "strequTest.hpp"
#include "strnequTest.hpp"
#include "strsubTest.hpp"
#include "strjoinTest.hpp"
#include "strtrimTest.hpp"
#include "strsplitTest.hpp"
#include "itoaTest.hpp"
#include "putcharTest.hpp"
#include "putstrTest.hpp"
#include "putendlTest.hpp"
#include "putnbrTest.hpp"
#include "putchar_fdTest.hpp"
#include "putstr_fdTest.hpp"
#include "putendl_fdTest.hpp"
#include "putnbr_fdTest.hpp"
#include "lstnewTest.hpp"
#include "lstdeloneTest.hpp"

static std::string HELP_INFOS =
R"str(DESCRIPTION:
Teste l'ensemble des fonctions de la libft et affiche le nombre d'erreurs.

LISTE DES COMMANDES:
<nom_de_fonction>         Affiche le detail de cette fonction (mode verbeux).
                          Plusieurs fonctions peuvent etres appelees, seuls les fonctions appelees
                          seront testees.
-r<nom_de_fonction>       Desactive les tests de cette fonction en mode non-verbeux.
--erronly                 Affiche uniquement les tests echoues lors du mode verbeux.
--nocrashtest             Ne teste pas les fonctions qui doivent crasher.
--nocolor                 Desactive l'affichage avec des couleurs.
--help                    Affiche cette page d'aide.)str";

int main(int argc, char **argv)
{
	int realArgc = argc - 1;
	int errCount = 0;
	int nbOfFunWithError = 0;
	int funNumberThatDontExist = 0;
	std::map<std::string, std::function<int()>> testList;
	std::list<std::string> removedTests;
	std::string curArg;

	std::cout << std::unitbuf;
	testList.emplace("ft_memset", std::bind(memsetTest::launchTest));
	testList.emplace("ft_bzero", std::bind(bzeroTest::launchTest));
	testList.emplace("ft_memcpy", std::bind(memcpyTest::launchTest));
	testList.emplace("ft_memccpy", std::bind(memccpyTest::launchTest));
	testList.emplace("ft_memmove", std::bind(memmoveTest::launchTest));
	testList.emplace("ft_memchr", std::bind(memchrTest::launchTest));
	testList.emplace("ft_memcmp", std::bind(memcmpTest::launchTest));
	testList.emplace("ft_strlen", std::bind(strlenTest::launchTest));
	testList.emplace("ft_strdup", std::bind(strdupTest::launchTest));
	testList.emplace("ft_strcpy", std::bind(strcpyTest::launchTest));
	testList.emplace("ft_strncpy", std::bind(strncpyTest::launchTest));
	testList.emplace("ft_strcat", std::bind(strcatTest::launchTest));
	testList.emplace("ft_strncat", std::bind(strncatTest::launchTest));
	testList.emplace("ft_strlcat", std::bind(strlcatTest::launchTest));
	testList.emplace("ft_strchr", std::bind(strchrTest::launchTest));
	testList.emplace("ft_strrchr", std::bind(strrchrTest::launchTest));
	testList.emplace("ft_strstr", std::bind(strstrTest::launchTest));
	testList.emplace("ft_strnstr", std::bind(strnstrTest::launchTest));
	testList.emplace("ft_strcmp", std::bind(strcmpTest::launchTest));
	testList.emplace("ft_strncmp", std::bind(strncmpTest::launchTest));
	testList.emplace("ft_atoi", std::bind(atoiTest::launchTest));
	testList.emplace("ft_isalpha", std::bind(isalphaTest::launchTest));
	testList.emplace("ft_isdigit", std::bind(isdigitTest::launchTest));
	testList.emplace("ft_isalnum", std::bind(isalnumTest::launchTest));
	testList.emplace("ft_isascii", std::bind(isasciiTest::launchTest));
	testList.emplace("ft_isprint", std::bind(isprintTest::launchTest));
	testList.emplace("ft_tolower", std::bind(tolowerTest::launchTest));
	testList.emplace("ft_toupper", std::bind(toupperTest::launchTest));
	testList.emplace("ft_memalloc", std::bind(memallocTest::launchTest));
	testList.emplace("ft_memdel", std::bind(memdelTest::launchTest));
	testList.emplace("ft_strnew", std::bind(strnewTest::launchTest));
	testList.emplace("ft_strdel", std::bind(strdelTest::launchTest));
	testList.emplace("ft_strclr", std::bind(strclrTest::launchTest));
	testList.emplace("ft_striter", std::bind(striterTest::launchTest));
	testList.emplace("ft_striteri", std::bind(striteriTest::launchTest));
	testList.emplace("ft_strmap", std::bind(strmapTest::launchTest));
	testList.emplace("ft_strmapi", std::bind(strmapiTest::launchTest));
	testList.emplace("ft_strequ", std::bind(strequTest::launchTest));
	testList.emplace("ft_strnequ", std::bind(strnequTest::launchTest));
	testList.emplace("ft_strsub", std::bind(strsubTest::launchTest));
	testList.emplace("ft_strjoin", std::bind(strjoinTest::launchTest));
	testList.emplace("ft_strtrim", std::bind(strtrimTest::launchTest));
	testList.emplace("ft_strsplit", std::bind(strsplitTest::launchTest));
	testList.emplace("ft_itoa", std::bind(itoaTest::launchTest));
	testList.emplace("ft_putchar", std::bind(putcharTest::launchTest));
	testList.emplace("ft_putstr", std::bind(putstrTest::launchTest));
	testList.emplace("ft_putendl", std::bind(putendlTest::launchTest));
	testList.emplace("ft_putnbr", std::bind(putnbrTest::launchTest));
	testList.emplace("ft_putchar_fd", std::bind(putchar_fdTest::launchTest));
	testList.emplace("ft_putstr_fd", std::bind(putstr_fdTest::launchTest));
	testList.emplace("ft_putendl_fd", std::bind(putendl_fdTest::launchTest));
	testList.emplace("ft_putnbr_fd", std::bind(putnbr_fdTest::launchTest));
	testList.emplace("ft_lstnew", std::bind(lstnewTest::launchTest));
	testList.emplace("ft_lstdelone", std::bind(lstdeloneTest::launchTest));

	for (int i = 1; i < argc; ++i)
	{
		curArg = argv[i];
		if(curArg[0] == '-')
		{
			--realArgc;
			if (curArg.substr(0, 2) == "-r")
			{
				curArg = curArg.substr(2);
				curArg = (curArg.substr(0, 3) == "ft_") ? curArg : "ft_" + curArg;
				removedTests.push_back(curArg);
			}
			else if (curArg == "--erronly")
			{
				absTest::showOnlyErrors = true;
			}
			else if (curArg == "--nocrashtest")
			{
				absTest::dontDoTestThatCrash = true;
			}
			else if (curArg == "--nocolor")
			{
				colors::showColors = false;
			}
			else if (curArg == "--help")
			{
				std::cout << HELP_INFOS << std::endl;
				return 0;
			}
		}
	}

	if (realArgc < 1)
	{
		absTest::isVerbose = false;
		for (const std::pair<std::string, std::function<int()>>& thisFunc : testList)
		{
			if (std::find(removedTests.begin(), removedTests.end(), thisFunc.first) == removedTests.end())
			{
				int tmpResult = thisFunc.second();

				if (tmpResult == -1)
				{
					funNumberThatDontExist += 1;
				}
				else if (tmpResult > 0)
				{
					errCount += tmpResult;
					++nbOfFunWithError;
				}
			}
		}
	}
	else
	{
		absTest::isVerbose = true;
		for (int i = 1; i < argc; ++i)
		{
			std::string strArg = argv[i];
			std::string strToFind = (strArg.substr(0, 3) == "ft_") ? strArg : "ft_" + strArg;
			std::map<std::string, std::function<int()>>::iterator it = testList.find(strToFind);

			if (it != testList.end())
			{
				int tmpResult = it->second();

				if (tmpResult == -1)
				{
					funNumberThatDontExist += 1;
				}
				else if (tmpResult > 0)
				{
					errCount += tmpResult;
					++nbOfFunWithError;
				}
			}
			else if (strArg[0] != '-')
			{
				std::cout << "Erreur : pas de tests pour la fonction " << strArg << "." << std::endl << std::endl;
			}
		}
	}

	std::cout << colors::bold();
	if (errCount == 0)
	{
		std::cout << colors::green();
		std::cout << "Erreurs : 0.";
	}
	else
	{
		std::cout << colors::red();
		std::cout << "Erreurs : " << errCount << ". Fonctions concernees : " << nbOfFunWithError << ".";
	}
	std::cout << colors::reset() << std::endl;
	if (funNumberThatDontExist > 0)
	{
		std::cout << "Fonctions non testees : " << funNumberThatDontExist << std::endl;
	}

	return 0;
}
