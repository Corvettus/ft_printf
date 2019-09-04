#include "ft_printf.h"

unsigned int	ft_convert108(long long int nmb)
{
	unsigned int	tmp;
	unsigned int	a;
	int				sign;

	a = 0;
	tmp = 0;
	sign = 1;
	if (nmb < 0)
	{
		nmb = UINT_MAX + nmb;
	}
	while ((unsigned int)nmb > 7)
	{
		a = nmb % 8;
		nmb = nmb / 8;
		tmp = tmp * 10 + a;
	}
	tmp = tmp * 10 + nmb;
	nmb = 0;
	while (tmp > 9)
	{
		a = tmp % 10;
		tmp = tmp / 10;
		nmb = nmb * 10 + a;
	}
	nmb = nmb * 10 + tmp;
	return (nmb);
}
