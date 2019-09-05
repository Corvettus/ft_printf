/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntlstn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:10:33 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/03 17:10:34 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

var				*ft_ntlstn_var(var *tmp)
{
	tmp->precision = 0;
	tmp->width = 0;
	tmp->data = 0;
	tmp->arg_sign = 1;
	tmp->flag = '?';
	tmp->size1 = 0;
	tmp->size2 = 0;
	return (tmp);
}

char			*ft_create_list_var(const char *mas, int i,
					va_list str, var *list)
{
	char	*str1;
	var		*tmp;

	str1 = 0;
	tmp = (var*)malloc(sizeof(var));
	tmp = ft_srchflgs(tmp, &i, mas);
	if (!ft_check_type(mas[i]) && mas[i] != '\0')
		exit(0);
	tmp->type = mas[i];
	if (mas[i] == '%')
	{
		tmp->data = ft_strnew(1);
		tmp->data = ft_strjoin_char(tmp->data, mas[i]);
		return (ft_controller(tmp));
	}
	str1 = ft_create_arg_string(str1, tmp, str, list);
	if (!(tmp->data))
		tmp->data = str1;
	return (ft_controller(tmp));
}

var				*ft_srchflgs(var *tmp, int *i, const char *mas)
{
	tmp = ft_ntlstn_var(tmp);
	if (mas[*i] == '-' || mas[*i] == '+' || mas[*i] == ' '
		|| mas[*i] == '#' || mas[*i] == '0')
		tmp->flag = mas[(*i)++];
	if (mas[*i] > '0' && mas[*i] <= '9')
	{
		while (mas[*i] >= '0' && mas[*i] <= '9')
			tmp->width = tmp->width * 10 + mas[(*i)++] - '0';
	}
	else if (mas[*i] == '*')
		tmp->width = mas[*i++];
	if (mas[*i] == '.')
		tmp = ft_ifseedot(tmp, i, mas);
	if (mas[*i] == 'L')
		tmp->size1 = mas[(*i)++];
	else
	{
		if (mas[*i] == 'h' || mas[*i] == 'l')
			tmp->size1 = mas[*i++];
		if (mas[*i] == 'h' || mas[*i] == 'l')
			tmp->size2 = mas[(*i)++];
	}
	return (tmp);
}

var				*ft_ifseedot(var *tmp, int *i, const char *mas)
{
	if ((mas[++(*i)] > '0' && mas[*i] <= '9'))
		while (mas[*i] >= '0' && mas[*i] <= '9')
			tmp->precision = tmp->precision * 10 + mas[(*i)++] - '0';
	else if (mas[*i] == '*')
		tmp->precision = -1;
	else if (ft_check_type(mas[(*i)++]))
		tmp->precision = 0;
	else
		exit(0);
	return (tmp);
}
