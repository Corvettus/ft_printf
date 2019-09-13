#include "ft_printf.h"

char	*ft_get_x(char *str1, var *tmp, va_list str)
{
	int long long	nb;

	nb = 0;
	if (tmp->size1 == 'h' && tmp->type != 'p')
	{
		if (tmp->size2 == 'h')
			nb = (unsigned char)va_arg(str, unsigned int);
		else
			nb = (unsigned short int)va_arg(str, unsigned int);
	}
	else if (tmp->size1 == 'j' && tmp->type != 'p')
		nb = va_arg(str, uintmax_t);
	else if (tmp->size1 == 'z' && tmp->type != 'p')
		nb = va_arg(str, size_t);
	else
		nb = (unsigned long long int)va_arg(str, unsigned long long int);
	str1 = ft_itoa_base(nb, 16, tmp->type);
	return (str1);
}
