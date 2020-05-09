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
    int     j;
    
    (*i)++;
    j = 0;
	while (str[*i] != '}')
    {
		specifier->color[j] = str[*i];
		(*i)++;
        j++;
    }
	(*i)++;
    specifier->color[j] = '\0';
    if (!ft_strcmp(specifier->color, "black"))
    	ft_putstrs(black,specifier);
	if (!ft_strcmp(specifier->color, "red"))
		ft_putstrs(red, specifier);
	if (!ft_strcmp(specifier->color, "green"))
		ft_putstrs(green, specifier);
	if (!ft_strcmp(specifier->color, "yellow"))
		ft_putstrs(yellow, specifier);
	if (!ft_strcmp(specifier->color, "purple"))
		ft_putstrs(purple, specifier);
	if (!ft_strcmp(specifier->color, "cyan"))
		ft_putstrs(cyan, specifier);
	if (!ft_strcmp(specifier->color, "white"))
		ft_putstrs(white, specifier);
	if (!ft_strcmp(specifier->color, "blue"))
		ft_putstrs(blue, specifier);
	if (!ft_strcmp(specifier->color, "eoc"))
		ft_putstrs(eoc, specifier);
    return (0);
}