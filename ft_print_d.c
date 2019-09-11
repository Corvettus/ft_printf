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
#include <stdio.h>

char	*ft_print_d(var *tmp)
{
	char	*res;

	if (tmp->arg_sign == -1 && (tmp->width < 0 || tmp->flag == '-' ))
	{
		tmp->data = ft_strjoin("-", tmp->data);
		tmp->width--;
	}
	if (tmp->arg_sign == -1 && tmp->width > (int)ft_strlen(tmp->data)
			&& tmp->flag != '-' && tmp->flag2 != '+' && tmp->flag != '0')
	{
		tmp->data = ft_strjoin("-", tmp->data);
		tmp->width--;
	}
	if ((int)ft_strlen(tmp->data) < tmp->precision && tmp->flag != '0')
		while (((int)ft_strlen(tmp->data) < tmp->precision &&
				tmp->precision < tmp->width))
			tmp->data = ft_strjoin("0", tmp->data);
	if (((tmp->flag2 == '+') && (tmp->arg_sign > 0)) || (tmp->flag == '0'
			&& (tmp->arg_sign < 0)))
		tmp->width -= 2;
	else if ((tmp->flag2 == ' ') && (tmp->arg_sign > 0) && tmp->flag != '+')
		tmp->data = ft_strjoin(" ", tmp->data);
	else if ((tmp->flag == '+') && (tmp->arg_sign > 0) && tmp->flag2 != '+')
		tmp->data = ft_strjoin("+", tmp->data);
	
	if (tmp->flag == '0' && tmp->precision > 0)
	{
		while ((int)ft_strlen(tmp->data) < tmp->precision)
				tmp->data = ft_strjoin("0", tmp->data);
		while (tmp->width > (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin(" ", tmp->data);
	}
	if (tmp->precision > 0 && tmp->precision > (int)ft_strlen(tmp->data))
	{
		tmp->flag = '0';
		tmp->width = (tmp->arg_sign == -1) ? tmp->precision - 1 : tmp->precision;
	}
	tmp->precision = 0;
	if (tmp->flag == ' ' && tmp->arg_sign > 0)
		tmp->data = ft_strjoin(" ", tmp->data);
	res = ft_print_s(tmp);
	if ((tmp->flag2 == '+') && (tmp->arg_sign > 0))
		res = ft_strjoin("+", res);
	if (tmp->arg_sign == -1 && (tmp->flag == '0' || tmp->width == 0))
		res = ft_strjoin("-", res);
	return (res);
}
