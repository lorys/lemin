/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:48:59 by llopez            #+#    #+#             */
/*   Updated: 2019/02/07 01:42:15 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "common.h"
#include "lem_in.h"
#include "parser.h"

static int		check_number_of_ants(char *line, t_infos *infos)
{
	if (!ft_stris(line, &ft_isdigit))
		error_parsing("the first line must be the number of ants", 1);
	else
	{
		if (!check_overflow(line))
			error_parsing("int overflow", 1);
		else
		{
			infos->fourmis = ft_atoi(line);
			return (1);
		}
	}
	return (0);
}

static int		check_command_comment(char *line, int *state, int nline)
{
	if (!ft_strcmp(line, "##start"))
		*state = STATE_START_ROOM;
	else if (!ft_strcmp(line, "##end"))
		*state = STATE_END_ROOM;
	else
	{
		if (line[1] == '#')
			warn_parsing("unknown command, ignoring it", nline);
	}
	return (1);
}

static int		add_start_or_end_room(char *line, t_vertice **to_change, \
				t_vertice **room_listp, int nline)
{
	t_vertice		*tmp;

	if ((tmp = is_room_valid(line, *room_listp, nline)))
	{
		append_room(room_listp, tmp);
		*to_change = tmp;
		return (1);
	}
	return (0);
}

int				line_is_valid(t_vertice **room_listp, t_infos *infos, \
				char *line, int nline)
{
	static int	state = STATE_ROOMS;
	int			ret;

	ret = 0;
	if (state == STATE_START_ROOM || state == STATE_END_ROOM)
	{
		if (state == STATE_START_ROOM)
			ret = add_start_or_end_room(line, &(infos->start), room_listp, nline);
		else if (state == STATE_END_ROOM)
			ret = add_start_or_end_room(line, &(infos->end), room_listp, nline);
		state = STATE_ROOMS;
	}
	else if (nline == 1)
		ret = check_number_of_ants(line, infos);
	else if (*line == '#')
		ret = check_command_comment(line, &state, nline);
	else if (state == STATE_ROOMS && is_tube_valid(line, *room_listp, 0))
		state = STATE_TUBES;
	else if (state == STATE_ROOMS)
		ret = save_room_if_valid(line, room_listp, infos, nline);
	if (state == STATE_TUBES && !ret)
		ret = save_tube_if_valid(line, *room_listp, nline);
	return (ret);
}

// int			parse(t_map *map, t_vertice **room_listp, t_infos *infos)
// {
// 	char			*back_pointer;
// 	char			*forward_pointer;
// 	t_map			*backup;
// 	unsigned int	nline;

// 	back_pointer = map->buffer;
// 	nline = 0;
// 	while ((forward_pointer = ft_strchr(back_pointer, '\n')) != NULL)
// 	{
// 		*forward_pointer = '\0';
// 		line_is_valid(room_listp, infos, back_pointer, ++nline);
// 		*forward_pointer = '\n';
// 		back_pointer = ++forward_pointer;
// 	}
// 	backup = map;
// 	if ((map = map->next) == NULL)
// 		return (0);
// 	while ((forward_pointer = ft_strchr(map->buffer, '\n')) == NULL)
// 		map = map->next;
// }

// int				count_block(t_map *map)
// {
// 	int			ret;

// 	ret = 0;
// 	while (map)
// 	{
// 		ret++;
// 		map = map->next;
// 	}
// 	return (ret);
// }

// void			copy_blocks(char *line, t_map *map)
// {
// 	int			count;
// 	t_map		*tmp;

// 	count = 0;
// 	tmp = map;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	while (tmp->prev)
// 	{
// 		ft_strcpy(line + (count * BUFFER_SIZE), tmp->buffer);
// 		count++;
// 		tmp = tmp->prev;
// 	}
// }

// void			free_blocks(t_map *map)
// {
// 	if (map)
// 	{
// 		free_blocks(map->next);
// 		free(map);
// 	}
// }

// int				get_line(int fd, char **line)
// {
// 	static t_map	buffer_map = {{'\0'}, NULL, NULL};
// 	static char		*back_pointer;
// 	char			*forward_pointer;
// 	int				ret;

// 	if (*buffer_map.buffer == '\0')
// 	{
// 		if ((ret = read(fd, buffer_map.buffer, BUFFER_SIZE)) <= 0)
// 			return (ret);
// 		back_pointer = buffer_map.buffer;
// 	}
// 	if ((forward_pointer = ft_strchr(back_pointer, '\n')))
// 	{
// 		back_pointer = forward_pointer;
// 		*line = ft_strndup(back_pointer, forward_pointer - back_pointer);
// 		return (line == NULL ? -2 : 1);
// 	}
// 	else
// 	{
// 		while ((ret = read_block(fd, &buffer_map.next)) == 1
// 			&& (forward_pointer = ft_strchr(buffer_map.next->buffer, '\n')) == NULL)
// 			;
// 		if (ret <= 0)
// 		{
// 			free_blocks(buffer_map.next);
// 			return (ret);
// 		}
// 		*line = ft_strnew((ret = ft_strlen(back_pointer)) + ((count_block(buffer_map.next) - 1) * BUFFER_SIZE) + (forward_pointer - buffer_map.next));
// 		ft_strcpy(*line, back_pointer);
// 		if (count_block(buffer_map.next) > 1)
// 			copy_blocks(*(line + ret), buffer_map.next);
// 		ft_strcpy(buffer_map.buffer, buffer_map.next->buffer);
// 		back_pointer = forward_pointer;
// 		free_blocks(buffer_map.next);
// 		return (1);
// 	}
// }



// void				read_stdin(t_vertice **room_listp, t_infos *infos)
// {
// 	char		*line;
// 	char		buffer[4096];
// 	char		*forward_pointer;
// 	char		*back_pointer;
// 	int			nline;
// 	int			ret;

// 	line = NULL;
// 	nline = 0;
// 	ret = read(0, buffer, 4096 / 2);
// 	buffer[ret] = '\0';
// 	back_pointer = buffer;
// 	while (forward_pointer = ft_strchr(back_pointer, '\n'))
// 	{
// 		*forward_pointer = '\0';
// 		if (line_is_valid(room_listp, infos, back_pointer, nline) && *forward_pointer = '\n')
// 		{
// 			write(1, back_pointer, forward_pointer - back_pointer);
// 		}
// 		else
// 			break ;
// 		back_pointer = forward_pointer;
// 	}
// 	while (get_next_line(0, &line) > 0 && ++nline)
// 	{
// 		if (*line != '\0' && line_is_valid(room_listp, infos, line, nline))
// 			ft_printf("%s\n", line);
// 		else
// 			break ;
// 		ft_strdel(&line);
// 	}
// 	ft_strdel(&line);
// 	ft_putchar('\n');
// 	if (infos->start && infos->end)
// 		infos->room_total += 2;
// }
