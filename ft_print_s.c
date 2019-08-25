#include "ft_printf.h"

ft_fil_whitespaces(char** str, int wdth, int len, int* i)
{
	while (wdth > len)
		{
			*str[*i++] = ' ';
			--wdth;
		}
}

char    *ft_print_s(var *s)
{
	char*   str;
	int     wdth;
	int     len;
	int     i;
	int     j;

	wdth = s->width;
	len = ft_strlen(s->data);
	wdth = (wdth > len) ? wdth : len;
	if (!ft_strnew(wdth))
		return (0);
	i = 0;
	if (s->sign != '-')
		ft_fil_whitespaces(&str, wdth, len, &i);
	while (s->data[j])
		str[i++] = s->data[j++];
	if (s->sign == '-')
		ft_fil_whitespaces(&str, wdth, len, &i);
	return (str);
}