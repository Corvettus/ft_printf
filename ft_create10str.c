#include "ft_printf.h"

void    ft_create_i(var *s, int n)
{
	size_t          buf;
	int    k;

    if (!n)
		s->data = ft_strdup("0");
	buf = 0;
	k = n;
	while (k)
	{
		buf++;
		k /= 10;
	}
	if (n < 0)
		buf++;
	s->data = ft_strnew(buf);
	ft_i(s, n);
}

void    ft_create_si(var *s, short int n)
{
	size_t              buf;
	short int  k;

    if (!n)
		s->data = ft_strdup("0");
	buf = 0;
	k = n;
	while (k)
	{
		buf++;
		k /= 10;
	}
	if (n < 0)
		buf++;
	s->data = ft_strnew(buf);
	ft_si(s, n);
}

void    ft_create_c(var *s, char n)
{
	size_t          buf;
	char   k;

	if (!n)
		s->data = ft_strdup("0");
	buf = 0;
	k = n;
	while (k)
	{
		buf++;
		k /= 10;
	}
	if (n < 0)
		buf++;
	s->data = ft_strnew(buf);
	ft_c(s, n);
}

void    ft_create_li(var *s, long int n)
{
	size_t              buf;
	long int   k;

    if (!n)
		s->data = ft_strdup("0");
	buf = 0;
	k = n;
	while (k)
	{
		buf++;
		k /= 10;
	}
	if (n < 0)
		buf++;
	s->data = ft_strnew(buf);
	ft_li(s, n);
}

void    ft_create_lli(var *s, long long int n)
{
	size_t                  buf;
	long long int  k;

    if (!n)
		s->data = ft_strdup("0");
	buf = 0;
	k = n;
	while (k)
	{
		buf++;
		k /= 10;
	}
	if (n < 0)
		buf++;
	s->data = ft_strnew(buf);
	ft_lli(s, n);
}