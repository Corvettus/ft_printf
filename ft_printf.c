/*
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>  //del
#include <string.h> //del
*/
#include <stdio.h>

#include "ft_printf.h"

int     check_flags(char format)
{
    if (format != 'c' && format != 'd' && format != 'i' && 
        format != 'e' && format != 'E' && format != 'f' && 
        format != 'g' && format != 'G' && format != 'o' && 
        format != 's' && format != 'u' && format != 'x' && 
        format != 'X' && format != 'p' && format != 'n' && 
        format != '%')
        return(1);
    return(0);
}

char*    ft_controller(var *tmp)
{
    char *res;

    if (tmp->type == '%')
        res = ft_print_pc(tmp);
    else if (tmp->type == 'c')
        res = ft_print_c(tmp);
    else if (tmp->type == 's')
        res = ft_print_s(tmp);
    else if (tmp->type == 'p')
        res = ft_print_p(tmp);
    else if (tmp->type == 'd' || tmp->type == 'i')
        res = ft_print_d(tmp);
    else if (tmp->type == 'o')
        res = ft_print_o(tmp);
    else if (tmp->type == 'u' || tmp->type == 'U')
        res = ft_print_u(tmp);
    else if (tmp->type == 'x' || tmp->type == 'X')
        res = ft_print_X(tmp);
    if (tmp->type == 'f')
        res = ft_print_f(tmp);
    return (res);
}

/*void    print_result(result_list *res)
{
    while()
}*/

char*        create_list_var(const char *mas, int *i, va_list str, var* list)
{
    char    *str1;
     write(1, "2.0\n", 4);
    str1 = va_arg(str, char*);
    write(1, "2.1\n", 4);
    var *tmp = (var*)malloc(sizeof(var));
    if ((mas[*i] == '+' || mas[*i] == '-' || mas[*i] == '+' || 
        mas[*i] == '#' || mas[*i] == '0') && !tmp->flags)
    tmp->flags = ft_strcat(tmp->flags, &mas[*i++]);
    else if ((mas[*i] > '0' && mas[*i] <= '9') || mas[*i] == '*')
        tmp->width = mas[*i++];
    else if (mas[*i] == '.')
        while(mas[*i] == '.' || (mas[*i] > '0' && mas[*i] <= '9')  || mas[*i] == '*')
    tmp->precision = ft_strcat(tmp->precision, &mas[*i++]);
    if (check_flags(mas[*i]))
        exit(0);
    write(1, "2.2\n", 4);
    tmp->type = mas[*i];
    tmp->data = str1;
    write(1, "2.3\n", 4);
    return(ft_controller(tmp));
}

result_list* create_list_result()
{
    result_list	*new_lst;

	if (!(new_lst = (result_list*)malloc(sizeof(result_list))))
		return (0);
    if(!(new_lst->data = (char*)malloc(sizeof(char))))
        return (0);
	new_lst->data = 0;
	return (new_lst);
}

int         ft_printf(const char *format, ...)
{
    va_list     str;
    int         i;
    result_list *res_str;
    result_list *res_head;
    result_list *res_tmp;
    var         *var_str;
    var         *var_head;
    var         *var_tmp;

    i = 0;
    var_str = (var*)malloc(sizeof(var));
    res_str = (result_list*)malloc(sizeof(result_list));
    res_head = res_str;
    var_head = var_str;
	va_start(str, format);
    while (format[i] != '\0')
    {
        res_tmp = (result_list*)malloc(sizeof(result_list));
        res_str->next = res_tmp;
        res_str = res_tmp;
        
        while (format[i] != '%' && format[i] != '\0')
            {
                res_str->data = ft_strnew(1);
                /*    write(1, "1.1\n", 4);
                res_str->data[0] = format[i++];
                    write(1, "1.2\n", 4);
                res_tmp = res_str;
                    write(1, "1.3\n", 4);
                res_str = create_list_result();
                    write(1, "1.3\n", 4);
                res_str = res_tmp->next;
                    write(1, "1.3\n", 4);*/
                res_str->data = ft_strjoin(res_str->data, &format[i++]);
            }
        if (format[i] == '%')
            {
                ++i;
                var_tmp = (var*)malloc(sizeof(var_tmp));
                write(1, "1.0\n", 4);
                var_tmp->data = create_list_var(format, &i, str, var_tmp);
                write(1, "1.1\n", 4);
                res_str->data = var_tmp->data;
                write(1, "1.2\n", 4);
                //free_var(var_tmp)
            }
        i++;
    }
    write(1, "1\n", 1);
    printf("%s", "res_str->data");
    //ft_lstiter(res_str, print_result(res_str));
    va_end(str);
    return (i + 1);
}
