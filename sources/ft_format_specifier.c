/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:13:23 by marrow            #+#    #+#             */
/*   Updated: 2020/02/29 21:17:18 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec			*ft_format_specifier(char *str, size_t *i, t_spec *specifier)
{
	(*i)++;
	if (str[*i])
	{
		ft_set_flag(str, i, specifier);
		ft_set_width(str, i, specifier);
		ft_set_accuracy(str, i, specifier);
		ft_set_length(str, i, specifier);
		if (ft_strchr("%diouxXcspfFe", str[*i]))
		{
			specifier->type = str[*i];
			(*i)++;
		}
	}
	return (specifier);
}

void			ft_set_flag(char *str, size_t *i, t_spec *specifier)
{
	if (str[*i] == ' ' && (*i)++)
	{
		specifier->flag[2] = ' ';
		ft_set_flag(str, i, specifier);
	}
	if (str[*i] == '+' && (*i)++)
	{
		specifier->flag[1] = '+';
		ft_set_flag(str, i, specifier);
	}
	if (str[*i] == '0' && (*i)++)
	{
		specifier->flag[4] = '0';
		ft_set_flag(str, i, specifier);
	}
	if (str[*i] == '-' && (*i)++)
	{
		specifier->flag[0] = '-';
		ft_set_flag(str, i, specifier);
	}
	if (str[*i] == '#' && (*i)++)
	{
		specifier->flag[3] = '#';
		ft_set_flag(str, i, specifier);
	}
}

void			ft_set_width(char *str, size_t *i, t_spec *specifier)
{
	size_t width;

	width = 0;
	if (str[*i] == '*')
	{
		specifier->width = '*';
		return ;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		width = width * 10 + str[*i] - '0';
		(*i)++;
	}
	specifier->width = width;
}

void			ft_set_accuracy(char *str, size_t *i, t_spec *specifier)
{
	int accuracy;

	accuracy = 0;
	if (str[*i] == '.' && (*i)++)
	{
		if (str[*i] == '*')
		{
			specifier->accuracy = '*';
			return ;
		}
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			accuracy = accuracy * 10 + str[*i] - '0';
			(*i)++;
		}
		if (accuracy != 0)
		{
			specifier->accuracy = accuracy;
			return ;
		}
		specifier->accuracy = 0;
	}
	else
		specifier->accuracy = -1;
}

void			ft_set_length(char *str, size_t *i, t_spec *specifier)
{
	if (str[*i] == 'h' && str[*i + 1] != 'h' && (*i)++)
		specifier->length[0] = 'h';
	if (str[*i] == 'h' && str[*i + 1] == 'h')
	{
		*i += 2;
		specifier->length[0] = 'h';
		specifier->length[1] = 'h';
	}
	if (str[*i] == 'l' && str[*i + 1] != 'l' && (*i)++)
		specifier->length[0] = 'l';
	if (str[*i] == 'l' && str[*i + 1] == 'l')
	{
		*i += 2;
		specifier->length[0] = 'l';
		specifier->length[1] = 'l';
	}
	if (str[*i] == 'L' && str[*i + 1] != 'L' && (*i)++)
		specifier->length[0] = 'L';
}
