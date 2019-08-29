#include "ft_printf.h"

int     ft_convert108(int nmb)
{
	int tmp;
	int a;

	a = 0;
	tmp = 0;
	while (nmb > 7)
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