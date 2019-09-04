#include "ft_printf.h"

void	ft_oi(var *s, unsigned int num)
{
	unsigned int    remainder;
	size_t          i;

	i = 0;
	while (num != 0)
	{
		remainder = num % 8;
		s->data[i++] = '0' + remainder;
		num = num / 8;
	}
}

void	ft_osi(var *s, unsigned short int num)
{
	unsigned short int	remainder;
	size_t              i;

	i = 0;
	while (num != 0)
	{
		remainder = num % 8;
		s->data[j++] = '0' + remainder;
		num = num / 8;
	}
}

void	ft_oc(var *s, unsigned char num)
{
	unsigned char	remainder;
	size_t          i;

	i = 0;
	while (num != 0)
	{
		remainder = num % 8;
		s->data[j++] = '0' + remainder;
		num = num / 8;
	}
}

void	ft_oli(var *s, unsigned long int num)
{
	unsigned long int	remainder;
	size_t              i;

	i = 0;
	while (num != 0)
	{
		remainder = num % 8;
		s->data[j++] = '0' + remainder;
		num = num / 8;
	}
}

void	ft_olli(var *s, unsigned long long int num)
{
	unsigned long long int  remainder;
	size_t                  i;

	i = 0;
	while (num != 0)
	{
		remainder = num % 8;
		s->data[i++] = '0' + remainder;
		num = num / 8;
	}
}
