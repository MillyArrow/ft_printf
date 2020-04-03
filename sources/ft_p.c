/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:51:39 by marrow            #+#    #+#             */
/*   Updated: 2020/02/27 21:55:52 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					check_for_p(unsigned long long number, \
int length, t_spec *specifier)
{
	if (number == 0)
		specifier->iszero = 1;
	if ((number != 0) && \
	(length < specifier->accuracy && specifier->accuracy != -1))
		specifier->width -= 2;
	if (specifier->flag[0] == '-')
	{
		ft_putstrs("0x", specifier);
		ft_accuracy(specifier, length);
		if (specifier->accuracy != 0)
			display_base(number, 16, specifier);
		ft_width(specifier, length);
		return (0);
	}
	return (1);
}

void				ft_p(t_spec *specifier, va_list args)
{
	unsigned long long	number;
	int					length;

	number = (unsigned long long)va_arg(args, void *);
	length = ft_number_length_u(number, 16);
	if (specifier->accuracy == 0)
		length = 0;
	if (!check_for_p(number, length, specifier))
		return ;
	if (specifier->flag[4] == '0' && specifier->accuracy == -1)
		ft_putstrs("0x", specifier);
	ft_width(specifier, length);
	if (!(specifier->flag[4] == '0' && specifier->accuracy == -1))
		ft_putstrs("0x", specifier);
	ft_accuracy(specifier, length);
	if (specifier->accuracy == 0)
		return ;
	if (specifier->flag[0] != '-')
		display_base(number, 16, specifier);
}
