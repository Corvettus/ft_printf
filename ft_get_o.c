/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:52:11 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/18 20:38:30 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_o(char *str1, var *tmp, va_list str)
{
	intmax_t	nb;

	nb = 0;
	if (tmp->size1 == 'l')
		nb = va_arg(str, unsigned long long int);
	else if (tmp->size1 == 'h')
	{
		if (tmp->size2 == 'h')
			nb = va_arg(str, unsigned char);
		else
			nb = va_arg(str, unsigned short int);
	}
	else
	{
		nb = va_arg(str, unsigned int);
		if (nb == 0 && tmp->precision == 0 && tmp->precision_flag == 1)
			return ("");
	}
	str1 = ft_itoa_base(nb, 8, tmp->type);
	return (str1);
}
