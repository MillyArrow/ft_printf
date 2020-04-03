/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:51:50 by marrow            #+#    #+#             */
/*   Updated: 2019/09/13 02:49:01 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	size_t len;
	size_t i;

	i = 0;
	len = 0;
	if (s)
		if ((len = ft_strlen(s)))
		{
			while ((ft_isblanki(s, i)))
				i++;
			while (ft_isblanki(s, len - 1) && (i < len))
				len--;
			return (ft_strsub(s, i, len - i));
		}
	return ((char *)s);
}
