#include "ft_printf.h"

char *ft_get_x(char *str1, var *tmp, va_list str)
{
	int long long nb;

	if (tmp->size1 == 'h')
	{
		if (tmp->size2 == 'h')
			nb = (unsigned char)va_arg(str, unsigned char);
		else
			nb = (unsigned short int)va_arg(str, unsigned short int);
	}
	else
		nb = va_arg(str, unsigned long long int);
	str1 = ft_llxtoa(nb);
	return (str1);
}

char		*ft_llxtoa(unsigned long long int n)
{
	char					*res;
	unsigned long long int	k;
	size_t					buf;

	buf = 1;
	k = n;
	while (k)
	{
		buf++;
		k /= 16;
	}
	if (!(res = (char*)malloc(buf * sizeof(char))))
		return (0);
	res[--buf] = 0;
	ft_xulli(n, &res, buf);
	return (res);
}