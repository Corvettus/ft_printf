#include "ft_printf.h"
#include <stdio.h>

char 	*ft_fil_whitespaces(char *str, int wdth, int len)
{
	int		i;

	i = 0;
	while (wdth - len >= i++ + 1)
			str = ft_strjoin_char(str, ' ');
	return (str);
}

/*char_crop_str(str, char *crop)
{

}*/

char    *ft_print_s(var *s)
{
	char	*str;
	int     wdth;
	int     len;
	int     i;
	int     j;

	len  = 0;
	i = 0;
	wdth = (s->width) ? s->width : 0;
	len = ft_strlen(s->data);
	//wdth = (wdth > len) ? wdth : len;
	if (!(str = ft_strnew(wdth)))
		return (0);
	if (s->flag == '-')
		wdth = 0;
	if (s->width)
		str = ft_fil_whitespaces(str, wdth, len);
	/*if (s->precision)
		ft_crop_str(str, s->precision);*/
	str = ft_strjoin(str, s->data);
	return (str);
}