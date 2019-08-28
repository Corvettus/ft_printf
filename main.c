#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	//printf("test %10.2s # %c\n", "flex12", 'A');
	ft_printf("test %+10.*s # %c", "flex12", "A");
	return (0);
}
