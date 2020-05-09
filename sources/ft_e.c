
#include "ft_printf.h"

void				ft_round_e(t_spec *specifier, long double number)
{
	__uint128_t		temp;
	__uint128_t		temp2;
	size_t			l_num;
	int				prec;
	char			check;

	check = 0;
	temp = number;
	number = number - temp;
	prec = specifier->accuracy + 1 - ft_l_num(temp);
	while (prec > 0)
	{
		number *= 10;
		temp = number;
		temp2 = number * 10;
		check += (temp == 0 && prec != 1 && (temp2 != 9)) ? 1 : 0;
		prec--;
	}
	l_num = ft_l_num(number / 10);
	number = (temp % 10 >= 5) ? number / 10 + 1 : number / 10;
	if ((l_num || !specifier->accuracy) && \
	l_num != (ft_l_num(number)) && !check)
		specifier->int_part++;
}

void		ft_e(t_spec *specifier, va_list args)
{
	long double number;
	size_t		l_int_part;

	number = 0;
	if (specifier->length[0] == 'l' || specifier->length[0] == '\0')
		number = (double)va_arg(args, double);
	else if (specifier->length[0] == 'L')
		number = (long double)va_arg(args, long double);
	if (inf_nan(&number, specifier))
		return ;
	if (specifier->accuracy == -1)
		specifier->accuracy = 6;
	if (number < 0 && (number *= -1))
		specifier->minus = 1;
	specifier->int_part = number;
	ft_round_e(specifier, number);
	l_int_part = ft_l_num(specifier->int_part);
	specifier->len_f = l_int_part + specifier->accuracy;
	if (specifier->accuracy != 0 || specifier->flag[3] == '#')
		specifier->len_f++;
	if (display_minus_f(specifier, number, l_int_part))
		return ;
	display_f(specifier, number, l_int_part);
}
