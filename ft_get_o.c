#include "ft_printf.h"

char	*ft_get_o(char *str1, var *tmp, va_list str)
{
	intmax_t	nb;

	nb = 0;
	if (tmp->size1 == 'l')
	{
		if (tmp->size2 == 'l')
			nb = va_arg(str, long long int);
		else
			nb = va_arg(str, long int);
	}
	else if (tmp->size1 == 'h')
	{
		if (tmp->size2 == 'h')
			nb = (signed char)va_arg(str, int);
		else
			nb = (short int)va_arg(str, int);
	}
	else
		nb = va_arg(str, int);
	str1 = ft_itoa_base(nb, 8, tmp->type);
	return (str1);
}
