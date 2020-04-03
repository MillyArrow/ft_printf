/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:02:33 by marrow            #+#    #+#             */
/*   Updated: 2019/09/15 03:16:12 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	word_end(char const *s, size_t i, char c)
{
	while (s[i] && s[i] != c)
		++i;
	return (i);
}

static	size_t	word_start(char const *s, size_t i, char c)
{
	while (s[i] && s[i] == c)
		++i;
	return (i);
}

static	size_t	count_words(char const *str, char c)
{
	size_t	word;
	size_t	i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static char		**free_string(char **result)
{
	size_t i;

	i = 0;
	while (result[i])
		ft_strdel(&result[i++]);
	free(result);
	result = 0;
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**result;
	size_t		i;
	size_t		start;
	size_t		end;

	start = 0;
	end = 0;
	i = 0;
	if (!s || !(result = (char **)malloc(sizeof(char *)\
	* (count_words(s, c) + 1))))
		return (NULL);
	while (1)
	{
		start = word_start(s, end, c);
		end = word_end(s, start, c);
		if (s[start] == '\0')
			break ;
		if (!(result[i++] = ft_strsub((const char *)s, start, end - start)))
			return (free_string(result));
	}
	result[i] = 0;
	return (result);
}
