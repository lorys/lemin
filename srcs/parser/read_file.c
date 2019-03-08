/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 00:14:16 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/09 00:42:07 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include "libft.h"
#include "get_next_line.h"
#include "parser.h"

static void		read_line(int fd, t_vertice **room_listp, t_infos *infos)
{
	char		*line;
	int			nline;

	line = NULL;
	nline = 0;
	while (get_next_line(fd, &line) > 0 && ++nline)
	{
		if (*line != '\0' && line_is_valid(room_listp, infos, line, nline))
			fill_buffer(line);
		else
		{
			get_next_line(fd, NULL);
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

int				read_file(t_infos *infos)
{
	int		fd;

	fd = STDIN_FILENO;
	if (infos->file_path != NULL)
	{
		errno = 0;
		if ((fd = open(infos->file_path, O_RDONLY)) < 0)
		{
			perror("lem-in");
			return (-1);
		}
	}
	read_line(fd, &infos->room_list, infos);
	fill_buffer(NULL);
	if (fd != STDIN_FILENO)
		close(fd);
	return (1);
}

void			fill_buffer(char *str)
{
	static char		buffer[LI_BUFFER_SIZE + 1] = {'\0'};
	static size_t	index = 0;
	size_t			str_len;

	str_len = 0;
	if (str == NULL || index + (str_len = ft_strlen(str)) >= LI_BUFFER_SIZE)
	{
		write(1, buffer, index);
		index = 0;
		if (str == NULL)
			return ;
	}
	ft_strcpy(buffer + index, str);
	index += str_len;
	buffer[index++] = '\n';
}
