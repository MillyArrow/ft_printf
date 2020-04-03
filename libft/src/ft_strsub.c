/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 05:38:50 by marrow            #+#    #+#             */
/*   Updated: 2019/09/12 05:51:57 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;

	new = ft_strnew(len);
	if (s && new)
	{
		ft_strncpy(new, s + start, len);
		return (new);
	}
	return (NULL);
}
