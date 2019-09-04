#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>

typedef struct	var
{
	int						width;
	int						precision;
	int						arg_sign;
	char					flag;
	char					size1;
	char					size2;
	char					type;
	char*					data;
} var;

typedef struct	result_list
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
}float_struct;

int		ft_printf(const char *format, ...);

char	*ft_print_c(var *s);

char	*ft_print_s(var *s);

char	*ft_print_p(var *s);

char	*ft_print_pc(var *s);

char	*ft_ullitoa(unsigned long long int n, int arg_sign);

char	*ft_print_d(var *s);

char	*ft_print_o(var *s);

char	*ft_print_u(var *s);

char	*ft_print_x(var *s);

char	*ft_print_f(var *s);

char	*ft_print_pc(var *s);

char	*ft_controller(var *tmp);
char	*ft_create_list_var(const char *mas, int i,
			va_list str, var *list);
char	*ft_create_arg_string(char *str1, var *tmp, va_list str, var *list);
int		ft_check_type(char type);
char	*ft_strjoin_char(char *str, char end);
unsigned int		ft_convert108(long long int nmb);
char	*ft_start_double(long double n, int precision);
char	*ft_fil_whitespaces(char *str, int wdth, int len, char space);
char	*ft_end_whitespaces(char *str, int wdth, int len);
char	*ft_crop_str(char *str, int len, int crop);
var		*ft_ntlstn_var(var *tmp);
char	ft_ulli_to_size(unsigned long long int num, char size1, char size2);
result_list		*ft_ifprecent(result_list *res_str,
					const char *format, va_list str, int *i);
result_list		*ft_ifnopercent(result_list *res_str,
					result_list *res_tmp, const char *format, int *i);
var		*ft_ifseedot(var *tmp, int *i, const char *mas);
var		*ft_srchflgs(var *tmp, int *i, const char *mas);

#endif