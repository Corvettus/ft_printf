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
	int						width;
	int						precision;
	int						arg_sign;
	char					flag;
	char					type;
	char*					data;
} var;

typedef struct result_list
{
	struct result_list*		next;
	char*					data;
} result_list;

typedef struct float_struct
{
	float					num;
	float					mantisa;
	long					sign;
	int						mantisa_len;
	int						base;
	int						power;
	char					*res;
} float_struct;

int     ft_printf(const char *format, ...);

char    *ft_print_c(var *s);

char    *ft_print_s(var *s);

char    *ft_print_p(var *s);

char	*ft_print_pc(var *s);

char    *ft_ullitoa(unsigned long long int n, int arg_sign);

char	*ft_print_d(var *s);

char	*ft_print_o(var *s);

char	*ft_print_u(var *s);

char	*ft_print_X(var *s);

char	*ft_print_f(var *s);

char	*ft_print_pc(var *s);

char	*ft_controller(var *tmp);

int		ft_check_flags(char format);
char	*ft_strjoin_char(char *str, char end);
int		ft_convert108(int nmb);
char	*ft_start_double(long double n);
char	*ft_fil_whitespaces(char *str, int wdth, int len, char space);
char	*ft_end_whitespaces(char *str, int wdth, int len);
char	*ft_crop_str(char *str, int len, int crop);

#endif