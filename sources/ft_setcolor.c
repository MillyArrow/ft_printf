/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 13:31:34 by mac               #+#    #+#             */
/*   Updated: 2020/05/09 17:10:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_setcolor(char *str, size_t *i, t_spec *specifier)
{
    //char    color[8];
    int     j;
    int     k;
    
    (*i)++;
    j = 0;
	while (str[*i] != '}')
    {
        (str[*i]) = specifier->color[j];
        i++;
        j++;
    }
    specifier->color[j] = '\0';
    k = ft_strcmp(specifier->color, "blue");
     //   ft_putstr("\e[00;34m");
    //return (0);
    ft_putnbr(k);
    return (0);
}