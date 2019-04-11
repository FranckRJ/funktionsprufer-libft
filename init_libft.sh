#!/bin/bash

getLibftFiles="true"
genDefineHeader="true"
makeTests="true"
libftPath="../libft"
libftPathIsCustom="false"

function print_help
{
read -r -d '' HELP_TEXT << EOM
DESCRIPTION:
Recupere, modifie et cree les fichiers necessaires a la compilation de test-libft.

LISTE DES COMMANDES:
<chemin_vers_libft>       Specifie le chemin vers la libft (le dossier contenant libft.a / libft.h).
                          Ne peut etre specifie qu'une seule fois, autrement une erreur se produit.
--nogetlibft              Ne recupere pas les fichiers libft.a / libft.h.
--nogendefh               Ne genere pas le header contenant les definitions d'existance des fonctions.
--nomake                  N'execute pas make a la fin du script.
-h / --help               Affiche cette page d'aide.
EOM

echo "$HELP_TEXT"
}

function add_extern_c_libfth
{
cat "libft.h" | sed "/define LIBFT_H/ a\\
\\
extern \"C\" {\\
" > tmplibft.h
rm libft.h
mv tmplibft.h libft.h
cat "libft.h" | sed "/#endif/ i\\
}\\
\\
" > tmplibft.h
rm libft.h
mv tmplibft.h libft.h
}

function del_cpp_keyword_libfth
{
	sed -i "" "s/ new,/ newPtr,/g" libft.h
	sed -i "" "s/*new,/*newPtr,/g" libft.h
	sed -i "" "s/ new)/ newPtr)/g" libft.h
	sed -i "" "s/*new)/*newPtr)/g" libft.h
	sed -i "" "s/ delete,/ deleteVar,/g" libft.h
	sed -i "" "s/*delete,/*deleteVar,/g" libft.h
	sed -i "" "s/ delete)/ deleteVar)/g" libft.h
	sed -i "" "s/*delete)/*deleteVar)/g" libft.h
	sed -i "" "s/false/False/g" libft.h
	sed -i "" "s/true/True/g" libft.h
}

function make_define_header
{
read -r -d '' START_DEF << EOM
#ifndef FUNEXISTDEFINES_HPP
#define FUNEXISTDEFINES_HPP

EOM

read -r -d '' END_DEF << EOM

#endif
EOM

echo "$START_DEF" > funExistDefines.hpp
echo "$(cat libft.h | sed -n "s/.*\(ft_[^\\(]*\)[\\(].*/#define \1_EXIST/p" | awk '{print toupper($0)}' | sed "s/#DEFINE/#define/g")" >> funExistDefines.hpp
if [[ $(cat libft.h) == *"t_list"* ]]; then
	echo "#define TYPE_LST_EXIST" >> funExistDefines.hpp
fi
echo "$END_DEF" >> funExistDefines.hpp
}

for param in "$@"; do
	if [[ "$param" =~ ^--.* ]]; then
		if [[ "$param" == "--nogetlibft" ]]; then
			getLibftFiles="false"
		elif [[ "$param" == "--nogendefh" ]]; then
			genDefineHeader="false"
		elif [[ "$param" == "--nomake" ]]; then
			makeTests="false"
		elif [[ "$param" == "--help" ]]; then
			print_help
			exit 0
		else
			echo "Erreur: parametre $param inconnu. Utilisez --help pour afficher l'aide."
			exit 0
		fi
	elif [[ "$param" =~ ^-.* ]]; then
		if [[ "$param" == "-h" ]]; then
			print_help
			exit 0
		else
			echo "Erreur: parametre $param inconnu. Utilisez --help pour afficher l'aide."
			exit 0
		fi
	fi
done

for param in "$@"; do
	if [[ ! "$param" =~ ^-.* ]]; then
		if [[ "$libftPathIsCustom" == "false" ]]; then
			libftPath="$param"
			libftPathIsCustom="true"
		else
			echo "Trop d'arguments, le chemin de libft ne peut etre initialise qu'une fois. Utilisez --help pour afficher l'aide."
			exit 0
		fi
	fi
done

if [[ "$getLibftFiles" == "true" ]]; then
	cp "${libftPath}/libft.h" "${libftPath}/libft.a" .
	add_extern_c_libfth
	del_cpp_keyword_libfth
fi
if [[ "$genDefineHeader" == "true" ]]; then
	make_define_header
fi
if [[ "$makeTests" == "true" ]]; then
	make -j4
fi
