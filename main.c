#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	printf("start %10s\n", "flex");
	ft_printf("start %10s", "flex");
	return (0);
}
