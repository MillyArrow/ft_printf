/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:26:06 by marrow            #+#    #+#             */
/*   Updated: 2019/09/15 11:26:32 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	list->content = data;
	list->next = NULL;
	return (list);
}
