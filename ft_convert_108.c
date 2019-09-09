/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_108.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:12:51 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/04 18:12:53 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_convert108(intmax_t nmb)
{
	intmax_t	tmp;
	intmax_t	a;
	int				sign;

	a = 0;
	tmp = 0;
	sign = 1;
	if (nmb < 0)
	{
		nmb = UINT_MAX + nmb;
	}
	while ((uintmax_t)nmb > 7)
	{
		a = nmb % 8;
		nmb = nmb / 8;
		tmp = tmp * 10 + a;
	}
	tmp = tmp * 10 + nmb;
	nmb = 0;
	while (tmp > 9)
	{
		a = tmp % 10;
		tmp = tmp / 10;
		nmb = nmb * 10 + a;
	}
	nmb = nmb * 10 + tmp;
	return (nmb);
}
