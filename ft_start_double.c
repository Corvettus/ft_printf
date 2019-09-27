/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:17:18 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/03 17:17:20 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

float			ft_power(float nb, int power)
{
	float	s;

	s = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power-- > 1)
		nb = s * nb;
	return (nb);
}

float_struct	ft_create_double_list(float_struct tmp, long double n, int precision)
{
	long double		num;

	num = n;
	tmp.power = 1;
	tmp.mantisa_len = 0;
	tmp.res = ft_strnew(0);
	while (num > 10)
	{
		num = num / 10;
		tmp.power++;
	}
	tmp.base = num;
	tmp.mantisa = (n - (uintmax_t)n);
/*	ft_putchar('|');
	ft_putnbr(n * 1000000);
	ft_putchar('|');*/
	return (tmp);
}

float_struct	ft_create_double(long double n, int precision)
{
	float_struct	tmp;

	tmp.mantisa_len = 0;
	tmp = ft_create_double_list(tmp, n, precision);
	while (tmp.mantisa_len < precision)
	{
		tmp.mantisa_len++;
		tmp.mantisa *= 10;
	}
	tmp.num = n;
	if (n < 0)
	{
		tmp.base *= -1;
		tmp.mantisa *= -1;
	}
	return (tmp);
}

char			*ft_start_double(long double n, var *var_struct)
{
	float_struct	tmp;
	int				precision;

	var_struct->arg_sign = (n < 0) ? -1 : 1;
	n = (n < 0) ? -n : n;
//	n += 0.0000005;
	precision = 0;
	if (!(var_struct->precision == 0 && var_struct->precision_flag == 1))
		precision = (var_struct->precision == 0) ? 6 : var_struct->precision;
	/*
	ft_putchar('|');
	ft_putnbr(var_struct->precision);
	ft_putchar('|');
	*/
	n += 0.5 * ft_power(0.1, precision);
	tmp = ft_create_double(n, precision);
	//tmp.res = ft_strjoin(tmp.res, ft_itoa((int)tmp.num));
	tmp.res = ft_itoa((int)tmp.num);
	/*ft_putchar('|');
	ft_putstr(tmp.res);
	ft_putchar('|');*/
	if (!(var_struct->precision == 0 && var_struct->precision_flag == 1))
	{
		tmp.res = ft_strjoin(tmp.res, ".");
		if ((int)ft_strlen(ft_itoa((int)tmp.mantisa)) < tmp.mantisa_len)
			while ((int)ft_strlen(ft_itoa((int)tmp.mantisa)) < tmp.mantisa_len--)
				tmp.res = ft_strjoin(tmp.res, "0");
		tmp.res = ft_strjoin(tmp.res, ft_ullitoa((long long int)tmp.mantisa, var_struct));
	}
	return (tmp.res);
}
