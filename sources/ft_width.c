/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 03:23:31 by marrow            #+#    #+#             */
/*   Updated: 2020/02/29 20:27:32 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_len_width(t_spec *specifier, int *length, int *tmp)
{
	if ((*length) <= (int)specifier->accuracy \
	&& specifier->accuracy != -1 && ++(*tmp))
		*length = (int)((int)specifier->width - specifier->accuracy);
	else
		*length = (int)(specifier->width - *length);
	if ((specifier->flag[1] == '+' && specifier->minus != 1) || \
		((*tmp) && specifier->minus == 1) || (specifier->flag[2] == ' ' && \
		specifier->flag[1] != '+' && specifier->minus != 1))
		(*length)--;
	if (specifier->minus == 1 && specifier->flag[4] == '0' \
		&& specifier->accuracy == -1 && specifier->flag[0] != '-')
		ft_putch('-', specifier);
	if (specifier->type == 'o' && specifier->flag[3] == '#' \
	&& specifier->iszero == 0 && !(*tmp))
		(*length)--;
	if ((specifier->type == 'x' || specifier->type == 'X') \
	&& specifier->flag[3] == '#' && specifier->iszero == 0 && !(*tmp))
		(*length) -= 2;
	if (specifier->type == 'p')
		(*length) -= 2;
}

void		print_width(t_spec *specifier, int *length, int *check)
{
	while ((*length)-- > 0)
	{
		if (specifier->flag[4] == '0' && specifier->accuracy == -1 \
		&& specifier->flag[0] != '-')
		{
			if (specifier->minus != 1 && specifier->flag[4] == '0' \
				&& specifier->flag[1] == '+' && (*check)++ == 1)
				ft_putch('+', specifier);
			ft_putch('0', specifier);
		}
		else
			ft_putch(' ', specifier);
	}
}

void		print_width_f(t_spec *specifier)
{
	while (specifier->len_f < specifier->width)
	{
		if (specifier->flag[4] == '0' && specifier->flag[0] != '-' \
		&& specifier->inf_nan == 0)
		{
			if (specifier->minus != 1 && specifier->flag[4] == '0' \
				&& specifier->flag[1] == '+' && specifier->plus++ == 0 \
				&& ++specifier->len_f)
				ft_putch('+', specifier);
			ft_putch('0', specifier);
		}
		else
			ft_putch(' ', specifier);
		specifier->width--;
	}
}

void		ft_width_f(t_spec *specifier)
{
	if (specifier->flag[1] == '+' && specifier->minus != 1 && \
	specifier->flag[4] != '0' && specifier->plus++ == 0)
		specifier->len_f++;
	if (specifier->minus == 1 && specifier->flag[4] == '0' \
		&& specifier->flag[0] != '-')
		ft_putch('-', specifier);
	if (specifier->len_f >= specifier->width && specifier->minus != 1 \
	&& specifier->flag[4] == '0' && specifier->flag[1] == '+' && \
	specifier->plus++ == 0 && ++specifier->len_f)
		ft_putch('+', specifier);
	print_width_f(specifier);
	if (specifier->minus == 1 && specifier->flag[4] != '0' && \
	specifier->flag[0] != '-' && specifier->width != 0)
		ft_putch('-', specifier);
}

void		ft_width(t_spec *specifier, int length)
{
	int tmp;
	int check;

	tmp = 0;
	check = 1;
	if (specifier->width <= 0)
		return ;
	ft_len_width(specifier, &length, &tmp);
	if (specifier->flag[1] == '+' && specifier->minus != 1 \
	&& length <= 0 && specifier->accuracy == -1)
		ft_putch('+', specifier);
	print_width(specifier, &length, &check);
	if (specifier->minus == 1 && specifier->flag[4] != '0' && \
	specifier->flag[0] != '-' && specifier->accuracy == -1)
		ft_putch('-', specifier);
}
