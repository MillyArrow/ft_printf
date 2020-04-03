/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 06:31:22 by marrow            #+#    #+#             */
/*   Updated: 2019/09/10 10:46:58 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;
	char		*str;

	len = ft_strlen(s);
	str = (char *)s + len - 1;
	if (c == 0)
		return ((char *)s + len);
	while (len--)
	{
		if (*str == c)
			return ((char *)str);
		str--;
	}
	return (NULL);
}
