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

char	*ft_fil_whitespaces(var *s, int wdth, int len)
{
	int		i;

	i = 0;
	if (s->flag != '0')
		while (wdth - len > i++)
			s->data = ft_strjoin(" ", s->data);
	else
		while (wdth - len > i++)
			s->data = ft_strjoin("0", s->data);
	return (s->data);
}
char	*ft_end_whitespaces(char *str, int wdth, int len)
{
	int		i;
	char	*new;

	new = ft_strnew(0);
	i = 0;
	while (wdth - len > i++)
		str = ft_strjoin(str, " ");
	return (str);
}

char	*ft_crop_str(char *str, int len, int crop)
{
	char	*tmp;

	tmp = 0;
	if (len > crop)
	{
		tmp = ft_strnew(crop);
		tmp = ft_strncpy(tmp, str, crop);
	}
	str = tmp;
	return (str);
}

char	*ft_print_s(var *s)
{
	char	*str;
	int		wdth;
	int		len;

	wdth = (s->width > 0) ? s->width : 0;
	s->data = (!(s->data)) ? "(null)" : s->data;
	len = ft_strlen(s->data);
	if (s->arg_sign == -1 || s->flag2 == '+')
		len--;
	s->precision = (s->precision >= len) ? 0 : s->precision;
	if (!(str = ft_strnew(wdth)))
		return (0);
	if (s->precision)
	{
		s->data = ft_crop_str(s->data, len, s->precision);
		len = (len > s->precision) ? s->precision : len;
	}
	if (s->width)
	{
		if (s->flag != '-')
			s->data = ft_fil_whitespaces(s, wdth, len);
		else if (s->flag == '-')
			s->data = ft_end_whitespaces(s->data, wdth, len);
	}
	if (s->arg_sign == -1)
		s->data = ft_strjoin("-", s->data);
	str = ft_strjoin(str, s->data);
	return (str);
}
