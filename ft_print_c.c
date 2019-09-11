/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:27:43 by rpoetess          #+#    #+#             */
/*   Updated: 2019/08/31 16:29:13 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static void	ft_fil_whitespaces1(char **str, int wdth, int *i)
{
	while (wdth > 1)
	{
		*str[*i++] = ' ';
		--wdth;
	}
}*/

char		*ft_print_c(var *s)
{
	char	*str;
//	int		wdth;
//	int		i;

/*	if (s->data == 0)
		return ("0");
	wdth = s->width;
	if (!wdth)
		++wdth;
	if (!(str = ft_strnew(wdth)))
		return (0);
	i = 0;
	if (s->flag != '-')
		ft_fil_whitespaces1(&str, wdth, &i);
	str[i++] = (char)*s->data;
	if (s->flag == '-')
		ft_fil_whitespaces1(&str, wdth, &i);*/
	s->width = (s->data > 0) ? s->width : 0;
	str = ft_print_s(s);
	return (str);
}
