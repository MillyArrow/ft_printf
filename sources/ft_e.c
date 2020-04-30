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
	ft_round(specifier, number);
	l_int_part = ft_l_num(specifier->int_part);
	specifier->len_f = l_int_part + specifier->accuracy;
	if (specifier->accuracy != 0 || specifier->flag[3] == '#')
		specifier->len_f++;
	if (display_minus_f(specifier, number, l_int_part))
		return ;
	display_f(specifier, number, l_int_part);
}
