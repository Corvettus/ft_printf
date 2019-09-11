#include <stdio.h>
#include "ft_printf.h"


int	main(void)
{
/*	// STRING
	printf("   5s|%5s|\n", "this is a test");
	ft_printf("My 5s|%5s|\n\n", "this is a test");

	printf("   25s|%25s|\n", "this is a test");
	ft_printf("My 25s|%25s|\n\n", "this is a test");

	printf("   -20s|%-20s|\n", "this is a test");
	ft_printf("My -20s|%-20s|\n\n", "this is a test");

	printf("   -5s|%-5s|\n", "this is a test");
	ft_printf("My -5s|%-5s|\n\n", "this is a test");

	printf("   25.6s|%25.6s|\n", "this is a test");
	ft_printf("My 25.6s|%25.6s|\n\n", "this is a test");

	printf("   -20.6s|%-20.6s|\n", "this is a test");
	ft_printf("My -20.6s|%-20.6s|\n\n", "this is a test");

	printf("   5.6s|%5.6s|\n", "this is a test");
	ft_printf("My 5.6s|%5.6s|\n\n", "this is a test");

	printf("   -5.6s|%-5.6s|\n", "this is a test");
	ft_printf("My -5.6s|%-5.6s|\n\n", "this is a test");

	printf("   -5.2s|%-5.2s|\n", NULL);
	ft_printf("My -5.2s|%-5.2s|\n\n", NULL);

	printf("   -5.6s|%-5.6s|\n", NULL);
	ft_printf("My -5.6s|%-5.6s|\n\n", NULL);

	printf("   5.15s|%5.15s|\n", NULL);
	ft_printf("My 5.15s|%5.15s|\n\n", NULL);

	printf("   -5.16s|%-5.16s|\n", NULL);
	ft_printf("My -5.16s|%-5.16s|\n\n", NULL);

	// 8 
	int i = 1234324;
	printf("     |%d|\n\n", i);

	printf("   o:|%o|\n", i);
	ft_printf("My o:|%o|\n\n", i);

	printf("   -o:|%o|\n", -i);
	ft_printf("My -o:|%o|\n\n", -i);

	printf("   0.3o:|%0.3o|\n", i);
	ft_printf("My 0.3o:|%0.3o|\n\n", i);

	printf("   .3o:|%.3o|\n", i);
	ft_printf("My .3o:|%.3o|\n\n", i);

	printf("   0.14o:|%0.14o|\n", i);
	ft_printf("My 0.14o:|%0.14o|\n\n", i);

	printf("   0.14-o:|%0.14o|\n", -i);
	ft_printf("My 0.14-o:|%0.14o|\n\n", -i);

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
	double f = 1023.2345;
	printf("\n   f:|%f|\n", f);
	ft_printf("My f:|%f|\n\n", f);

	printf("\n   -f:|%f|\n", -f);
	ft_printf("My -f:|%f|\n\n", -f);

	printf("   5f:|%5f|\n", f);
	ft_printf("My 5f:|%5f|\n\n", f);

	printf("   5-f:|%5f|\n", -f);
	ft_printf("My 5-f:|%5f|\n\n", -f);

	printf("   10f:|%10f|\n", f);
	ft_printf("My 10f:|%10f|\n\n", f);
	
	printf("   -30f:|%-30f|\n", f);
	ft_printf("My -30f:|%-30f|\n\n", f);

	printf("    0.3f :|%.3f|\n", f);
	ft_printf("My  0.3f :|%.3f|\n\n", f);

	printf("    10.3f:|%10.3f|\n", f);
	ft_printf("My  10.3f:|%10.3f|\n\n", f);

	// INT ??
	int num1 = 65426;

	printf("   d:|%d|\n", num1);
	ft_printf("My d:|%d|\n\n", num1);

	printf("   -d:|%d|\n", -num1);
	ft_printf("My -d:|%d|\n\n", -num1);

	printf("   2d:|%2d|\n", num1);
	ft_printf("My 2d:|%2d|\n\n", num1);

	printf("   10d:|%10d|\n", num1);
	ft_printf("My 10d:|%10d|\n\n", num1);

	printf("   10d:|%10.3d|\n", num1);
	ft_printf("My 10d:|%10.3d|\n\n", num1);

	printf("    -10d|%-10d|\n", num1);
	ft_printf(" My -10d|%-10d|\n\n", num1);

	// PERCENT
	printf("   %%:|%%|\n");
	ft_printf("My %%:|%%|\n\n");
	printf("   10%%:|%10%|\n");
	ft_printf("My 10%%:|%10%|\n\n");
	printf("   10.2%%:|%10.2%|\n");
	ft_printf("My 10.2%%:|%10.2%|\n\n");
	printf("   -10%%:|%-10%|\n");
	ft_printf("My -10%%:|%-10%|\n\n");

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

	// Unsigned INT ??
	int num = 65426355;
	printf("   u:|%u|\n", num);
	ft_printf("My u:|%u|\n\n", num);

	printf("   -u:|%u|\n", -num);
	ft_printf("My -u:|%u|\n\n", -num);

	printf("   2u:|%2u|\n", num);
	ft_printf("My 2u:|%2u|\n\n", num);

	printf("   10u:|%10u|\n", num);
	ft_printf("My 10u:|%10u|\n\n", num);

	printf("   10.5u:|%10.5u|\n", num);
	ft_printf("My 10.5u:|%10.5u|\n\n", num);

	printf("    -10u|%-10u|\n", num);
	ft_printf(" My -10u|%-10u|\n\n", num);

	printf("   5f:|%5f|\n", f);
	ft_printf("My 5f:|%5llf|\n\n", f);
*/
/*	long int num = 65426355;
	printf("   u:|%li|\n", num);
	ft_printf("My u:|%li|\n\n", num);

	printf("   -u:|%ld|\n", -num);
	ft_printf("My -u:|%ld|\n\n", -num);
*/
/*	// POINT 
	char d1[4]="abc";
	printf ("   p|%p|\n",d1);
	ft_printf("My p|%p|\n\n", d1);
*/
/*	char *str;
	
	str = 0;
	printf( "%x\n", 120);
	printf( "%s", ft_create_xi(str, 120, 0));
*/
/*	printf("%x\n", 42);
	ft_printf("%x", 42);*/
//	ft_printf("%lu\n", -42);
//	printf("%lu\n", -42);
//	ft_printf("%ju\n", 4999999999);
//	ft_printf("|%  +d|\n", 42);
	//printf("%  +d\n", 42);

/*	unsigned int a = -1;
	printf("%u\n", a);
	ft_printf("%u\n", a);*/
/*	printf("%lu\n", a);
	ft_printf("%lu\n", a);
	printf("%llu\n", a);
	ft_printf("%llu\n", a);
	printf("%hu\n", a);
	ft_printf("%hu\n", a);
	printf("%hhu\n", a);
	ft_printf("%hhu\n", a);*/
//	ft_printf("% ++d", 42);
//	printf("% ++d", 42);
//	printf("%d\n", 0);
//	ft_printf("%d\n", 0);
	//ft_printf("@moulitest: %.d %.0d", 0, 0);
	//printf("@moulitest: %.d %.0d", 0, 0);
//	ft_printf("|%2c|\n", 0);
//	printf("|%2c|", 0);
	printf("@moulitest: |%o|\n", 0);
	ft_printf("@moulitest: |%o|\n", 0);
}
