#include "ft_printf.h"

void    ft_create_oi(var *s, unsigned int n)
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
		k /= 8;
	}
	s->data = ft_strnew(buf);
	ft_oi(s, n);
}

void    ft_create_osi(var *s, unsigned short int n)
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
		k /= 8;
	}
	s->data = ft_strnew(buf);
	ft_osi(s, n);
}

void    ft_create_oc(var *s, unsigned char n)
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
		k /= 8;
	}
	s->data = ft_strnew(buf);
	ft_oc(s, n);
}

void    ft_create_oli(var *s, unsigned long int n)
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
		k /= 8;
	}
	s->data = ft_strnew(buf);
	ft_oli(s, n);
}

void    ft_create_olli(var *s, unsigned long long int n)
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
		k /= 8;
	}
	s->data = ft_strnew(buf);
	ft_olli(s, n);
}