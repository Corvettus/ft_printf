/*
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>  //del
#include <string.h> //del
*/

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

var*    controller(var *tmp)
{
    while(1)
    {
        if (tmp->flags == '%')
            ft_print_percent(tmp);
        else if (tmp->flags == 'c')
            ft_print_c(tmp);
        else if (tmp->flags == 's')
            ft_print_s(tmp);
        else if (tmp->flags == 'p')
            ft_print_p(tmp);
        else if (tmp->flags == 'd' || tmp->flags == 'i')
            ft_print_d(tmp);
        else if (tmp->flags == 'o')
            ft_print_o(tmp);
        else if (tmp->flags == 'u' || tmp->flags == 'U')
            ft_print_u(tmp);
        else if (tmp->flags == 'x' || tmp->flags == 'X')
            ft_print_X(tmp);
        if (tmp->flags == 'f')
            ft_print_f(tmp);
    }
}

void    print_result(result_list *res)
{
    while()
}

var*    create_list(const char *mas, int *i, va_list str, result_list* list)
{
    char    *str1;
 
    str1 = va_arg(str, char*);
    var *tmp = (var*)malloc(sizeof(var));
    if ((mas[i] == '+' || mas[i] == '-' || mas[i] == '+' || 
        mas[i] == '#' || mas[i] == '0') && tmp->flags == NULL)
    tmp->flags = ft_strcat(tmp->flags, &mas[i++]);
    else if ((mas[i] > '0' && mas[i] <= '9') || mas[i] == '*')
        tmp->width = mas[i++];
    else if (mas[i] == '.')
        while(mas[i] == '.' || (mas[i] > '0' && mas[i] <= '9')  || mas[i] == '*')
    tmp->precision = ft_strcat(tmp->precision, &mas[i++]);
    if (check_flags(mas[i]))
        exit(0);
    tmp->type = mas[i];
    tmp->data = str1;
    return(ft_controller(tmp));
}

int    start(const char *format, ...)
{
    va_list     str;
    int         i;
    result_list *res_str;
    result_list *head_res_str;
    var         *var_str;
    var         *head_var;

    i = 0;
    head_var = (result_list*)malloc(sizeof(result_list));
    head_res_str = (res_str*)malloc(sizeof(res_str));
    res_str = head_res_str;
    var_str = head_var;
	va_start(str, format);
    while (format[i] != '\0')
    {
        while (format[i] != '%' && format[i] != '\0')
            {
                res_str->str = format[i++];
                res_str = res_str->next;
            }
        if (format[i] == '%')
            {
            res_str = res_str->next;
            res_str = create_list(format, &(++i), str);
            }
        i++;
    }
    ft_lstiter(res_str, print_result());
    va_end(str);
    return (i + 1);
}

int main(void)
{
    int i;

    i = start("Hi %s %d", "test", "9");
    printf("\nКоличество выведенных символов: %i", i);
}
