#include "ft_printf.h"

void	ft_i(var *s, int num)
{
	int	remainder;
	size_t          i;

	i = 0;
	if (num < 0)
		s->data[i++] = '-';
	while (num != 0)
	{
		remainder = num % 10;
		s->data[i++] = '0' + remainder;
		num = num / 10;
	}
	
}

void	ft_si(var *s, short int num)
{
	short int	remainder;
	size_t          i;

	i = 0;
	if (num < 0)
		s->data[i++] = '-';
	while (num != 0)
	{
		remainder = num % 10;
		s->data[i++] = '0' + remainder;
		num = num / 10;
	}
	
}

void	ft_c(var *s, char num)
{
	char	remainder;
	size_t          i;

	i = 0;
	if (num < 0)
		s->data[i++] = '-';
	while (num != 0)
	{
		remainder = num % 10;
		s->data[i++] = '0' + remainder;
		num = num / 10;
	}
	
}

void	ft_li(var *s, long int num)
{
	long int	remainder;
	size_t          i;

	i = 0;
	if (num < 0)
		s->data[i++] = '-';
	while (num != 0)
	{
		remainder = num % 10;
		s->data[i++] = '0' + remainder;
		num = num / 10;
	}
	
}

void	ft_lli(var *s, long long int num)
{
	long long int remainder;
	size_t          i;

	i = 0;
	if (num < 0)
		s->data[i++] = '-';
	while (num != 0)
	{
		remainder = num % 10;
		s->data[i++] = '0' + remainder;
		num = num / 10;
	}
	
}

	/*ft_dllexeption(s, &num);
	if (num < 0)
	{
		s->pmz = -1;
		num = num * (-1);
	}*/