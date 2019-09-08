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

int			ft_print_result_list(result_list *res, int i)
{
	i = 0;
	while (res)
	{
		ft_putstr(res->data);
			i = ft_strlen(res->data);
		res = res->next;
	}
	return (i);
}

char			*ft_create_arg_string(char *str1, var *tmp,
								va_list str, var *list)
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
		list->arg_sign = (nb > 0) ? 1 : -1;
		nb = (nb > 0) ? nb : nb * (-1);
		str1 = ft_ullitoa(nb, list->arg_sign);
	}
	else if (tmp->type == 'u')
		str1 = ft_itoa(va_arg(str, unsigned int));
	else if (tmp->type == 'o')
		str1 = ft_itoa(ft_convert108(va_arg(str, int)));
	else if (tmp->type == 'f')
		str1 = ft_start_double(va_arg(str, double), tmp->precision);
	return (str1);
}

result_list		*ft_ifnopercent(result_list *res_str,
					result_list *res_tmp, const char *format, int *i)
{
	if (!(res_tmp = (result_list*)malloc(sizeof(res_str))))
		return (0);
	res_str->next = res_tmp;
	res_str = res_tmp;
	res_str->data = ft_strnew(0);
	res_str->data[0] = '\0';
	while (format[*i] != '%' && format[*i] != '\0')
		res_str->data = ft_strjoin_char(res_str->data, format[(*i)++]);
	return (res_str);
}

result_list		*ft_ifprecent(result_list *res_str,
					const char *format, va_list str, int *i)
{
	var			*var_tmp;

	if (!(var_tmp = (var*)malloc(sizeof(var_tmp))))
		exit(0);
	var_tmp->data = ft_create_list_var(format, ++(*i), str, var_tmp);
	while (!ft_check_type(format[*i]) && format[*i] != '\0')
		(*i)++;
	res_str->data = var_tmp->data;
	free(var_tmp);
	(*i)++;
	return (res_str);
}

int				ft_printf(const char *format, ...)
{
	va_list		str;
	int			i;
	result_list	*res_str;
	result_list	*res_head;
	result_list	*res_tmp;
	char		*res;

	i = 0;
	res = ft_strnew(0);
	res_tmp = (result_list*)malloc(sizeof(result_list));
	res_str = (result_list*)malloc(sizeof(result_list));
	res_head = res_str;
	va_start(str, format);
	while (format[i] != '\0')
	{
		res_str->data = 0;
		if (format[i] != '%' && format[i] != '\0')
		{
			res_str = ft_ifnopercent(res_str, res_tmp, format, &i);
			if (res_str->data)
				res = ft_strjoin(res, res_str->data);
		}
		if (format[i] == '%')
		{
			res_str->next = (result_list*)malloc(sizeof(res_str));
			res_str = res_str->next;
			res_str = ft_ifprecent(res_str, format, str, &i);
			if (res_str->data > 0)
				res = ft_strjoin(res, res_str->data);
		}
		res_str->next = 0;
	}
	//i = ft_print_result_list(res_head->next, i);
	ft_putstr(res);
	i = ft_strlen(res);
	free(res_str);
	free(res_tmp);
	va_end(str);
	return (i);
}
