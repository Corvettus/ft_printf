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

	double f = 0.332432;
	printf("\n|   f :%f|\n", f);
	ft_printf("|My f :%f|\n\n", f);

	printf("|   10f :%10f|\n", f);
	ft_printf("|My 10f :%10f|\n\n", f);
	
	printf("|   -10f :%-10f|\n", f);
	ft_printf("|My -10f :%-10f|\n\n", f);

	printf("|    0.3f :%.3f|\n", f);
	ft_printf("|My  0.3f :%.3f|\n\n", f);

	printf("|    10.3f :%10.3f|\n", f);
	ft_printf("|My  10.3f :%10.3f|\n\n", f);

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
