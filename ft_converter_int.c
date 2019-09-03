#include "ft_printf.h"

char	ft_ulli_to_size(unsigned long long int num, char size1, char size2)
{
	if (size1 == 'l')
	{
		if (size2 == 'l')
			num = (int long long)num;
		else
			num = (int long)num;
	}
	else if(size1 == 'h')
	{
		if (size2 == 'h')
			num = (unsigned int)num;
		else
			num = (short int)num;
	}
}