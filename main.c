#include <stdio.h>
#include "ft_printf.h"
#define PAGES 959


int main(void)
{
	// STRING
	printf("   |%5s|\n", "this is a test");
	ft_printf("My |%5s|\n\n", "this is a test");

	printf("   |%25s|\n", "this is a test");
	ft_printf("My |%25s|\n\n", "this is a test");

	printf("   |%-20s|\n", "this is a test");
	ft_printf("My |%-20s|\n\n", "this is a test");

	printf("   |%-5s|\n", "this is a test");
	ft_printf("My |%-5s|\n\n", "this is a test");

	printf("   |%25.6s|\n", "this is a test");
	ft_printf("My |%25.6s|\n\n", "this is a test");

	printf("   |%-20.6s|\n", "this is a test");
	ft_printf("My |%-20.6s|\n\n", "this is a test");

	printf("   |%5.6s|\n", "this is a test");
	ft_printf("My |%5.6s|\n\n", "this is a test");

	printf("   |%-5.6s|\n", "this is a test");
	ft_printf("My |%-5.6s|\n\n", "this is a test");

	// HEX
	int i = 1234324;
	printf("     |%d|\n", i);
	printf("   o:|%o|\n", i);
	ft_printf("My o:|%o|\n\n", i);

	printf("   10o:|%10o|\n", i);
	ft_printf("My 10o:|%10o|\n\n", i);

	printf("   -10o:|%-10o|\n", i);
	ft_printf("My -10o:|%-10o|\n\n", i);

	printf("   .3o:|%.3o|\n", i);
	ft_printf("My .30:|%.3o|\n\n", i);

	printf("   10.3:|%10.3o|\n", i);
	ft_printf("My 10.3:|%10.3o|\n\n", i);


	// DOUBLE
	double f = 10.332432;
	printf("\n   f :|%f|\n", f);
	ft_printf("My f :|%f|\n\n", f);

	printf("   5f :|%5f|\n", f);
	ft_printf("My 5f :|%5f|\n\n", f);

	printf("   10f :|%10f|\n", f);
	ft_printf("My 10f :|%10f|\n\n", f);
	
	printf("   -30f :|%-30f|\n", f);
	ft_printf("My -30f :|%-30f|\n\n", f);

	printf("    0.3f :|%.3f|\n", f);
	ft_printf("My  0.3f :|%.3f|\n\n", f);

	printf("    10.3f :|%10.3f|\n", f);
	ft_printf("My  10.3f :|%10.3f|\n\n", f);


	//printf("*%d*\n", PAGES);
	//printf("*%2d*\n", PAGES);
	//printf("*%10d*\n", PAGES);
	//printf("*%-10d*\n", PAGES);

	return (0);
}
