/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:39:28 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/21 05:55:25 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_o(var *tmp)
{
	char	*res;

	if (tmp->width < tmp->precision)
		tmp->width = tmp->precision;
	if (tmp->flag == '?' && (int)ft_strlen(tmp->data) < tmp->precision)
		tmp->flag = '0';
	while (tmp->flag == '0' && (int)ft_strlen(tmp->data) < tmp->width)
		tmp->data = ft_strjoin_left("0", tmp->data);
	if (tmp->flag2 == '#' && tmp->flag != '0')
		tmp->data = ft_strjoin_left("0", tmp->data);
	if (tmp->flag == '-')
		while ((int)ft_strlen(tmp->data) < tmp->precision)
			tmp->data = ft_strjoin_left("0", tmp->data);
	tmp->precision = 0;
	res = ft_print_s(tmp);
	return (res);
}
