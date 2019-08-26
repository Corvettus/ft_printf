#include "ft_printf.h"

char			*ft_controller(var *tmp)
{
	char *res;

	if (tmp->type == '%')
		res = ft_print_pc(tmp);
	else if (tmp->type == 'c')
		res = ft_print_c(tmp);
	else if (tmp->type == 's')
		res = ft_print_s(tmp);
	else if (tmp->type == 'p')
		res = ft_print_p(tmp);
	else if (tmp->type == 'd' || tmp->type == 'i')
		res = ft_print_d(tmp);
	else if (tmp->type == 'o')
		res = ft_print_o(tmp);
	else if (tmp->type == 'u' || tmp->type == 'U')
		res = ft_print_u(tmp);
	else if (tmp->type == 'x' || tmp->type == 'X')
		res = ft_print_X(tmp);
	if (tmp->type == 'f')
		res = ft_print_f(tmp);
	return (res);
}