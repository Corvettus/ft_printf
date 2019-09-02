#include "ft_printf.h"

static void	puting_ulli_to_a(unsigned long long int n, char **res, size_t buf)
{
	while (n)
	{
		(*res)[--buf] = (char)(n % 10 + '0');
		n /= 10;
	}
}

char		*ft_ullitoa(unsigned long long int n, int arg_sign)
{
	char					*res;
	unsigned long long int	k;
	size_t					buf;

	/*if (!n)
		return (ft_strdup("0"));*/
	buf = 1;
	k = n;
	/*ft_putstr("OK");
	ft_putnbr(k);
	ft_putchar('\n');*/
	while (k)
	{
		buf++;
		k /= 10;
	}
	/*ft_putnbr(k);
	ft_putstr("OK");
	ft_putchar('\n');*/
	if (!(res = (char*)malloc(buf * sizeof(char))))
		return (0);
	res[--buf] = 0;
	puting_ulli_to_a(n, &res, buf);
	if (arg_sign == -1)
		res = ft_strjoin("-", res);
	return (res);
}