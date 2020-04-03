/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:33:26 by marrow            #+#    #+#             */
/*   Updated: 2020/02/28 08:38:45 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_width_pct(t_spec *specifier, int length)
{
	if (specifier->width <= 0)
		return ;
	length = (int)specifier->width - length;
	while (length-- > 0)
	{
		if (specifier->flag[4] == '0' && specifier->flag[0] != '-')
			ft_putch('0', specifier);
		else
			ft_putch(' ', specifier);
	}
}

void		ft_pct(t_spec *specifier)
{
	int length;

	length = 1;
	if (specifier->flag[0] == '-')
	{
		if (specifier->accuracy != 0)
			ft_putch('%', specifier);
		ft_width_pct(specifier, length);
		return ;
	}
	ft_width_pct(specifier, length);
	if (specifier->flag[0] != '-')
		ft_putch('%', specifier);
}
