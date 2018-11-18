read -r -d '' START << EOM
#ifndef FUNEXISTDEFINES_HPP
#define FUNEXISTDEFINES_HPP\n
EOM

read -r -d '' END << EOM
\n#endif
EOM

echo "$START" > funExistDefines.hpp
echo "$(cat libft.h | sed -n "s/.*\(ft_[^\\(]*\).*/#define \1_EXIST/p" | awk '{print toupper($0)}' | sed "s/#DEFINE/#define/g")" >> funExistDefines.hpp
echo "$END" >> funExistDefines.hpp
