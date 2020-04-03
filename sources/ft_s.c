/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:27:11 by marrow            #+#    #+#             */
/*   Updated: 2020/03/01 00:40:56 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_str(t_spec *specifier, size_t *i, size_t *len, char **length)
{
	if (specifier->width > *len)
	{
		if (specifier->flag[0] == '-')
		{
			ft_putstrs(*length, specifier);
			while ((*i)++ < (specifier->width - *len))
				ft_putch(' ', specifier);
			return (0);
		}
		else
		{
			while ((*i)++ < (specifier->width - *len))
				ft_putch(' ', specifier);
			ft_putstrs(*length, specifier);
			return (0);
		}
	}
	return (1);
}

void		ft_s(t_spec *specifier, va_list args)
{
	char	*length;
	size_t	len;
	size_t	i;

	i = 0;
	length = (char *)va_arg(args, char*);
	if (length == NULL)
		length = "(null)";
	len = ft_strlen(length);
	if (specifier->accuracy != -1 && (size_t)specifier->accuracy < len)
	{
		len = specifier->accuracy;
		length = ft_strsub(length, 0, len);
	}
	if (!print_str(specifier, &i, &len, &length))
		return ;
	ft_putstrs(length, specifier);
}
