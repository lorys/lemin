/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 00:14:16 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/07 01:45:11 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "parser.h"

// static int		read_block(int fd, t_map **map_p)
// {
// 	ssize_t		ret;
// 	t_map		*new;
// 	t_map		*tmp;

// 	if (!map_p || !(new = ft_memalloc(sizeof(*new))))
// 		return (-2);
// 	errno = 0;
// 	if ((ret = read(fd, new->buffer, BUFFER_SIZE)) <= 0)
// 	{
// 		free(new);
// 		return (ret);
// 	}
// 	new->buffer[ret] = '\0';
// 	if (!(*map_p))
// 	{
// 		*map_p = new;
// 		return (1);
// 	}
// 	tmp = *map_p;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	tmp->next = new;
// 	return (1);
// }

static void		read_line(int fd, t_vertice **room_listp, t_infos *infos)
{
	char		*line;
	int			nline;

	line = NULL;
	nline = 0;
	while (get_next_line(fd, &line) > 0 && ++nline)
	{
		if (*line != '\0' && line_is_valid(room_listp, infos, line, nline))
			ft_printf("%s\n", line);
		else
		{
			get_next_line(fd, NULL);
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	write(1, "\n", 1);
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
	errno = 0;
	if (close(fd) == -1)
		perror("lem-in");
	return (1);
}