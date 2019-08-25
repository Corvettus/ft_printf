#include "ft_printf.h"

char    *ft_print_p(var *s)
{
	char*   str;
	
	return (str);
}
/*
void	ft_supoctalsminus(t_spec *s, t_ran *ran)
{
	if (s->minus == 0 && s->precision == 0)
	{
		while (s->width-- - 3 > 0)
			ran->buf[ran->j++] = ' ';
		ran->buf[ran->j++] = '0';
		ran->buf[ran->j++] = 'x';
		ran->buf[ran->j++] = '0';
	}
	else if (s->precision == -1)
	{
		while (s->width-- - 2 > 0)
			ran->buf[ran->j++] = ' ';
		ran->buf[ran->j++] = '0';
		ran->buf[ran->j++] = 'x';
	}
	else
	{
		ran->buf[ran->j++] = '0';
		ran->buf[ran->j++] = 'x';
		ran->buf[ran->j++] = '0';
		while (s->precision-- > 1)
			ran->buf[ran->j++] = '0';
		while (s->width-- - 3 > 0)
			ran->buf[ran->j++] = ' ';
	}
}

void	ft_supzerox(t_spec *s, t_ran *ran)
{
	ran->buf[ran->j++] = '0';
	ran->buf[ran->j++] = 'x';
	if (s->precision > s->width)
		while (s->precision-- > ft_strlen(s->buf))
			ran->buf[ran->j++] = '0';
	ft_strjcpy(ran->buf, s, &ran->j);
}

void	ft_adrxuli(t_spec *s, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned long remainder;

	s->i = s->j;
	while (num != 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			s->buf[s->j++] = 48 + remainder;
		else
			s->buf[s->j++] = 55 + sm + remainder;
		num = num / 16;
	}
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ran->strlen = ft_strlen(s->buf) + 2;
}

void	ft_supadr1(t_spec *s, t_ran *ran, unsigned long long int num)
{
	ft_adrxuli(s, ran, num, 32);
	if (s->minus == 0)
	{
		if (s->width < ran->strlen)
			ft_supzerox(s, ran);
		else
		{
			while (s->width-- > ran->strlen)
				ran->buf[ran->j++] = ' ';
			ft_supzerox(s, ran);
		}
	}
	else
	{
		ft_supzerox(s, ran);
		while (s->width-- > ran->strlen)
			ran->buf[ran->j++] = ' ';
	}
}

void	ft_adr_record(t_ran *ran, va_list *vl, t_spec *s)
{
	unsigned long num;

	num = va_arg(*vl, unsigned long);
	if (num == 0)
		ft_supoctalsminus(s, ran);
	else
		ft_supadr1(s, ran, num);
}
*/