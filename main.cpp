#include <iostream>
#include <map>
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
#include "strtrimTest.hpp"
#include "itoaTest.hpp"
#include "putcharTest.hpp"
#include "putstrTest.hpp"
#include "putendlTest.hpp"
#include "putnbrTest.hpp"
#include "putchar_fdTest.hpp"
#include "putstr_fdTest.hpp"
#include "putendl_fdTest.hpp"
#include "putnbr_fdTest.hpp"

static std::string HELP_INFOS =
R"str(DESCRIPTION:
Teste l'ensemble des fonctions de la libft et affiche le nombre d'erreurs.

LISTE DES COMMANDES :
<nom_de_fonction>         Affiche le detail de cette fonction (mode verbeux).
                          Plusieurs fonctions peuvent etres appelees, seuls les fonctions appelees
                          seront testees.
--erronly                 Affiche uniquement les tests echoues lors du mode verbeux.
--nopotcrash              Ne teste pas les fonction susceptibles de crasher.
--nocolor                 Desactive l'affichage avec des couleurs.
--help                    Affiche cette page d'aide.)str";

int main(int argc, char **argv)
{
	int realArgc = argc - 1;
	int errcount = 0;
	std::map<std::string, std::function<int()>> testList;
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
	testList.emplace("ft_strtrim", std::bind(strtrimTest::launchTest));
	testList.emplace("ft_itoa", std::bind(itoaTest::launchTest));
	testList.emplace("ft_putchar", std::bind(putcharTest::launchTest));
	testList.emplace("ft_putstr", std::bind(putstrTest::launchTest));
	testList.emplace("ft_putendl", std::bind(putendlTest::launchTest));
	testList.emplace("ft_putnbr", std::bind(putnbrTest::launchTest));
	testList.emplace("ft_putchar_fd", std::bind(putchar_fdTest::launchTest));
	testList.emplace("ft_putstr_fd", std::bind(putstr_fdTest::launchTest));
	testList.emplace("ft_putendl_fd", std::bind(putendl_fdTest::launchTest));
	testList.emplace("ft_putnbr_fd", std::bind(putnbr_fdTest::launchTest));

	for (int i = 1; i < argc; ++i)
	{
		curArg = argv[i];
		if(curArg[0] == '-')
		{
			--realArgc;
			if (curArg == "--erronly")
			{
				absTest::showOnlyErrors = true;
			}
			else if (curArg == "--nopotcrash")
			{
				absTest::dontDoPotentialCrashTest = true;
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
			errcount += thisFunc.second();
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
				errcount += it->second();
			}
			else if (strArg[0] != '-')
			{
				std::cout << "Erreur : fonction " << strArg << " non trouvee." << std::endl << std::endl;
			}
		}
	}

	std::cout << "Erreurs : " << errcount << std::endl;

	return 0;
}
