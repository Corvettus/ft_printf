#include "ft_printf.h"

static void ft_fil_whitespaces(char** str, int wdth, int* i)
{
	while (wdth > 1)
		{
			*str[*i++] = ' ';
			--wdth;
		}
}

char    *ft_print_c(var *s)
{
	char*   str;
	int     wdth;
	int     i;

	wdth = s->width;
	if (!wdth)
		++wdth;
	if (!(str = ft_strnew(wdth)))
		return (0);
	i = 0;
	if (s->flag != '-')
		ft_fil_whitespaces(&str, wdth, &i);
	str[i++] = (char)*s->data;
	if (s->flag == '-')
		ft_fil_whitespaces(&str, wdth, &i);
	return (str);
}