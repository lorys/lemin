/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 00:14:16 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/07 14:59:36 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "libft.h"
#include "get_next_line.h"
#include "parser.h"
#include "common.h"

static void		read_line(int fd, t_vertice **room_listp, t_infos *infos)
{
	char		*line;
	int			nline;

	line = NULL;
	nline = 0;
	while (get_next_line(fd, &line) > 0 && ++nline)
	{
		if (*line != '\0' && line_is_valid(room_listp, infos, line, nline))
			ft_putendl(line);
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

int			read_file(t_vertice **room_listp, t_infos *infos)
{
	int		fd;

	fd = 0;
	if (infos->file_path != NULL)
	{
		errno = 0;
		if ((fd = open(infos->file_path, O_RDONLY)) < 0)
		{
			perror("lem-in");
			return (-1);
		}
	}
	read_line(fd, room_listp, infos);
	print_matrix(infos);
	errno = 0;
	if (close(fd) == -1)
		perror("lem-in");
	return (1);
}