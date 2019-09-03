#include "ft_printf.h"

int				ft_check_type(char type)
{
	if (type == 'c' || type == 'd' || type == 'i' ||
		type == 'e' || type == 'E' || type == 'f' ||
		type == 'g' || type == 'G' || type == 'o' ||
		type == 's' || type == 'u' || type == 'x' ||
		type == 'X' || type == 'p' || type == 'n' ||
		type == '%')
		return (1);
	return (0);
}
