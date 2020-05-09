/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:43:59 by marrow            #+#    #+#             */
/*   Updated: 2020/02/29 18:18:15 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_type(t_spec *specifier, va_list args)
{
	if (specifier->type == 'd' || specifier->type == 'i')
		ft_d(specifier, args);
	else if (specifier->type == 'c')
		ft_c(specifier, args);
	else if (specifier->type == 's')
		ft_s(specifier, args);
	else if (specifier->type == 'p')
		ft_p(specifier, args);
	else if (specifier->type == 'o')
		ft_o(specifier, args);
	else if (specifier->type == 'u')
		ft_u(specifier, args);
	else if (specifier->type == 'x')
		ft_x(specifier, args);
	else if (specifier->type == 'X')
		ft_big_x(specifier, args);
	else if (specifier->type == '%')
		ft_pct(specifier);
	else if (specifier->type == 'f')
		ft_f(specifier, args);
	else if (specifier->type == 'e')
		ft_e(specifier, args);
}
