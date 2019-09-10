#include "ft_printf.h"

char	*ft_llxtoa(var *s, unsigned long long int n)
{
	char					*res;
	unsigned long long int	k;
	size_t					buf;

	k = n;
	!k ? buf = 1 : buf = 0;
	while (k)
	{
		buf++;
		k /= 16;
	}
	if (!(res = ft_strnew((size_t)buf)))
		return (0);
	res[--buf] = 0;
	if (s->size1 == 'h')
	{
		if (s->size2 == 'h')
			ft_xi(s, n, ++buf);
		else
			ft_xsi(s, n, ++buf);
	}
	else
		ft_xlli(s, n, ++buf);
	return (res);
}

char	*ft_get_x(char *str1, var *tmp, va_list str)
{
	int long long nb;

	nb = 0;
	if (tmp->size1 == 'h')
	{
		if (tmp->size2 == 'h')
			nb = (unsigned char)va_arg(str, unsigned int);
		else
			nb = (unsigned short int)va_arg(str, unsigned int);
	}
	else
		nb = va_arg(str, unsigned long long int);
	str1 = ft_llxtoa(tmp, nb);
	return (str1);
}