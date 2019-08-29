#include "ft_printf.h"

char    *ft_print_d(var *s)
{
	char*    str;


	str = s->data;
	if (s->arg_sign == -1)
		str = ft_strjoin("-", str);
	return (str);
}