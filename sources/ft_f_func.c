/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:06:09 by marrow            #+#    #+#             */
/*   Updated: 2020/03/07 21:06:11 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				ft_l_num(long double number)
{
	int i;

	i = 0;
	while (number >= 1)
	{
		number /= 10;
		i++;
	}
	return (i);
}

void				div_digit(t_spec *specifier, long double *number,\
__uint128_t *t_number, char *check)
{
	size_t	l_num;

	l_num = ft_l_num(*number / 10);
	if (*t_number % 10 >= 5)
	{
		*number = *number / 10 + 1;
		if (l_num && l_num != (ft_l_num(*number)) && !*check)
		{
			(*number)--;
			*t_number /= 10;
			while ((*t_number % 10) == 9)
			{
				ft_putch('0', specifier);
				specifier->accuracy--;
				*t_number /= 10;
			}
		}
	}
}

int					inf_nan(long double *number, t_spec *specifier)
{
	if (*number == 1.0 / 0.0 && ++specifier->inf_nan)
	{
		specifier->len_f = 3;
		ft_width_f(specifier);
		ft_putstr("inf");
		return (1);
	}
	else if (*number == -1.0 / 0.0 && ++specifier->inf_nan)
	{
		specifier->len_f = 4;
		ft_width_f(specifier);
		ft_putstr("-inf");
		return (1);
	}
	else if ((*number) != (*number) && ++specifier->inf_nan)
	{
		specifier->len_f = 3;
		ft_width_f(specifier);
		ft_putstr("nan");
		return (1);
	}
	else
		return (0);
}

long	double		ft_real_part(t_spec *specifier, long double number)
{
	__uint128_t		t_number;
	__uint128_t		t2_number;
	size_t			prec;
	char			check;

	t_number = 0;
	check = 0;
	prec = specifier->accuracy + 1;
	number = (double)number;
	while (prec)
	{
		number *= 10;
		t_number = number;
		t2_number = number * 10;
		if (t_number == 0 && prec != 1 && (t2_number != 9) && ++check)
		{
			ft_putch('0', specifier);
			specifier->accuracy--;
		}
		prec--;
	}
	div_digit(specifier, &number, &t_number, &check);
	return (number);
}

void				ft_round(t_spec *specifier, long double number)
{
	__uint128_t		temp;
	__uint128_t		temp2;
	size_t			prec;
	size_t			l_num;
	char			check;

	check = 0;
	temp = number;
	number = number - temp;
	prec = specifier->accuracy + 1;
	while (prec)
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
