#include "ft_printf.h"

void	ft_ulli_to_size(var *s, unsigned long long int num)
{
	unsigned long long int  remainder;
	size_t                  i;

	i = 0;
	while (num != 0)
	{
		remainder = num % 10;
		s->data[i++] = '0' + remainder;
		num = num / 10;
	}
}