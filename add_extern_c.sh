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
