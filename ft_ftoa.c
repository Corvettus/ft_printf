#include "ft_printf.h"
#include <stdio.h>

/*char	*ft_ftoa(double n)
{
	char	*res;
	double	k;
	size_t	buf;
	float_struct 

	while(n > 10)
	{
		n = n / 10.0;
		
	}
	printf("%f\n", n);
	return (res);
}*/

char	*ft_create_double(double n)
{
	char			*res;
	float_struct	tmp;
	double			num;

	num = n;
	tmp.power = 0;
	tmp.mantisa = 0;
	tmp.mantisa_len = 0;
	while(num > 10)
	{
		num = num / 10;
		tmp.power++;
	}
	tmp.mantisa = (double)num - tmp.power;
	printf("%f\n", num);
	printf("power %d\n", tmp.power);
	printf("mantisa %f\n", tmp.mantisa);	
	while((num) != (int)(num))
		{
			tmp.mantisa_len++;
			num *= 10;	
		}
	printf("mantisa len %d\n", tmp.mantisa_len);
	return (res);
}