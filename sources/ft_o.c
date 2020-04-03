/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 08:17:43 by marrow            #+#    #+#             */
/*   Updated: 2020/02/28 14:31:25 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	get_number_u(t_spec *specifier, va_list args)
{
	unsigned long long number;

	if (ft_strcmp(specifier->length, "hh") == 0)
		number = (unsigned char)va_arg(args, unsigned int);
	else if (ft_strcmp(specifier->length, "h") == 0)
		number = (unsigned short int)va_arg(args, unsigned int);
	else if (ft_strcmp(specifier->length, "ll") == 0)
		number = (unsigned long long)va_arg(args, unsigned long long);
	else if (ft_strcmp(specifier->length, "l") == 0)
		number = (unsigned long)va_arg(args, unsigned long);
	else
		number = (unsigned int)va_arg(args, unsigned int);
	number = (unsigned long long)number;
	return (number);
}

void				display_base(unsigned long long value, \
int base, t_spec *spec)
{
	char	buff[1000];
	int		i;

	i = 0;
	if (value == 0)
		buff[i++] = '0';
	while (value)
	{
		buff[i++] = "0123456789abcdef"[value % base];
		value = value / base;
	}
	buff[i] = '\0';
	while (i > 0)
	{
		i--;
		ft_putch(buff[i], spec);
	}
}

int					ft_number_length_u(unsigned long long number, int base)
{
	int length;

	length = 1;
	while ((number /= base) > 0)
		length++;
	return (length);
}

int					check_for_o(unsigned long long number, \
int length, t_spec *specifier)
{
	if (number == 0)
		specifier->iszero = 1;
	if (specifier->flag[3] == '#' && (number != 0) && specifier->accuracy == 0)
	{
		specifier->width--;
		specifier->accuracy--;
	}
	if (specifier->flag[0] == '-')
	{
		if (specifier->flag[3] == '#' && \
		((number != 0) || specifier->accuracy == 0))
			ft_putch('0', specifier);
		ft_accuracy(specifier, length);
		if (specifier->accuracy != 0)
			display_base(number, 8, specifier);
		ft_width(specifier, length);
		return (0);
	}
	return (1);
}

void				ft_o(t_spec *specifier, va_list args)
{
	unsigned long long	number;
	int					length;

	number = get_number_u(specifier, args);
	length = ft_number_length_u(number, 8);
	if (specifier->accuracy == 0 && specifier->flag[3] != '#')
		length = 0;
	if (!check_for_o(number, length, specifier))
		return ;
	ft_width(specifier, length);
	if (specifier->flag[3] == '#' && \
	((number != 0) || specifier->accuracy == 0))
		ft_putch('0', specifier);
	ft_accuracy(specifier, length);
	if (specifier->accuracy == 0)
		return ;
	if (specifier->flag[0] != '-')
		display_base(number, 8, specifier);
}
