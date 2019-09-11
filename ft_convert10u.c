/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert10u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 02:42:00 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/11 02:42:02 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ui(var *s, unsigned int num)
{
	unsigned int			remainder;
	size_t					i;

	i = 0;
	while (num != 0)
	{
		remainder = num % 10;
		s->data[i++] = '0' + remainder;
		num = num / 10;
	}
}

void	ft_usi(var *s, unsigned short int num)
{
	unsigned short int		remainder;
	size_t					i;

	i = 0;
	while (num != 0)
	{
		remainder = num % 10;
		s->data[i++] = '0' + remainder;
		num = num / 10;
	}
}

void	ft_uc(var *s, unsigned char num)
{
	unsigned char			remainder;
	size_t					i;

	i = 0;
	while (num != 0)
	{
		remainder = num % 10;
		s->data[i++] = '0' + remainder;
		num = num / 10;
	}
}

void	ft_uli(var *s, unsigned long int num)
{
	unsigned long int		remainder;
	size_t					i;

	i = 0;
	while (num != 0)
	{
		remainder = num % 10;
		s->data[i++] = '0' + remainder;
		num = num / 10;
	}
}

void	ft_ulli(var *s, unsigned long long int num)
{
	unsigned long long int	remainder;
	size_t					i;

	i = 0;
	while (num != 0)
	{
		remainder = num % 10;
		s->data[i++] = '0' + remainder;
		num = num / 10;
	}
}
