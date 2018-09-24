/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:51:28 by llopez            #+#    #+#             */
/*   Updated: 2017/12/15 16:57:45 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static int		find_break(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (i - 1);
	return (-1);
}

static char		*ft_strfjoin(char *s1, char const *s2)
{
	char		*alloc;
	int			s_len[2];
	int			i;
	int			x;

	i = 0;
	x = 0;
	s_len[0] = ft_strlen(s1);
	s_len[1] = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	alloc = ft_strnew(s_len[0] + s_len[1]);
	if (!alloc)
		return (NULL);
	while (s1[i] != '\0')
		alloc[x++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		alloc[x++] = s2[i++];
	alloc[x] = '\0';
	free(s1);
	return (alloc);
}

static int		ft_fill_buff(int fd, char **line, char **buff)
{
	int			break_found;
	int			i_buff;
	char		line_read[BUFF_SIZE + 1];

	while ((i_buff = read(fd, line_read, BUFF_SIZE)) > 0)
	{
		break_found = find_break(line_read);
		line_read[i_buff] = '\0';
		if (break_found > -1)
		{
			line_read[break_found] = '\0';
			*line = ft_strfjoin(*line, line_read);
			*buff = ft_strfjoin(*buff, (line_read + break_found + 1));
			return (1);
		}
		else
			*line = ft_strfjoin(*line, line_read);
	}
	return (ft_strlen(*line) > 0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buff[1000];

	if (fd < 0 || read(fd, NULL, 0) == -1 || line == NULL)
		return (-1);
	if (buff[fd] != NULL)
	{
		if (find_break(buff[fd]) > -1)
		{
			*line = ft_strndup(buff[fd], find_break(buff[fd]));
			ft_strcpy(buff[fd], (buff[fd] + find_break(buff[fd]) + 1));
			return (1);
		}
		else
		{
			*line = ft_strdup(buff[fd]);
			free(buff[fd]);
			buff[fd] = ft_strnew(0);
		}
	}
	else
	{
		buff[fd] = ft_strnew(0);
		*line = ft_strnew(0);
	}
	return (ft_fill_buff(fd, line, &buff[fd]));
}
