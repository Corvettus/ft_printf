#include <stdio.h>
#include "ft_printf.h"


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

	printf("   |%-5.2s|\n", NULL);
	ft_printf("My |%-5.2s|\n\n", NULL);

	printf("   |%-5.6s|\n", NULL);
	ft_printf("My |%-5.6s|\n\n", NULL);


	// 8 
	int i = 1234324;
	printf("     |%d|\n\n", i);

	printf("   o:|%o|\n", i);
	ft_printf("My o:|%o|\n\n", i);

	printf("   0.3o:|%0.3o|\n", i);
	ft_printf("My 0.3o:|%0.3o|\n\n", i);

	printf("   .3o:|%.3o|\n", i);
	ft_printf("My .3o:|%.3o|\n\n", i);

	printf("   0.14o:|%0.14o|\n", i);
	ft_printf("My 0.14o:|%0.14o|\n\n", i);

	printf("   2.14o:|%2.14o|\n", i);
	ft_printf("My 2.14o:|%2.14o|\n\n", i);

	printf("   2.14o:|%2.14o|\n", i);
	ft_printf("My 2.14o:|%2.14o|\n\n", i);
	
	printf("   .14o:|%.14o|\n", i);
	ft_printf("My .14o:|%.14o|\n\n", i);

	printf("   10o:|%10o|\n", i);
	ft_printf("My 10o:|%10o|\n\n", i);

	printf("   -10o:|%-10o|\n", i);
	ft_printf("My -10o:|%-10o|\n\n", i);

	printf("   .3o:|%.3o|\n", i);
	ft_printf("My .30:|%.3o|\n\n", i);

	printf("   10.3o:|%10.3o|\n", i);
	ft_printf("My 10.3o:|%10.3o|\n\n", i);

	printf("   10.5o:|%10.5o|\n", i);
	ft_printf("My 10.5o:|%10.5o|\n\n", i);

	// DOUBLE
	double f = 10.0;
	printf("\n   f:|%f|\n", f);
	ft_printf("My f:|%f|\n\n", f);

	printf("   5f:|%5f|\n", f);
	ft_printf("My 5f:|%5f|\n\n", f);

	printf("   10f:|%10f|\n", f);
	ft_printf("My 10f:|%10f|\n\n", f);
	
	printf("   -30f:|%-30f|\n", f);
	ft_printf("My -30f:|%-30f|\n\n", f);

	printf("    0.3f :|%.3f|\n", f);
	ft_printf("My  0.3f :|%.3f|\n\n", f);

	printf("    10.3f:|%10.3f|\n", f);
	ft_printf("My  10.3f:|%10.3f|\n\n", f);

	// INT ??
	int num = 65426;
	printf("   d:|%d|\n", num);
	ft_printf("My d:|%d|\n\n", num);

	printf("   2d:|%2d|\n", num);
	ft_printf("My 2d:|%2d|\n\n", num);

	printf("   10d:|%10d|\n", num);
	ft_printf("My 10d:|%10d|\n\n", num);

	printf("    -10d|%-10d|\n", num);
	ft_printf(" My -10d|%-10d|\n\n", num);

	// CHAR
	int c = 'A';
	printf("   c:|%c|\n", c);
	ft_printf("My c:|%c|\n\n", c);

	printf("   c:|%2c|\n", c);
	ft_printf("My c:|%2c|\n\n", c);

	printf("   10c:|%10c|\n", c);
	ft_printf("My 10c:|%10c|\n\n", c);

	printf("    -10c|%-10c|\n", c);
	ft_printf(" My -10c|%-10c|\n\n", c);

}

