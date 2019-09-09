#include "ft_printf.h"

void	ft_xui(var *s,  int num, int sz)
{
	unsigned int	remainder;
	unsigned int	localnum;
	size_t          i;

	i = 0;
	localnum = (unsigned int)num;
	if (localnum == 0)
		s->data[i++] = '0' + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			s->data[i++] = '0' + remainder;
		else
			s->data[i++] = 55 + remainder + sz;
		localnum = localnum / 16;
	}
	
}

void	ft_xusi(var *s, unsigned long long int num,
	int sz)
{
	unsigned short int	remainder;
	unsigned short int	localnum;
	size_t          i;

	i = 0;
	localnum = (unsigned short int)num;
	if (localnum == 0)
		s->data[i++] = '0' + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			s->data[i++] = '0' + remainder;
		else
			s->data[i++] = 55 + remainder + sz;
		localnum = localnum / 16;
	}
	
}

void	ft_xuc(var *s, unsigned long long int num,
	int sz)
{
	unsigned char	remainder;
	unsigned char	localnum;
	size_t          i;

	i = 0;
	localnum = (unsigned char)num;
	if (localnum == 0)
		s->data[i++] = '0' + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			s->data[i++] = '0' + remainder;
		else
			s->data[i++] = 55 + remainder + sz;
		localnum = localnum / 16;
	}
	
}

void	ft_xuli(var *s, unsigned long long int num,
	int sz)
{
	unsigned long int	remainder;
	unsigned long int	localnum;
	size_t          i;

	i = 0;
	localnum = (unsigned long int)num;
	if (localnum == 0)
		s->data[i++] = '0' + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			s->data[i++] = '0' + remainder;
		else
			s->data[i++] = 55 + remainder + sz;
		localnum = localnum / 16;
	}
	
}

void	ft_xulli(var *s, unsigned long long int num,
	int sz)
{
	unsigned long long int	remainder;
	unsigned long long int	localnum;
	size_t          i;

	i = 0;
	localnum = (unsigned long long int)num;
	if (localnum == 0)
		s->data[i++] = '0' + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			s->data[i++] = '0' + remainder;
		else
			s->data[i++] = 55 + remainder + sz;
		localnum = localnum / 16;
	}
	
}
	//s->i--;
	//while (s->i < s->i)
	//{
	//	remainder = s->data[i];
	//	s->data[i++] = s->data[i];
	//	s->data[i--] = remainder;
	//}
	//ft_bufioin_x(ran, s);