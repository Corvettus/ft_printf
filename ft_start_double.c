#include "ft_printf.h"
#include <stdio.h>

float_struct	ft_create_double(long double n)
{
	float_struct	tmp;
	double				num;

	num = n;
	tmp.power = 0;
	tmp.mantisa = 0;
	tmp.mantisa_len = 0;
	tmp.res = ft_strnew(0);
	while(num > 10)
	{
		num = num / 10;
		tmp.power++;
	}
	tmp.base = num;
	tmp.mantisa = n - (long double)(long int)n;
//	printf("Num :%f\n", num);
//	printf("Base :%d\n", tmp.base);
//	printf("Mantisa :%f\n", tmp.mantisa);
	tmp.mantisa += 0.0000005;
	while(((tmp.mantisa) != (long int)(tmp.mantisa)) && tmp.mantisa_len < 6)
		{
			tmp.mantisa_len++;
			tmp.mantisa *= 10;	
//			printf("%f\n", tmp.mantisa);
		}
//	printf("Mantisa Len :%d\n", tmp.mantisa_len);
//	printf("Mantisa :%f\n", tmp.mantisa);
	tmp.num = n;
	if (n < 0)
	{
		tmp.base *= -1;
		tmp.mantisa *= -1;
	}
	return (tmp);
}

/*char			*ft_ftoa(float_struct tmp)
{
	char			*res;
	size_t			buf;
	int				i;

	i = 0;
	res = ft_strnew(0);
	//res = ft_strjoin(res, tmp.power);
	return (res);
}*/

char			*ft_start_double(long double n)
{
	float_struct	tmp;
	int				len;
	int				wdth;

	wdth = (tmp.mantisa_len) ? (tmp.mantisa_len) : 0;
	tmp = ft_create_double(n);
//	if (n < 0)
//		tmp.res = ft_strjoin("-", tmp.res);
	tmp.res = ft_strjoin(tmp.res, ft_itoa((int)tmp.num));
	if (tmp.mantisa != 0)
	{
		tmp.res = ft_strjoin(tmp.res, ".");
		if (ft_strlen(ft_itoa((int)tmp.mantisa)) < tmp.mantisa_len)
			while (ft_strlen(ft_itoa((int)tmp.mantisa)) < tmp.mantisa_len--)
					tmp.res = ft_strjoin(tmp.res, "0");
		tmp.res = ft_strjoin(tmp.res, ft_itoa((int)tmp.mantisa));
	}
	//ft_putstr(tmp.res);
	return (tmp.res);
}
