#include "ft_printf.h"
#include <stdio.h>

static void ft_fil_whitespaces(char **str, int wdth, int len, int *i)
{
	while (wdth > len)
		{
			*str[*i++] = ' ';
			--wdth;
		}
}

char    *ft_print_s(var *s)
{
	char	*str;
	int     wdth;
	int     len;
	int     i;
	int     j;

	len  = 0;
	wdth = (s->width) ? s->width : 0;
	len = ft_strlen(s->data);
	wdth = (wdth > len) ? wdth : len;
	if (!(str = ft_strnew(wdth)))
		return (0);
	i = 0;
	//ft_putstr(s->data);
	//ft_putchar(s->flag);
	//s-> = '-';
	if (s->flag != '-')
		ft_fil_whitespaces(&str, wdth, len, &i);
	while (s->data[j])
		str[i++] = s->data[j++];
	if (s->flag == '-')
		ft_fil_whitespaces(&str, wdth, len, &i);
	//ft_putstr(s->data);
	return (str);
}