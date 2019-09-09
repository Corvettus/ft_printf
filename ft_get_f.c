#include "ft_printf.h"

char	*ft_get_f(char *str1, var *tmp, va_list str)
{
	if (tmp->size1 == 'l')
		str1 = ft_start_double(va_arg(str, double), tmp->precision);
	else if (tmp->size1 == 'L')
		str1 = ft_start_double(va_arg(str, long double), tmp->precision);
	else
		str1 = ft_start_double(va_arg(str, double), tmp->precision);
	return (str1);
}