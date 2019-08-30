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

	double f = 10.23439;
	printf( "%.2f\n", f );
	ft_printf( "%f", f );

	//printf("*%d*\n", PAGES);
	//printf("*%2d*\n", PAGES);
	//printf("*%10d*\n", PAGES);
	//printf("*%-10d*\n", PAGES);

	//printf("%-20s|\n", "this is a test");
	//ft_printf("%-20s|\n", "this is a test");
	//printf("%20s|\n", "this is a test");
	//ft_printf("%15s|", "this is a test");
	return (0);
}
