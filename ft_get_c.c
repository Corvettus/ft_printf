/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:27:04 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/09 20:27:06 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_c(char *str1, var *tmp, va_list str)
{
	if (tmp->width == '0')
		tmp->precision = 0;
	str1 = ft_strnew(1);
	str1[0] = (char)va_arg(str, int);
	str1[1] = '\0';
	return (str1);
}