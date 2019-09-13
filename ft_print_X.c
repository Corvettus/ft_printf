/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_X.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:17:29 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/13 19:32:33 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_print_x(var *tmp)
{
	if (tmp->flag == '-')
		while((int)ft_strlen(tmp->data) < tmp->precision)
			tmp->data = ft_strjoin("0", tmp->data);
	if (tmp->flag2 == '#' && tmp->data != 0)
	{
		if (tmp->type == 'x')
			tmp->data = ft_strjoin("0x", tmp->data);
		if (tmp->type == 'X')
			tmp->data = ft_strjoin("0X", tmp->data);
	}
	if (tmp->flag != '-')
		ft_fil_whitespaces(tmp, tmp->width, (int)ft_strlen(tmp->data));
	else
		while((int)ft_strlen(tmp->data) < tmp->width)
			tmp->data = ft_strjoin(tmp->data, " ");
	return (tmp->data);
}
