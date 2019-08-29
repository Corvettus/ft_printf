#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int i = 1234324;
//	char s[4];
//	printf("start %10.6s\n", "flexyiyiyiyi");
//	ft_printf("start %10.6s", "flexyiyiyiyi");
//	printf("start %d\n", i);
	ft_printf("start %o\n", i);
	printf("start %o\n", i);
	return (0);
}
