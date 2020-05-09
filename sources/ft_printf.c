/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 23:29:48 by marrow            #+#    #+#             */
/*   Updated: 2020/05/09 17:16:10 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		initialization(t_spec *specifier)
{
	ft_bzero(specifier->flag, sizeof(char) * 5);
	specifier->width = 0;
	specifier->accuracy = 0;
	ft_bzero(specifier->length, 3);
	specifier->type = 0;
	specifier->minus = 0;
	specifier->iszero = 0;
	specifier->len = 0;
	specifier->len_f = 0;
	specifier->inf_nan = 0;
	specifier->plus = 0;
	ft_bzero(specifier->color, sizeof(char) * 8);
}

void		ft_putch(char c, t_spec *spec)
{
	write(1, &c, 1);
	spec->len += 1;
}

void		ft_putstrs(char const *s, t_spec *spec)
{
	if (s)
		while (*s)
			ft_putch(*s++, spec);
}

int			ft_dota(va_list parameters,\
const char *restrict format)
{
	char	*str;
	size_t	i;
	size_t	printed;
	t_spec	*specifier;

	str = (char*)format;
	printed = 0;
	specifier = NULL;
	i = 0;
	specifier = (t_spec*)ft_memalloc(sizeof(t_spec));
	while (str[i])
	{
		if (str[i] == '{')
			ft_setcolor(str, &i, specifier);
		if (str[i] != '%' && ++printed)
			ft_putchar(str[i++]);
		else
		{
			initialization(specifier);
			ft_format_specifier(str, &i, specifier);
			ft_type(specifier, parameters);
			printed += specifier->len;
		}
	}
	free(specifier);
	return (printed);
}

int			ft_printf(const char *restrict format, ...)
{
	int			printed;
	va_list		parameters;

	printed = 0;
	va_start(parameters, format);
	printed = ft_dota(parameters, format);
	va_end(parameters);
	return (printed);
}
