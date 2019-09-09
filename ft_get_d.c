#include "ft_printf.h"

char        *ft_get_d(char *str1, var *tmp, va_list str)
{
	intmax_t	nb;
	
	nb = 0;
	if (tmp->size1 == 'l')
	{
		if (tmp->size2 == 'l')
			nb = va_arg(str, int long long);
		else
			nb = (int long)va_arg(str, int long);
	}
	else if (tmp->size1 == 'h')
	{
		if (tmp->size2 == 'h')
			nb = (unsigned int)va_arg(str, unsigned int);
		else
			nb = (short int)va_arg(str, int);
	}
    else 
    	nb = va_arg(str, int);
	str1 = ft_llitoa(nb, tmp);
    return (str1);
}