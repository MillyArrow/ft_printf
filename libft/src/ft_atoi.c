/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:10:53 by marrow            #+#    #+#             */
/*   Updated: 2019/09/15 11:07:14 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *c)
{
	long long	number;
	long long	prev;
	signed char	sign;

	sign = 1;
	number = 0;
	while (*c == 32 || (*c >= 9 && *c <= 13))
		c++;
	if (*c == '-')
	{
		sign = -1;
		c++;
	}
	else if (*c == '+')
		c++;
	while (*c >= '0' && *c <= '9')
	{
		prev = number;
		number = number * 10 + *c - '0';
		c++;
		if (number / 10 != prev)
			return (sign > 0 ? -1 : 0);
	}
	return ((int)(number * sign));
}
