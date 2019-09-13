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

void			ft_putstr_len(char *str, int n)
{
	int		i;
	char	c;

	c = 0;
	i = 0;
/*	while (i < n)
	{
		if (str[i] == 0)
		{
			write(1, &c, 1);
			i++;
		}
		else
			ft_putchar(str[i++]);
	}
*/
	write(1, str, n);
}

char			*ft_create_arg_string(char *str1, var *tmp,
								va_list str)
{
	if (tmp->type == 'c' || tmp->type == '%')
		str1 = ft_get_c(str1, tmp, str);
	else if (tmp->type == 's' || tmp->type == 'p')
		str1 = va_arg(str, char*);
	else if (tmp->type == 'd' || tmp->type == 'i')
		str1 = ft_get_d(str1, tmp, str);
	else if (tmp->type == 'u')
		str1 = ft_get_u(str1, tmp, str);
	else if (tmp->type == 'o')
		str1 = ft_get_o(str1, tmp, str);
	else if (tmp->type == 'f')
		str1 = ft_get_f(str1, tmp, str);
	else if (tmp->type == 'x' || tmp->type == 'X')
		str1 = ft_get_x(str1, tmp, str);
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
	//write(1, &res_str, 1);
	res_str = ft_strjoin(res_str, ft_create_list_var(format, ++(*i), str));
	while (!ft_check_type(format[*i]) && format[*i] != '\0' && res_str > 0)
		(*i)++;
	(*i)++;
	//write(1, &res_str, 1);
	return (res_str);
}

int				ft_printf(const char *format, ...)
{
	va_list		str;
	int			i;
	char		*res;
	int			len;
	char		*tmp;

	i = 0;
	len = 0;
	res = ft_strnew(0);
	va_start(str, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%' && format[i] != '\0')
		{
			tmp = ft_strnew(0);
			tmp = ft_ifnopercent(tmp, format, &i);
			len += (tmp) ? ft_strlen(tmp) : 0;
			res = ft_strjoin(res, tmp);
			free(tmp);
		}
		if (format[i] == '%')
		{
			tmp = ft_strnew(0);
			tmp = ft_strjoin(tmp, ft_ifprecent(tmp, format, str, &i));
			len += (tmp > 0) ? ft_strlen(tmp) : 1;
			res = ft_strjoin(res, tmp);
			free(tmp);
		}
	}
	ft_putstr_len(res, len);
	//i = ft_strlen(res); //- ft_strsrch_null(res);
	free(res);
	va_end(str);
	return (len);
}
