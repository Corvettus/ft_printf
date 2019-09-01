/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:10:55 by rpoetess          #+#    #+#             */
/*   Updated: 2019/08/31 16:10:57 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char			*ft_controller(var *tmp)
{
	char *res;

	//res = ft_strnew(0);
	if (tmp->type == '%')
		res = ft_print_pc(tmp);
	else if (tmp->type == 'c')
		res = ft_print_c(tmp);
	else if (tmp->type == 's')
		res = ft_print_s(tmp);
	else if (tmp->type == 'p')
		res = ft_print_p(tmp);
	else if (tmp->type == 'd' || tmp->type == 'i')
		res = ft_print_d(tmp);
	else if (tmp->type == 'o')
	{
		//if (tmp->flag == '+' || tmp->flag == '-' || tmp->flag == ' ')
		if (tmp->flag != '0' || (tmp->flag == '0' && ft_strlen(tmp->data) > tmp->precision) ||
			((tmp->flag == '?') && ft_strlen(tmp->data) > tmp->precision))
			tmp->precision = 0;
		if ((tmp->flag == '0' || tmp->flag == '?') && ft_strlen(tmp->data) < tmp->precision)
			tmp->width = tmp->precision;
		
		//printf("width  :%d\n", tmp->width);
		//printf("precision  :%d\n", tmp->precision);
		res = ft_print_s(tmp);
	}
	else if (tmp->type == 'u' || tmp->type == 'U')
		res = ft_print_u(tmp);
	else if (tmp->type == 'x' || tmp->type == 'X')
		res = ft_print_X(tmp);
	if (tmp->type == 'f')
		res = ft_print_f(tmp);
	return (res);
}
