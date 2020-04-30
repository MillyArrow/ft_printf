/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:03:10 by marrow            #+#    #+#             */
/*   Updated: 2020/03/03 21:03:13 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_f_precision(t_spec *specifier, long double number)
{
	__int128_t		int_number;
	int				start;

	int_number = number;
	start = 0;
	number = ft_real_part(specifier, number - int_number);
	while (number >= 1)
		number /= 10;
	while (specifier->accuracy != -1 && specifier->accuracy--)
	{
		number *= 10;
		if (start != 0)
			number = number - int_number * 10;
		int_number = number;
		ft_putch(int_number + '0', specifier);
		start++;
	}
}

void		ft_putnbr_f(t_spec *specifier, long double number, size_t int_part)
{
	__int128_t	temp;
	long double	t_number;
	char		start;

	temp = 0;
	start = 0;
	int_part = 0;
	t_number = number;
	if (!(temp = t_number) && !specifier->int_part)
	{
	    specifier->width--;
	    ft_putch('0', specifier);
	}
	if (specifier->int_part)
		ft_putnbrs_u(specifier->int_part, 10, specifier);
	if (specifier->accuracy != 0 || specifier->flag[3] == '#')
		ft_putch('.', specifier);
}

void		display_f(t_spec *specifier, long double number, size_t int_part)
{
	if (specifier->flag[2] == ' ' && specifier->flag[1] != '+' && \
		specifier->minus != 1 && ++specifier->len_f)
		ft_putch(' ', specifier);
	if (specifier->minus == 1)
		specifier->len_f++;
	ft_width_f(specifier);
	if (specifier->flag[1] == '+' && specifier->minus != 1 && \
	specifier->flag[4] != '0')
		ft_putch('+', specifier);
	if (specifier->accuracy == 0 && number == 0)
		return ;
	if (specifier->flag[0] != '-')
	{
		if (specifier->minus == 1 && specifier->width == 0)
			ft_putch('-', specifier);
		ft_putnbr_f(specifier, number, int_part);
		ft_f_precision(specifier, number);
	}
}

int			display_minus_f(t_spec *specifier, long double number,\
size_t int_part)
{
	if (specifier->flag[0] == '-')
	{
		if (specifier->flag[2] == ' ' && specifier->flag[1] != '+' && \
		specifier->minus != 1 && ++specifier->len_f)
			ft_putch(' ', specifier);
		if (specifier->minus == 1 && ++specifier->len_f)
			ft_putch('-', specifier);
		if (specifier->flag[1] == '+' && specifier->minus != 1 \
			&& specifier->plus++ == 0 && ++specifier->len_f)
			ft_putch('+', specifier);
		ft_putnbr_f(specifier, number, int_part);
		ft_f_precision(specifier, number);
		ft_width_f(specifier);
		return (1);
	}
	return (0);
}

void		ft_f(t_spec *specifier, va_list args)
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
	ft_round(specifier, number);
    l_int_part = ft_l_num(specifier->int_part);
    specifier->len_f = l_int_part + specifier->accuracy;
    if (specifier->accuracy != 0 || specifier->flag[3] == '#')
        specifier->len_f++;
	if (display_minus_f(specifier, number, l_int_part))
		return ;
	display_f(specifier, number, l_int_part);
}
