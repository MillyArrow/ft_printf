/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 09:55:46 by marrow            #+#    #+#             */
/*   Updated: 2019/11/17 09:56:09 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	new_line(char **str, char **line)
{
	int		length;
	char	*tmp;

	length = 0;
	while (str[0][length] != '\n' && str[0][length] != '\0')
		length++;
	if (str[0] && str[0][length] == '\n')
	{
		*line = ft_strsub(str[0], 0, length);
		tmp = ft_strdup(&(str[0][length + 1]));
		free(str[0]);
		str[0] = tmp;
		if (str[0][0] == '\0')
			ft_strdel(&(str[0]));
	}
	else
	{
		*line = ft_strdup(str[0]);
		ft_strdel(&(str[0]));
	}
	return (1);
}

static	int	validation(const int fd, char **str, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	else
		return (new_line(&(*(str + fd)), line));
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		buffer[BUFF_SIZE + 1];
	static char	*str[10240];
	char		*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (validation(fd, str, line, ret));
}
