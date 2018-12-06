/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:48:59 by llopez            #+#    #+#             */
/*   Updated: 2018/12/04 22:43:42 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int		add_start_or_end_room(char *line, t_tube **to_change, \
				t_tube **room_listp, int nline)
{
	t_tube		*tmp;

	if ((tmp = is_room_valid(line, *room_listp, nline)))
	{
		append_room(room_listp, tmp);
		*to_change = tmp;
		return (1);
	}
	return (0);
}

int				line_is_valid(t_tube **room_listp, t_infos *infos, \
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
		ret = save_room_if_valid(line, room_listp, nline);
	if (state == STATE_TUBES && !ret)
		ret = save_tube_if_valid(line, *room_listp, nline);
	return (ret);
}

int				read_stdin(t_tube **room_listp, t_infos *infos)
{
	char		*line;
	int			nline;

	line = NULL;
	nline = 0;
	while (get_next_line(0, &line) > 0 && ++nline)
	{
		if (*line != '\0' && line_is_valid(room_listp, infos, line, nline))
			ft_printf("%s\n", line);
		else
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	write(1, "\n", 1);
	if (infos->fourmis <= 0)
		return (0);
	// t_tube	*tmp = *room_listp;
	// t_paths	*tmp1;
	// while (tmp)
	// {
	// 	ft_printf("Room name: %s\n", tmp->name);
	// 	tmp1 = tmp->links;
	// 	while (tmp1)
	// 	{
	// 		ft_printf("Link name: %p\n", tmp1->room);
	// 		tmp1 = tmp1->next;
	// 	}
	// 	ft_putchar('\n');
	// 	tmp = tmp->next;
	// }
	return (1);
}
