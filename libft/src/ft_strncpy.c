/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:34:13 by marrow            #+#    #+#             */
/*   Updated: 2019/09/09 23:42:30 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t size;

	size = ft_strnlen(src, len);
	if (size < len)
		ft_memset(dst + size, '\0', len - size);
	return (ft_memcpy(dst, src, size));
}
