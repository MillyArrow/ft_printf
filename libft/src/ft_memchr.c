/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:28:52 by marrow            #+#    #+#             */
/*   Updated: 2019/09/15 01:26:33 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;

	if (!n)
		return (NULL);
	str = (unsigned char *)s;
	while (--n && *str != (unsigned char)c)
		str++;
	if (*str == (unsigned char)c)
		return (str);
	return (NULL);
}
