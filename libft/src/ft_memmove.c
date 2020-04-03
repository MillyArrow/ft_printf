/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:47:51 by marrow            #+#    #+#             */
/*   Updated: 2019/09/07 18:25:41 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (d >= s && d)
	{
		d += (len - 1);
		s += (len - 1);
		while (len--)
			ft_copybyte(d--, s--);
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
