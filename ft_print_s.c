/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:30:58 by rpoetess          #+#    #+#             */
/*   Updated: 2019/08/31 16:31:00 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_fil_whitespaces(char *str, int wdth, int len, char space)
{
	int		i;

	i = 0;
	if (space != '0')
	{
		while (wdth - len > i++)
			str = ft_strjoin(" ", str);
	}
	else 
	{	while (wdth - len > i++)
			str = ft_strjoin("0", str);
	}
	return (str);
}

char	*ft_end_whitespaces(char *str, int wdth, int len)
{
	int		i;

	i = 0;
	while (wdth - len > i++)
		str = ft_strjoin_char(str,033);
	return (str);
}

char	*ft_crop_str(char *str, int len, int crop)
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
//нужно сделать поддержку "*" , "-" и фришки.
char	*ft_print_s(var *s)
{
	char	*str;
	int		wdth;
	int		len;

	len = 0;
	wdth = (s->width) ? s->width : 0;
	if (!(s->data))
		s->data = "(null)";
	len = ft_strlen(s->data);
	/*printf("Wdth  :%d\n", wdth);
	printf("width  :%d\n", s->width);
	printf("precision  :%d\n", s->precision);
	printf("len  :%d\n", len);*/


	if (s->precision >= len && s->flag != '0')
		s->precision = 0;
	if (s->flag == '0')
		wdth = s->precision;
	if (!(str = ft_strnew(wdth)))
		return (0);
	if (s->precision > 0)
	{
		s->data = ft_crop_str(s->data, len, s->precision);
		len = (len > s->precision) ? s->precision : len;
	}

	if (s->width)
	{
		if (s->flag != '-')
			str = ft_fil_whitespaces(str, wdth, len, s->flag);
		else if (s->flag == '-')
		{
			str = ft_end_whitespaces(str, wdth, len);
			//str = ft_rev_str(str);
		}
	}
	str = ft_strjoin(str, s->data);
	return (str);
}
