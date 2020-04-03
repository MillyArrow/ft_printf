/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:16:07 by marrow            #+#    #+#             */
/*   Updated: 2020/02/28 09:00:00 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		display_base_big(unsigned long long value, int base, t_spec *spec)
{
	char	buff[1000];
	int		i;

	i = 0;
	if (value == 0)
		buff[i++] = '0';
	while (value)
	{
		buff[i++] = "0123456789ABCDEF"[value % base];
		value = value / base;
	}
	buff[i] = '\0';
	while (i > 0)
	{
		i--;
		ft_putch(buff[i], spec);
	}
}

int			check_for_big_x(unsigned long long number, \
int length, t_spec *specifier)
{
	if (number == 0)
		specifier->iszero = 1;
	if (specifier->flag[3] == '#' && (number != 0) && \
	(length < specifier->accuracy && specifier->accuracy != -1))
		specifier->width -= 2;
	if (specifier->flag[0] == '-')
	{
		if (specifier->flag[3] == '#' && number != 0)
			ft_putstrs("0X", specifier);
		ft_accuracy(specifier, length);
		if (specifier->accuracy != 0)
			display_base_big(number, 16, specifier);
		ft_width(specifier, length);
		return (0);
	}
	return (1);
}

void		ft_big_x(t_spec *specifier, va_list args)
{
	unsigned long long	number;
	int					length;

	number = get_number_u(specifier, args);
	length = ft_number_length_u(number, 16);
	if (specifier->accuracy == 0)
		length = 0;
	if (!check_for_big_x(number, length, specifier))
		return ;
	if (specifier->flag[3] == '#' && number != 0 && \
	(specifier->flag[4] == '0' && specifier->accuracy == -1))
		ft_putstrs("0X", specifier);
	ft_width(specifier, length);
	if (specifier->flag[3] == '#' && number != 0 && \
	!(specifier->flag[4] == '0' && specifier->accuracy == -1))
		ft_putstrs("0X", specifier);
	ft_accuracy(specifier, length);
	if (specifier->accuracy == 0)
		return ;
	if (specifier->flag[0] != '-')
		display_base_big(number, 16, specifier);
}
