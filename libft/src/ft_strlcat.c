/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 23:43:26 by marrow            #+#    #+#             */
/*   Updated: 2019/09/10 06:08:34 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dstlen;
	size_t srclen;
	size_t buffer;

	srclen = ft_strlen(src);
	dstlen = ft_strnlen(dst, size);
	buffer = size - dstlen;
	if (dstlen == size)
		return (dstlen + srclen);
	if (srclen < buffer)
		ft_memcpy(dst + dstlen, src, (srclen + 1));
	if (srclen >= buffer)
	{
		ft_memcpy(dst + dstlen, src, buffer - 1);
		dst[dstlen + buffer - 1] = '\0';
	}
	return (dstlen + srclen);
}
