/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 05:42:33 by marrow            #+#    #+#             */
/*   Updated: 2019/09/14 07:55:13 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length(int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

static int		is_neg(int n, size_t *len, signed char *flag)
{
	if (n < 0)
	{
		n *= -1;
		*len += 1;
		*flag = 1;
	}
	return (n);
}

char			*ft_itoa(int n)
{
	size_t		len;
	size_t		i;
	char		*string;
	signed char	flag;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	len = length(n);
	flag = 0;
	n = is_neg(n, &len, &flag);
	if ((string = ft_strnew(len)))
	{
		string[--len] = n % 10 + '0';
		while (n /= 10)
			string[--len] = n % 10 + '0';
		if (flag)
			string[0] = '-';
		return (string);
	}
	return (NULL);
}
