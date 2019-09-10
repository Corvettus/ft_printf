#include "ft_printf.h"

static void	ft_puting_ulli_to_a(unsigned long long int n, char **res, size_t buf)
{
	while (n)
	{
		(*res)[--buf] = (char)(n % 10 + '0');
		n /= 10;
	}
}

char		*ft_ullitoa(long long int nb, var *tmp)
{
	char					*res;
	unsigned long long int	k;
	size_t					buf;

    (void)tmp->arg_sign;
	//nb = (nb < 0) ? ULONG_MAX + nb : nb;
	buf = 1;
	k = nb;
	while (k)
	{
		buf++;
		k /= 10;
	}
	if (!(res = (char*)malloc(buf * sizeof(char))))
		return (0);
	res[--buf] = 0;
	ft_puting_ulli_to_a(nb, &res, buf);
	return (res);
}
