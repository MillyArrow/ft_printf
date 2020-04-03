/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 03:53:06 by marrow            #+#    #+#             */
/*   Updated: 2019/09/12 03:53:56 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*a;
	size_t	len;
	size_t	i;

	a = 0;
	if (s)
	{
		len = ft_strlen(s);
		a = ft_memalloc(len + 1);
		i = 0;
		if (len && a)
		{
			while (i < len)
			{
				a[i] = f(i, s[i]);
				i++;
			}
		}
	}
	return (a);
}
