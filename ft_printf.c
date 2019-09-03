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

/*
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>  //del
#include <string.h> //del
*/
#include "ft_printf.h"

char			*ft_strjoin_char(char *str, char end)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
		i++;
	tmp = (char*)malloc(sizeof(char) * i + 2);
	tmp = ft_strcpy(tmp, str);
	tmp[i] = end;
	tmp[i + 1] = '\0';
	free(str);
	str = tmp;
	return (str);
}

void			ft_print_result_list(result_list *res)
{
	while (res)
	{
		ft_putstr(res->data);
		res = res->next;
	}
}

char			*ft_create_arg_string(char *str1, char type, va_list str, var *list)
{
	long long int	nb;

	if (type == 'c' || type == '%')
	{
		str1 = ft_strnew(1);
		str1[0] = (char)va_arg(str, int);
		str1[1] = '\0';
	}
	else if (type == 's' || type == 'p')
		str1 = va_arg(str, char*);
	else if (type == 'd' || type == 'i')
	{
		nb = va_arg(str, unsigned long long int);
		list->arg_sign = (nb > 0) ? 1 : -1;
		nb = (nb > 0) ? nb : nb * (-1);
		str1 = ft_ullitoa(nb, list->arg_sign);
	}
	else if (type == 'u')
		str1 = ft_itoa(va_arg(str, unsigned int));
	else if (type == 'o')
		str1 = ft_itoa(ft_convert108(va_arg(str, int)));
	else if (type == 'f')
		str1 = ft_start_double(va_arg(str, double));
	return (str1);
}

result_list		*ft_create_list_result()
{
	result_list	*new_lst;

	if (!(new_lst = (result_list*)malloc(sizeof(result_list))))
		return (0);
	if (!(new_lst->data = (char*)malloc(sizeof(char))))
		return (0);
	new_lst->data = 0;
	return (new_lst);
}

int				ft_printf(const char *format, ...)
{
	va_list		str;
	int			i;
	result_list	*res_str;
	result_list	*res_head;
	result_list	*res_tmp;
	var			*var_tmp;

	i = 0;
	res_str = (result_list*)malloc(sizeof(result_list));
	res_head = res_str;
	va_start(str, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%' && format[i] != '\0')
		{
			if (!(res_tmp = (result_list*)malloc(sizeof(res_str))))
				return (0);
			res_str->next = res_tmp;
			res_str = res_tmp;
			res_str->data = ft_strnew(0);
			res_str->data[0] = '\0';
			while (format[i] != '%' && format[i] != '\0')
				res_str->data = ft_strjoin_char(res_str->data, format[i++]);
		}
		if (format[i] == '%')
		{
			res_tmp = (result_list*)malloc(sizeof(res_str));
			res_str->next = res_tmp;
			res_str = res_tmp;
			if (!(var_tmp = (var*)malloc(sizeof(var_tmp))))
				return (0);
			var_tmp->data = ft_create_list_var(format, ++i, str, var_tmp);
			while (!ft_check_type(format[i]) && format[i] != '\0')
				i++;
			res_str->data = var_tmp->data;
			free(var_tmp);
			i++;
		}
		res_str->next = 0;
	}
	ft_print_result_list(res_head->next);
	va_end(str);
	return (i + 1);
}
