#include "ft_printf.h"

void    ft_create_xui(var *s, unsigned int n)
{
	size_t          buf;
	unsigned int    k;

    if (!n)
		s->data = ft_strdup("0");
	buf = 0;
	k = n;
	while (k)
	{
		buf++;
		k /= 16;
	}
	s->data = ft_strnew(buf);
	ft_xui(s, n);
}

void    ft_create_xusi(var *s, unsigned short int n)
{
	size_t              buf;
	unsigned short int  k;

    if (!n)
		s->data = ft_strdup("0");
	buf = 0;
	k = n;
	while (k)
	{
		buf++;
		k /= 16;
	}
	s->data = ft_strnew(buf);
	ft_xusi(s, n);
}

void    ft_create_xuc(var *s, unsigned char n)
{
	size_t          buf;
	unsigned char   k;

    if (!n)
		s->data = ft_strdup("0");
	buf = 0;
	k = n;
	while (k)
	{
		buf++;
		k /= 16;
	}
	s->data = ft_strnew(buf);
	ft_xuc(s, n);
}

void    ft_create_xuli(var *s, unsigned long int n)
{
	size_t              buf;
	unsigned long int   k;

    if (!n)
		s->data = ft_strdup("0");
	buf = 0;
	k = n;
	while (k)
	{
		buf++;
		k /= 16;
	}
	s->data = ft_strnew(buf);
	ft_xuli(s, n);
}

void    ft_create_xulli(var *s, unsigned long long int n)
{
	size_t                  buf;
	unsigned long long int  k;

    if (!n)
		s->data = ft_strdup("0");
	buf = 0;
	k = n;
	while (k)
	{
		buf++;
		k /= 16;
	}
	s->data = ft_strnew(buf);
	ft_xulli(s, n);
}