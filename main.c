#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	printf("start %10.6s\n", "flexyiyiyiyi");
	ft_printf("start %10.6s", "flexyiyiyiyi");
	return (0);
}
