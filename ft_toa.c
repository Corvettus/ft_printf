#include "ft_printf.h"

static void	puting_ulli_to_a(unsigned long long int n, char **res, size_t buf)
{
	while (n)
	{
		(*res)[--buf] = (char)(n % 10 + '0');
		n /= 10;
	}
}

char		*ft_ullitoa(unsigned long long int n)
{
	char	*res;
	int		k;
	size_t	buf;

	if (!n)
		return (ft_strdup("0"));
	buf = 1;
	k = n;
	while (k)
	{
		buf++;
		k /= 10;
	}
	if (!(res = (char*)malloc(buf * sizeof(char))))
		return (0);
	res[--buf] = 0;
	puting_ulli_to_a(n, &res, buf);
	return (res);
}