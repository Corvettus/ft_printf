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

char	*ft_print_d(var *s)
{
	char	*str;

	//str = ft_strnew(0);
	str = s->data;
	if (s->arg_sign == -1)
		str = ft_strjoin("-", str);
	//ft_putstr(str);
	return (str);
}
