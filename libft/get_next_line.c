/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:34:07 by pcarles           #+#    #+#             */
/*   Updated: 2017/12/07 17:49:38 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include "get_next_line.h"

static char	*join_until(char *s1, char *s2, char c)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s2[i] && s2[i] != c)
		i++;
	p = ft_strnew(ft_strlen(s1) + i);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j] && s2[j] != c)
		p[i++] = s2[j++];
	return (p);
}

static int	put_rest(char **rest, char **line)
{
	char	*tmp;

	if (*rest)
	{
		if ((tmp = ft_strchr(*rest, '\n')))
		{
			*line = join_until(*line, *rest, '\n');
			tmp = ft_strdup(tmp + 1);
			free(*rest);
			*rest = tmp;
			return (1);
		}
		*line = join_until(*line, *rest, '\n');
		ft_memdel((void**)&*rest);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*lst[OPEN_MAX] = {NULL};
	int			count;

	if (fd < 0 || !line || BUFF_SIZE < 1 || fd > OPEN_MAX)
		return (-1);
	*line = ft_strnew(0);
	if (put_rest(&lst[fd], line))
		return (1);
	while ((count = read(fd, buff, BUFF_SIZE)))
	{
		if (count == -1)
			return (-1);
		buff[count] = '\0';
		*line = join_until(*line, buff, '\n');
		if ((lst[fd] = ft_strchr(buff, '\n')))
		{
			lst[fd] = ft_strdup(lst[fd] + 1);
			break ;
		}
	}
	return (count == 0 && ft_strlen(*line) == 0 ? 0 : 1);
}
