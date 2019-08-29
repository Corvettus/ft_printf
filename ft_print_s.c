#include "ft_printf.h"
#include <stdio.h>

char    *ft_fil_whitespaces(char *str, int wdth, int len, int crop)
{
	int		i;

	i = 0;
	while (wdth - len > i++ + crop)
		str = ft_strjoin_char(str, ' ');
	return (str);
}

char    *ft_crop_str(char *str, int len, int crop)
{
	char	*tmp;

	if (len > crop)
	{
		tmp = ft_strnew(crop);
		tmp = ft_strncpy(tmp, str, crop);
	}
	//free(str);
	str = tmp;
	return (str);
}

char    *ft_print_s(var *s)
{
	char    *str;
	int     wdth;
	int     len;
	int     i;
	int     j;

	len  = 0;
	i = 0;
	wdth = (s->width) ? s->width : 0;
	len = ft_strlen(s->data);
	if (!(str = ft_strnew(wdth)))
		return (0);
	if  (s->precision >= len)
		s->precision = 0;
	if (s->precision > 0)
	{
		s->data = ft_crop_str(s->data, len, s->precision);
		len = (len > s->precision) ? s->precision : len;
	}
	if (s->flag == '-')
		wdth = 0;
	if (s->width)
		str = ft_fil_whitespaces(str, wdth + s->precision, len, s->precision);
	str = ft_strjoin(str, s->data);
	return (str);
}