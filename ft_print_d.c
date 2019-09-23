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

void	ft_if_ngtv_rgsgn(var *tmp)
{
/*
	ft_putchar('|');
	ft_putchar(tmp->flag);
	ft_putchar(tmp->flag_1);
	ft_putchar(tmp->flag2);
	ft_putchar('|');
*/
	if (tmp->precision_flag == 0)
	{
		if (tmp->flag == '?')
		{
			tmp->data = ft_strjoin("-", tmp->data);
		}
		if (tmp->flag == '+')
		{
			if (tmp->width == 0)
			{
				tmp->data = ft_strjoin("-", tmp->data);
			}
		}
		if (tmp->flag == '-')
			tmp->data = ft_strjoin("-", tmp->data);
		if (tmp->flag == '0')
		{
			if (tmp->flag2 == '?')
			{
				if (tmp->width <= (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin("-", tmp->data);
				tmp->width--;
			}
			if (tmp->flag2 == '+')
			{
				if (tmp->width > (int)ft_strlen(tmp->data))
					tmp->width--;
			}
		}
		if (tmp->flag == ' ')
		{
			if (tmp->width == 0)
				tmp->data = ft_strjoin("-", tmp->data);
		}
	}
	if (tmp->precision_flag == 1)
	{
		if (tmp->flag == '?')
		{	
			if (tmp->precision < (int)ft_strlen(tmp->data))
			{
				//if (tmp->width <= (int)ft_strlen(tmp->data) )
				//	tmp->data = ft_strjoin("-", tmp->data);
				if (tmp->width == 0)
				{
					if (tmp->precision <= (int)ft_strlen(tmp->data))
						tmp->data = ft_strjoin("-", tmp->data);
				}
			}
			if (tmp->precision >= (int)ft_strlen(tmp->data))
			{
				if (tmp->width)
				{
					if (tmp->width <= (int)ft_strlen(tmp->data) && tmp->precision < tmp->width)
						tmp->data = ft_strjoin("-", tmp->data);
				}
				else if (tmp->width == 0)
				{
					if (tmp->precision <= (int)ft_strlen(tmp->data))
						tmp->data = ft_strjoin("-", tmp->data);
				}
			}
		}
		if (tmp->flag == '-')
		{
			if (tmp->flag2 == '?')
			{
				if (tmp->precision >= (int)ft_strlen(tmp->data))
				{
					if (tmp->precision <= tmp->width)
						tmp->data = ft_strjoin("-", tmp->data);
				}
				if (tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin("-", tmp->data);
			}
			if (tmp->flag2 == '+')
			{
				if (tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin("-", tmp->data);
			}
		}
		if (tmp->flag == '0')
		{
			if (tmp->flag2 == '?')
				tmp->width--;
		}
	}
}

void	ft_if_pstv_rgsgn(var *tmp)
{
/*
	ft_putchar('|');
	ft_putchar(tmp->flag);
	ft_putchar(tmp->flag_1);
	ft_putchar(tmp->flag2);
	ft_putchar('|');
*/

	if (tmp->precision_flag == 0)
	{
		if (tmp->flag == ' ')
		{
			if (tmp->flag2 == '?')
			{
				if (tmp->width == 0)
					tmp->data = ft_strjoin(" ", tmp->data);
			}
		}
		if (tmp->flag == '+')
		{
			if (tmp->flag2 == ' ')
			{
				if (tmp->width == 0)
					tmp->data = ft_strjoin("+", tmp->data);
			}
			if (tmp->flag2 == '?' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin("+", tmp->data);
			if (tmp->flag2 == '+')
				tmp->data = ft_strjoin("+", tmp->data);
		}
		if (tmp->flag == '0')
		{
			if (tmp->flag2 == '+' && tmp->width > (int)ft_strlen(tmp->data))
				tmp->width--;
			if (tmp->flag2 == '?')
			{
				//tmp->width = 0;
				//if (tmp->width >= (int)ft_strlen(tmp->data))
				//tmp->flag = ' ';
			}
		}
	}
	if (tmp->precision_flag == 1)
	{
		if (tmp->flag == '+')
		{
			if (tmp->flag2 == '?' && tmp->flag_1 == '?')
			{
				if (tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin("+", tmp->data);
			}
		}
		if (tmp->flag == '0')
		{
			if (tmp->flag2 == '?')
				tmp->flag = ' ';
		}
	}
}

char	*ft_print_d(var *tmp)
{
	if (tmp->arg_sign == -1)
		ft_if_ngtv_rgsgn(tmp);
	if (tmp->arg_sign == 1)
		ft_if_pstv_rgsgn(tmp);
	if ((int)ft_strlen(tmp->data) < tmp->precision && tmp->precision_flag == 1)
		while (((int)ft_strlen(tmp->data) < tmp->precision && tmp->precision <= tmp->width))
			tmp->data = ft_strjoin("0", tmp->data);
	if (tmp->arg_sign == 1 && tmp->precision == (int)ft_strlen(tmp->data))
	{
		if (tmp->flag == '+')
		{
			if (tmp->flag2 == '?')
				tmp->data = ft_strjoin("+", tmp->data);
		}
		if (tmp->flag == '-')
		{
			if (tmp->flag2 == '+')
				tmp->data = ft_strjoin("+", tmp->data);
		}
	}
	if (tmp->arg_sign == -1 && tmp->precision_flag == 1)
	{
		if (tmp->flag == '?')
		{
			if (tmp->width > 0 && tmp->precision <= (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin("-", tmp->data);
		}
	}
	if (tmp->width == 0)
		tmp->width = tmp->precision;
	if (tmp->width && tmp->width > (int)ft_strlen(tmp->data))
	{
		if (tmp->precision > (int)ft_strlen(tmp->data))
		{
			if (tmp->flag == '+')
				tmp->flag_1 = '+';
			tmp->flag = '0';
		}
		if (tmp->precision > tmp->width)
			tmp->width = tmp->precision;
		if (tmp->width && tmp->width > (int)ft_strlen(tmp->data))
		{
			if (tmp->flag != '-')
				tmp->data = ft_fil_whitespaces(tmp, tmp->width, (int)ft_strlen(tmp->data));
			else if (tmp->flag == '-')
				tmp->data = ft_end_whitespaces(tmp, tmp->width, (int)ft_strlen(tmp->data));
		}
	}
	else if (tmp->width < (int)ft_strlen(tmp->data))
	{
		if (tmp->precision && tmp->precision > (int)ft_strlen(tmp->data))
		{
			if (tmp->flag != '-')
				tmp->data = ft_fil_whitespaces(tmp, tmp->precision, (int)ft_strlen(tmp->data));
			else if (tmp->flag == '-')
				tmp->data = ft_end_whitespaces(tmp, tmp->precision, (int)ft_strlen(tmp->data));
		}
	}
	if (tmp->arg_sign == 1)
	{
		if (tmp->flag == '0')
		{
			if (tmp->flag2 == '+' && tmp->width == (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin("+", tmp->data);
			if (tmp->flag2 == '?' && tmp->flag_1 == '+' && tmp->precision == (int)ft_strlen(tmp->data) && tmp->precision_flag == 1)
				tmp->data = ft_strjoin("+", tmp->data);
			//if (tmp->flag2 == '?' && tmp->width == (int)ft_strlen(tmp->data))
			//	tmp->data = ft_strjoin("+", tmp->data);
		}
		if (tmp->flag == '+')
		{
			if (tmp->flag2 == '?' && tmp->precision == (int)ft_strlen(tmp->data) && tmp->precision_flag == 1)
				tmp->data = ft_strjoin("+", tmp->data);
		}
	}

	if (tmp->arg_sign == -1)
	{
		if (tmp->flag == '0')
		{
		//	if (tmp->flag2 == '?' && tmp->width == (int)ft_strlen(tmp->data))
		//		tmp->data = ft_strjoin("-", tmp->data);
			if (tmp->flag2 == '+' && tmp->width == (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin("-", tmp->data);
			if (tmp->flag2 == '?' && tmp->precision >= (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin("-", tmp->data);
		}
	}
	return (tmp->data);
}
