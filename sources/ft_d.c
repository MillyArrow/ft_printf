/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:40:44 by marrow            #+#    #+#             */
/*   Updated: 2020/02/29 21:37:53 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

__int64_t	get_number(t_spec *specifier, va_list args)
{
	__int64_t number;

	number = va_arg(args, __int64_t);
	if (ft_strcmp(specifier->length, "hh") == 0)
		number = (signed char)number;
	else if (ft_strcmp(specifier->length, "h") == 0)
		number = (short int)number;
	else if (ft_strcmp(specifier->length, "ll") == 0)
		number = (long long)number;
	else if (ft_strcmp(specifier->length, "l") == 0)
		number = (long)number;
	else
		number = (int)number;
	if (number < 0)
		specifier->minus = 1;
	number = (__int64_t)number;
	return (number);
}

void		ft_putnbrs(__int64_t n, int base, t_spec *spec)
{
	if (n > LLONG_MAX || n < LLONG_MIN)
		return ;
	if (n == LLONG_MIN)
	{
		ft_putstrs("9223372036854775808", spec);
		return ;
	}
	if (n < 0)
		n *= -1;
	if (n < base)
	{
		ft_putch(n + '0', spec);
		return ;
	}
	ft_putnbrs(n / base, base, spec);
	ft_putch((char)((n % base) + '0'), spec);
}

void		ft_accuracy(t_spec *specifier, int length)
{
	if (length > (int)specifier->accuracy)
	{
		if (specifier->minus == 1 && specifier->accuracy != -1 \
		&& specifier->flag[0] != '-')
			ft_putch('-', specifier);
		if (specifier->minus != 1 && specifier->flag[4] == '0' \
			&& specifier->flag[1] == '+' && specifier->accuracy != -1)
			ft_putch('+', specifier);
		return ;
	}
	length = (int)specifier->accuracy - length;
	if (specifier->minus == 1 && ++length && specifier->flag[0] != '-')
		ft_putch('-', specifier);
	if (specifier->minus != 1 && specifier->flag[4] == '0' \
			&& specifier->flag[1] == '+')
		ft_putch('+', specifier);
	if (specifier->flag[3] == '#' && specifier->iszero == 0 \
	&& specifier->type == 'o')
		length--;
	while (length-- > 0)
		ft_putch('0', specifier);
}

void		display_d(t_spec *specifier, __int64_t *number, int *length)
{
	if (specifier->flag[2] == ' ' && specifier->flag[1] != '+' && \
		specifier->minus != 1)
		ft_putch(' ', specifier);
	ft_width(specifier, *length);
	if (specifier->flag[1] == '+' && specifier->minus != 1 && \
	specifier->flag[4] != '0')
		ft_putch('+', specifier);
	ft_accuracy(specifier, *length);
	if (specifier->accuracy == 0 && *number == 0)
		return ;
	if (specifier->flag[0] != '-')
	{
		if (specifier->minus == 1 && specifier->accuracy == -1 \
			&& !(specifier->width))
			ft_putch('-', specifier);
		ft_putnbrs(*number, 10, specifier);
	}
}

void		ft_d(t_spec *specifier, va_list args)
{
	__int64_t	number;
	int			length;

	number = get_number(specifier, args);
	length = ft_number_length(number, 10);
	if (specifier->accuracy == 0 && number == 0)
		length = 0;
	if (specifier->flag[0] == '-')
	{
		if (specifier->flag[2] == ' ' && specifier->flag[1] != '+' && \
		specifier->minus != 1)
			ft_putch(' ', specifier);
		if (specifier->minus == 1)
			ft_putch('-', specifier);
		if (specifier->flag[1] == '+' && specifier->minus != 1 \
			&& specifier->flag[4] != '0')
			ft_putch('+', specifier);
		ft_accuracy(specifier, length);
		if (specifier->accuracy != 0)
			ft_putnbrs(number, 10, specifier);
		ft_width(specifier, length);
		return ;
	}
	display_d(specifier, &number, &length);
}
