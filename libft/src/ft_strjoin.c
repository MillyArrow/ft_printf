/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 05:57:29 by marrow            #+#    #+#             */
/*   Updated: 2019/09/12 22:50:06 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *new;

	if (s1 && s2)
	{
		if ((new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			new = ft_strcpy(new, s1);
			new = ft_strcat(new, s2);
			return (new);
		}
	}
	return (NULL);
}
