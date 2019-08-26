/*
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>  //del
#include <string.h> //del
*/
#include "ft_printf.h"

int				check_flags(char format)
{
	if (format != 'c' && format != 'd' && format != 'i' &&
		format != 'e' && format != 'E' && format != 'f' &&
		format != 'g' && format != 'G' && format != 'o' &&
		format != 's' && format != 'u' && format != 'x' &&
		format != 'X' && format != 'p' && format != 'n' &&
		format != '%')
		return (1);
	return (0);
}

void			print_result_list(result_list *res)
{
	while (res)
	{
		ft_putstr(res->data);
		res = res->next;
	}
}

char			*create_list_var(const char *mas, int *i,
					va_list str, var *list)
{
	char	*str1;
	var		*tmp;

	str1 = va_arg(str, char*);
	tmp = (var*)malloc(sizeof(var));
	if ((mas[*i] == '+' || mas[*i] == '-' || mas[*i] == '+' ||
		mas[*i] == '#' || mas[*i] == '0') && !tmp->flags)
	tmp->flags = ft_strcat(tmp->flags, &mas[*i++]);
	else if ((mas[*i] > '0' && mas[*i] <= '9') || mas[*i] == '*')
		tmp->width = mas[*i++];
	else if (mas[*i] == '.')
		while (mas[*i] == '.' || (mas[*i] > '0' && mas[*i] <= '9') ||
				mas[*i] == '*')
	tmp->precision = ft_strcat(tmp->precision, &mas[*i++]);
	if (check_flags(mas[*i]))
		exit(0);
	tmp->type = mas[*i];
	tmp->data = str1;
	return (ft_controller(tmp));
}

result_list		*create_list_result()
{
	result_list	*new_lst;

	if (!(new_lst = (result_list*)malloc(sizeof(result_list))))
		return (0);
	if (!(new_lst->data = (char*)malloc(sizeof(char))))
		return (0);
	new_lst->data = 0;
	return (new_lst);
}

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

int				ft_printf(const char *format, ...)
{
	va_list		str;
	int			i;
	result_list	*res_str;
	result_list	*res_head;
	result_list	*res_tmp;
	var			*var_str;
	var			*var_head;
	var			*var_tmp;

	i = 0;
	var_str = (var*)malloc(sizeof(var));
	res_str = (result_list*)malloc(sizeof(result_list));
	res_head = res_str;
	var_head = var_str;
	va_start(str, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%' && format[i] != '\0')
		{
			res_tmp = (result_list*)malloc(sizeof(res_str));
			res_str->next = res_tmp;
			res_str = res_tmp;
			res_str->data = ft_strnew(0);
			res_str->data[0] = '\0';
			while (format[i] != '%' && format[i] != '\0')
				res_str->data = ft_strjoin_char(res_str->data, format[i++]);
		}
		if (format[i++] == '%')
		{
			res_tmp = (result_list*)malloc(sizeof(res_str));
			res_str->next = res_tmp;
			res_str = res_tmp;
			var_tmp = (var*)malloc(sizeof(var_tmp));
			var_tmp->data = create_list_var(format, &i, str, var_tmp);
			res_str->data = var_tmp->data;
			//free_var(var_tmp)
		}
		res_str->next = 0;
		i++;
	}
	print_result_list(res_head->next);
	va_end(str);
	return (i + 1);
}
