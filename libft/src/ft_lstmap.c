/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:02:05 by marrow            #+#    #+#             */
/*   Updated: 2019/11/10 02:39:20 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*current;

	if (!lst)
		return (NULL);
	new = f(lst);
	current = new;
	while (lst->next)
	{
		lst = lst->next;
		current->next = f(lst);
		if (!(current->next))
		{
			free(current->next);
			return (NULL);
		}
		current = current->next;
	}
	return (new);
}
