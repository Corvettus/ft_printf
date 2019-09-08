/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:35:51 by rpoetess          #+#    #+#             */
/*   Updated: 2019/08/31 16:35:53 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_create_arg_string(char *str1, var *tmp,
								va_list str)
{
	long long int	nb;

	if (tmp->type == 'c' || tmp->type == '%')
	{
		str1 = ft_strnew(1);
		str1[0] = (char)va_arg(str, int);
		str1[1] = '\0';
	}
	else if (tmp->type == 's' || tmp->type == 'p')
		str1 = va_arg(str, char*);
	else if (tmp->type == 'd' || tmp->type == 'i')
	{
		nb = (va_arg(str, unsigned long long int));
		tmp->arg_sign = (nb < 0 && tmp->arg_sign != 0) ? -1 : tmp->arg_sign;
		nb = (nb > 0) ? nb : nb * (-1);
		str1 = ft_llitoa(nb, tmp->arg_sign);
	}
	else if (tmp->type == 'u')
		str1 = ft_itoa(va_arg(str, unsigned int));
	else if (tmp->type == 'o')
		str1 = ft_itoa(ft_convert108(va_arg(str, int)));
	else if (tmp->type == 'f')
		str1 = ft_start_double(va_arg(str, double), tmp->precision);
	return (str1);
}

char			*ft_ifnopercent(char *res_str, const char *format, int *i)
{
	while (format[*i] != '%' && format[*i] != '\0')
		res_str = ft_strjoin_char(res_str, format[(*i)++]);
	return (res_str);
}

char			*ft_ifprecent(char *res_str,
					const char *format, va_list str, int *i)
{
	res_str = ft_strjoin(res_str, ft_create_list_var(format, ++(*i), str));
	while (!ft_check_type(format[*i]) && format[*i] != '\0')
		(*i)++;
	(*i)++;
	return (res_str);
}

int				ft_printf(const char *format, ...)
{
	va_list		str;
	int			i;
	char		*res;

	i = 0;
	res = ft_strnew(0);
	va_start(str, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%' && format[i] != '\0')
			res = ft_ifnopercent(res, format, &i);
		if (format[i] == '%')
			res = ft_ifprecent(res, format, str, &i);
	}
	ft_putstr(res);
	i = ft_strlen(res);
	free(res);
	va_end(str);
	return (i);
}
