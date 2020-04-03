/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:21:51 by marrow            #+#    #+#             */
/*   Updated: 2019/09/10 03:15:17 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t s1len;

	s1len = ft_strlen(s1);
	if (ft_strlen(s2) < n)
		ft_strcpy(s1 + s1len, s2);
	else
	{
		ft_strncpy(s1 + s1len, s2, n);
		s1[s1len + n] = '\0';
	}
	return (s1);
}
