/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:05:02 by marrow            #+#    #+#             */
/*   Updated: 2019/09/10 12:07:34 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *str1;
	const unsigned char *str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (n-- > 0)
	{
		if (*str1 == '\0' && *str2 == '\0')
			break ;
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
