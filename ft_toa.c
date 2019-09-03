/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:23:56 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/03 17:23:58 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puting_ulli_to_a(unsigned long long int n, char **res, size_t buf)
{
	while (n)
	{
		(*res)[--buf] = (char)(n % 10 + '0');
		n /= 10;
	}
}

char		*ft_ullitoa(unsigned long long int n, int arg_sign)
{
	char					*res;
	unsigned long long int	k;
	size_t					buf;

	buf = 1;
	k = n;
	while (k)
	{
		buf++;
		k /= 10;
	}
	if (!(res = (char*)malloc(buf * sizeof(char))))
		return (0);
	res[--buf] = 0;
	puting_ulli_to_a(n, &res, buf);
	if (arg_sign == -1)
		res = ft_strjoin("-", res);
	return (res);
}
