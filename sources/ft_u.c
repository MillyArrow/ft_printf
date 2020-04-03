/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:13:40 by marrow            #+#    #+#             */
/*   Updated: 2020/02/28 14:48:17 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		display_u(t_spec *specifier, \
unsigned long long *number, int *length)
{
	ft_width(specifier, *length);
	ft_accuracy(specifier, *length);
	if (specifier->accuracy == 0)
		return ;
	if (specifier->flag[0] != '-')
		ft_putnbrs_u(*number, 10, specifier);
}

void		ft_putnbrs_u(unsigned long long n, \
unsigned long long base, t_spec *spec)
{
	if (n < base)
	{
		ft_putch(n + '0', spec);
		return ;
	}
	ft_putnbrs_u(n / base, base, spec);
	ft_putch((char)((n % base) + '0'), spec);
}

void		ft_u(t_spec *specifier, va_list args)
{
	unsigned long long	number;
	int					length;

	number = get_number_u(specifier, args);
	length = ft_number_length_u(number, 10);
	if (specifier->accuracy == 0)
		length = 0;
	if (specifier->flag[0] == '-')
	{
		ft_accuracy(specifier, length);
		if (specifier->accuracy != 0)
			ft_putnbrs_u(number, 10, specifier);
		ft_width(specifier, length);
		return ;
	}
	display_u(specifier, &number, &length);
}
