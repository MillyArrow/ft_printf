/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 07:48:59 by marrow            #+#    #+#             */
/*   Updated: 2019/09/09 23:17:45 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!src && !dst)
		return (NULL);
	while (n-- > 0 && (ft_copybyte(d, s)))
	{
		if (*s == (unsigned char)c)
		{
			ft_copybyte(d, s);
			return (++d);
			break ;
		}
		d++;
		s++;
	}
	return (NULL);
}
