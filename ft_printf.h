#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>

typedef struct var
{
    char*                   origin_data;
    char                    sign;
    char*                   flags;
    int                     width;
    char*                   precision;
    char                    type;
    char*                   data;
    struct var*             next;
} var;

typedef struct result_list
{
	char*				    data;
	struct result_list*	    next;
} result_list;

int     ft_printf(const char *format, ...);
char    *ft_print_c(var *s);
char    *ft_print_s(var *s);
char    *ft_print_p(var *s);
char    *ft_print_pc(var *s);
char    *ft_print_d(var *s);
char    *ft_print_o(var *s);
char    *ft_print_u(var *s);
char    *ft_print_X(var *s);
char    *ft_print_f(var *s);
char    *ft_print_pc(var *s);
char    *ft_controller(var *tmp);

#endif