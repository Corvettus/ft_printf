/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:43:57 by rpoetess          #+#    #+#             */
/*   Updated: 2019/08/31 16:43:58 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_d(var *tmp)
{
	char	*res;

	if ((int)ft_strlen(tmp->data) < tmp->precision)
		while ((int)ft_strlen(tmp->data) < tmp->precision && tmp->precision < tmp->width)
			tmp->data = ft_strjoin("0", tmp->data);
	if ((tmp->flag2 == '+') && (tmp->arg_sign > 0))
		tmp->data = ft_strjoin("+", tmp->data);
	else if ((tmp->flag == '+') && (tmp->arg_sign > 0))
		tmp->data = ft_strjoin("+", tmp->data);
		tmp->precision = 0;
	res = ft_print_s(tmp);
	return (res);
}
