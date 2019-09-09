#include "ft_printf.h"

void ft_xi(char *s, unsigned long long int num, int sz)
{
    unsigned int	remainder;
    unsigned int	localnum;
    size_t			i;

    if (!sz)
	sz = 'a' - 'A';
    i = 0;
    localnum = (unsigned int)num;
    if (localnum == 0)
    	s[i++] = '0' + localnum;
    while (localnum != 0)
    {
		remainder = localnum % 16;
		if (remainder < 10)
			s[i++] = '0' + remainder;
		else
			s[i++] = 'A' + remainder - 10 + sz;
		localnum = localnum / 16;
    }
}

char *ft_create_xi(char *s, unsigned int n, int sz)
{
	size_t buf;
	unsigned int k;

	if (!n)
		s= ft_strdup("0");
	buf = 0;
	k = n;
	while (k)
	{
		buf++;
		k /= 16;
	}
	s = ft_strnew(buf);
	ft_xi(s, n, sz);
	return (s);
}
