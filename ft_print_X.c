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

void	ft_ox(var *tmp)
{
	if (tmp->type == 'x')
		tmp->data = ft_strjoin("0x", tmp->data);
	if (tmp->type == 'X')
		tmp->data = ft_strjoin("0X", tmp->data);
}

char	*ft_print_x(var *tmp)
{
	/*
	ft_putchar('|');
	ft_putchar(tmp->flag);
	ft_putchar(tmp->flag_1);
	ft_putchar(tmp->flag2);
	ft_putchar('|');
	*/
	int	flag_zero;

	flag_zero = 0;
	if ((int)ft_strlen(tmp->data) == 0)
		flag_zero = 1;
	if (flag_zero == 0)
	{
		if (tmp->precision_flag == 0)
		{
			if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '0')
			{
				tmp->width -= 2;
				while (tmp->width > (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin("0", tmp->data);
			}
		}
		if (tmp->precision_flag == 1)
		{
			if (tmp->flag == '?' && tmp->flag2 == '#')
			{
				if (tmp->flag_1 == '-' || tmp->flag_1 == '?' || tmp->flag_1 == '0')
				{
					//if (tmp->precision > tmp->width)
						while ((int)ft_strlen(tmp->data) < tmp->precision)
							tmp->data = ft_strjoin("0", tmp->data);		
				}
			}
			if (tmp->flag == '-' && tmp->flag2 == '#')
			{
				if (tmp->flag_1 == '0')
				{
					while (tmp->precision > (int)ft_strlen(tmp->data))
						tmp->data = ft_strjoin("0", tmp->data);
				}
				if (tmp->flag_1 == '?')
				{
					while (tmp->precision > (int)ft_strlen(tmp->data))
						tmp->data = ft_strjoin("0", tmp->data);
				}
			}
			/*if (tmp->flag == 0 && tmp->flag2 == '#' && tmp->flag_1 == '?')
				if (tmp->precision < tmp->width)
					tmp->flag = '?';*/
		}
		if (tmp->flag == '?')
		{
			if (tmp->flag2 == '#')
				ft_ox(tmp);
		}
		if (tmp->flag == '-')
		{
			if (tmp->flag2 == '#' && tmp->flag_1 == '?')
				ft_ox(tmp);
			if (tmp->flag2 == '#' && tmp->flag_1 == '0')
				ft_ox(tmp);
		}
	}
	if (tmp->precision_flag == 0 && (int)ft_strlen(tmp->data) == 0)
	{
		tmp->data = "0";
		if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '0')
			while (tmp->width > (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin("0", tmp->data);
	}
	if (tmp->precision_flag == 1 && (int)ft_strlen(tmp->data) == 0)
	{
		if (tmp->flag == '0' && tmp->flag2 == '#' && tmp->flag_1 == '?')
		{
			tmp->data = "0";
			tmp->flag = '?';
			tmp->flag2 = '?'; 
		}
	}
	
	tmp->data = ft_print_d(tmp);

	if (flag_zero == 0)
	{
		if (tmp->flag == '0')
		{
			if (tmp->precision >= (int)ft_strlen(tmp->data))
				if (tmp->flag2 == '#' && tmp->flag_1 == '?')
					ft_ox(tmp);
		}
	}
	return (tmp->data);
}
