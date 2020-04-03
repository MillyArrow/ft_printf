/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copybyte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 08:13:30 by marrow            #+#    #+#             */
/*   Updated: 2019/09/07 18:24:26 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_copybyte(void *dst, const void *src)
{
	char		*destination;
	const char	*source;

	destination = dst;
	source = src;
	if (!destination && !source)
		return (NULL);
	*destination = *source;
	return (dst);
}
