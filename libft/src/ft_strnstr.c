/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:04:04 by marrow            #+#    #+#             */
/*   Updated: 2019/09/11 21:15:39 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*hay;
	size_t		need_length;

	hay = haystack;
	need_length = ft_strlen(needle);
	if (!need_length)
		return ((char *)hay);
	while (len && *hay)
	{
		if (len >= need_length)
			if (!ft_strncmp(hay, needle, need_length))
				return ((char *)hay);
		len--;
		hay++;
	}
	return (NULL);
}
