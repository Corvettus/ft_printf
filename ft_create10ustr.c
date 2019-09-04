#include "ft_printf.h"

void    ft_create_ui(var *s, unsigned int n)
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
		k /= 10;
	}
	s->data = ft_strnew(buf);
	ft_ui(s, n);
}

void    ft_create_usi(var *s, unsigned short int n)
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
		k /= 10;
	}
	s->data = ft_strnew(buf);
	ft_usi(s, n);
}

void    ft_create_uc(var *s, unsigned char n)
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
		k /= 10;
	}
	s->data = ft_strnew(buf);
	ft_uc(s, n);
}

void    ft_create_uli(var *s, unsigned long int n)
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
		k /= 10;
	}
	s->data = ft_strnew(buf);
	ft_uli(s, n);
}

void    ft_create_ulli(var *s, unsigned long long int n)
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
		k /= 10;
	}
	s->data = ft_strnew(buf);
	ft_ulli(s, n);
}