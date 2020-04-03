/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 06:12:49 by marrow            #+#    #+#             */
/*   Updated: 2020/02/28 08:52:00 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrll(__int64_t n, int base)
{
	if (n > LLONG_MAX || n < LLONG_MIN)
		return ;
	if (n == LLONG_MIN)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (n < 0)
		n *= -1;
	if (n < base)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_putnbrll(n / base, base);
	ft_putchar((char)((n % base) + '0'));
}
