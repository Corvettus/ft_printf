/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:37:01 by rpoetess          #+#    #+#             */
/*   Updated: 2019/08/31 16:37:03 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_print_f(var *s)
{
	char	*str;
	int		wdth;
	int		len;
	int		i;

	i = 0;
	len = 0;
	wdth = (s->width) ? s->width : 0;
	len = ft_strlen(s->data);
	while (s->data[i] != '.')
		i++;
	if (!(str = ft_strnew(wdth)))
		return (0);
	if (s->precision >= len)
		s->precision = 0;
	if (s->precision > 0)
	{
		s->data = ft_crop_str(s->data, len , s->precision + i + 1);
		len = (len > s->precision) ? s->precision + i : len;
	}
	if (s->precision)
		len++;
	if (s->width)
		str = ft_fil_whitespaces(str, wdth , len);
	str = ft_strjoin(str, s->data);
	//printf("Len :%d\n", len);
	//printf("Precicion :%d\n", s->precision);
	//printf("Precicion :%d\n");
	return (str);
}
