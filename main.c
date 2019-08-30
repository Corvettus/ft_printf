#include <stdio.h>
#include "ft_printf.h"
#define PAGES 959


int main(void)
{
//	int i = 1234324;
//	char s[4];
//	printf("start %10.6s\n", "flexyiyiyiyi");
//	ft_printf("start %10.6s", "flexyiyiyiyi");
//	printf("start %d\n", i);
//	ft_printf("start %o\n", i);
//	printf("start %o\n", i);
	double f = 1.23439;
	printf( "%f\n", f );
	ft_printf( "%f", f );
	//printf("*%d*\n", PAGES);
	//printf("*%2d*\n", PAGES);
	//printf("*%10d*\n", PAGES);
	//printf("*%-10d*\n", PAGES);

	return (0);
}
