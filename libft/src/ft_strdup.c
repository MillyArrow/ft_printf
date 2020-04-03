/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:27:56 by marrow            #+#    #+#             */
/*   Updated: 2019/11/13 19:07:16 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*c;

	i = ft_strlen(s1);
	if (!(c = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	c[i] = '\0';
	while (i >= 0)
	{
		c[i] = s1[i];
		i--;
	}
	return (c);
}
