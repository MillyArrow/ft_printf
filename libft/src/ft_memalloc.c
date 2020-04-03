/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 00:05:49 by marrow            #+#    #+#             */
/*   Updated: 2019/09/12 00:17:56 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *memory;

	if (!(memory = (unsigned char *)malloc(size)))
		return (NULL);
	else
		ft_bzero(memory, size);
	return (memory);
}
