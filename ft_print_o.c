/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:39:28 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/28 19:11:13 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_o(var *tmp)
{
	int flag_zero;

	flag_zero = 0;
	/*
	ft_putchar('|');
	ft_putchar(tmp->flag);
	ft_putchar(tmp->flag_1);
	ft_putchar(tmp->flag2);
	ft_putchar('|');
	*/
/*
	ft_putchar('|');
	ft_putnbr(tmp->width);
	ft_putnbr(tmp->precision);
	ft_putnbr(tmp->precision_flag);
	ft_putnbr((int)ft_strlen(tmp->data));
	ft_putchar('|');
*/
	if ((int)ft_strlen(tmp->data) == 0)
		flag_zero = 1;
	if (flag_zero == 0)
	{
		if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '?')
			tmp->data = ft_strjoin("0", tmp->data);
		if (tmp->flag == '-' && tmp->flag2 == '#' && tmp->flag_1 == '?')
			tmp->data = ft_strjoin("0", tmp->data);
		if (tmp->flag == '-' && tmp->flag2 == '#' && tmp->flag_1 == '0')
			tmp->data = ft_strjoin("0", tmp->data);
		if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '0')
		{
			if (tmp->precision_flag == 0)
			{
				if (tmp->width == (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin("0", tmp->data);
				while (tmp->width > (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin("0", tmp->data);
			/*ft_putchar('|');
			ft_putstr(tmp->data);
			ft_putchar('|');*/

			}
			if (tmp->precision_flag == 1)
			{
				if (tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin("0", tmp->data);
				while (tmp->precision > (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin("0", tmp->data);
			}
		}
		/*if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '0')
		{
			tmp->flag_1 = '?';
			tmp->flag2 = '?';
		}*/
	}
	if (flag_zero == 1)
	{
		if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '?')
			tmp->data = ft_strjoin("0", tmp->data);
		if (tmp->flag == '-' && tmp->flag2 == '#' && tmp->flag_1 == '?')
			tmp->data = ft_strjoin("0", tmp->data);
	}
	/*
	if (flag_zero == 1)
	{
		if (!(tmp->precision == 0 && tmp->precision_flag == 1))
		{
			if (tmp->flag == '?' && tmp->flag2 == '?' && tmp->flag_1 == '?')
				tmp->data = "0";
			if (tmp->flag == '-' && tmp->flag2 == '?' && tmp->flag_1 == '?')
				tmp->data = "0";
		}
		if (tmp->flag2 == '#')
			while (tmp->width > (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin("0", tmp->data);	
	}
	*/
	tmp->data = ft_print_d(tmp);
	return (tmp->data);
}
//if (tmp->precision)
		//tmp->data = ft_crop_str(tmp->data, (int)ft_strlen(tmp->data), tmp->precision);
/*
if (tmp->width && tmp->width > (int)ft_strlen(tmp->data))
	{
		if (tmp->flag != '-')
			tmp->data = ft_fil_whitespaces(tmp, wdth, len);
		else if (tmp->flag == '-')
			tmp->data = ft_end_whitespaces(tmp, wdth, len);
	}
*/