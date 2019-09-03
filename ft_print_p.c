/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:13:29 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/03 17:13:33 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_p(var *s)
{
	return (0);
}
/*
void	ft_supzerox(t_spec *s, t_ran *ran)
{
	str[i++] = '0';
	str[i++] = 'x';
	if (s->precision > s->width)
		while (s->precision-- > ft_strlen(s))
			str[i++] = '0';
	//??ft_strjcpy??;
}

char    *ft_print_p(var *s)
{
	char*           str;
	unsigned long   p;

	i = 0;
	num = va_arg(*vl, unsigned long);
	if (num == 0)
	{
		if (s->minus == 0 && s->precision == 0)
		{
			while (s->width-- - 3 > 0)
				str[i++] = ' ';
			str[i++] = '0';
			str[i++] = 'x';
			str[i++] = '0';
		}
		else if (s->precision == -1)
		{
			while (s->width-- - 2 > 0)
				str[i++] = ' ';
			str[i++] = '0';
			str[i++] = 'x';
		}
		else
		{
			str[i++] = '0';
			str[i++] = 'x';
			str[i++] = '0';
			while (s->precision-- > 1)
				str[i++] = '0';
			while (s->width-- - 3 > 0)
				str[i++] = ' ';
		}
	}
	else
	{
		s->i = s->j;
		while (num != 0)
		{
			remainder = num % 16;
			if (remainder < 10)
				s[s->j++] = 48 + remainder;
			else
				s[s->j++] = 55 + 32 + remainder;
			num = num / 16;
		}
		s->j--;
		while (s->i < s->j)
		{
			remainder = s[s->i];
			s[s->i++] = s[s->j];
			s[s->j--] = remainder;
		}
		ran->strlen = ft_strlen(s) + 2;
		if (s->minus == 0)
		{
			if (s->width < ran->strlen)
				ft_supzerox(s, ran);
			else
			{
				while (s->width-- > ran->strlen)
					str[i++] = ' ';
				ft_supzerox(s, ran);
			}
		}
		else
		{
			ft_supzerox(s, ran);
			while (s->width-- > ran->strlen)
				str[i++] = ' ';
		}
	}
	return (str);
}


void	ft_supoctalsminus(t_spec *s, t_ran *ran)
{
	if (s->minus == 0 && s->precision == 0)
	{
		while (s->width-- - 3 > 0)
			str[i++] = ' ';
		str[i++] = '0';
		str[i++] = 'x';
		str[i++] = '0';
	}
	else if (s->precision == -1)
	{
		while (s->width-- - 2 > 0)
			str[i++] = ' ';
		str[i++] = '0';
		str[i++] = 'x';
	}
	else
	{
		str[i++] = '0';
		str[i++] = 'x';
		str[i++] = '0';
		while (s->precision-- > 1)
			str[i++] = '0';
		while (s->width-- - 3 > 0)
			str[i++] = ' ';
	}
}

void	ft_supzerox(t_spec *s, t_ran *ran)
{
	str[i++] = '0';
	str[i++] = 'x';
	if (s->precision > s->width)
		while (s->precision-- > ft_strlen(s))
			str[i++] = '0';
	ft_strjcpy(ran->buf, s, &ran->j);
}

void	ft_adrxuli(t_spec *s, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned long remainder;

	s->i = s->j;
	while (num != 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			s[s->j++] = 48 + remainder;
		else
			s[s->j++] = 55 + sm + remainder;
		num = num / 16;
	}
	s->j--;
	while (s->i < s->j)
	{
		remainder = s[s->i];
		s[s->i++] = s[s->j];
		s[s->j--] = remainder;
	}
	ran->strlen = ft_strlen(s) + 2;
}

void	ft_supadr1(t_spec *s, t_ran *ran, unsigned long long int num)
{
	ft_adrxuli(s, ran, num, 32);
	if (s->minus == 0)
	{
		if (s->width < ran->strlen)
			ft_supzerox(s, ran);
		else
		{
			while (s->width-- > ran->strlen)
				str[i++] = ' ';
			ft_supzerox(s, ran);
		}
	}
	else
	{
		ft_supzerox(s, ran);
		while (s->width-- > ran->strlen)
			str[i++] = ' ';
	}
}

void	ft_adr_record(t_ran *ran, va_list *vl, t_spec *s)
{
	unsigned long num;

	num = va_arg(*vl, unsigned long);
	if (num == 0)
		ft_supoctalsminus(s, ran);
	else
		ft_supadr1(s, ran, num);
}
*/
