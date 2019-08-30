#include "ft_printf.h"
#include <stdio.h>

char	*ft_ftoa(double n)
{
	char	*res;
	double	k;
	size_t	buf;

	while (k)
	{
		buf++;
		k /= 10;
	}
	if (!(res = (char*)malloc(buf * sizeof(char))))
		return (0);
	res[--buf] = 0;
	
	printf("%f\n", n);
	return (res);
}