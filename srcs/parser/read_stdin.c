/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:48:59 by llopez            #+#    #+#             */
/*   Updated: 2018/11/30 05:51:33 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "parser.h"

static int	check_number_of_ants(char *line, t_infos *infos)
{
	int		ret;

	ret = 0;
	if (!ft_strisdigit(line))
		error_parsing("the first line must be the number of ants", 1);
	else
	{
		infos->fourmis = ft_atoi(line);
		ret = 1;
	}
	return (ret);
}

static int	check_command_comment(char *line, int state, int nline)
{
	if (!ft_strcmp(line, "##start"))
		return (STATE_START_ROOM);
	else if (!ft_strcmp(line, "##end"))
		return (STATE_END_ROOM);
	else
	{
		if (line[1] == '#')
			warn_parsing("unknown command, ignoring it", nline);
		return (state);
	}
}

static int	add_end_or_start_room(char *line, int state, t_infos *infos, \
		t_tube **rooms, int nline)
{
	if (state == STATE_START_ROOM || state == STATE_END_ROOM)
	{
		if (save_room_if_valid(line, rooms, nline))
		{
			if (state == STATE_START_ROOM)
				infos->start = (*rooms)->prev;
			else
				infos->end = (*rooms)->prev;
			return (1);
		}
	}
	return (0);
}

int			check_line(t_tube *tube, t_infos *infos)
{
	char	*line;
	int		nline;
	int		state;
	int		ret;

	line = NULL;
	nline = 0;
	state = STATE_ROOMS;
	ret = 0;
	while (get_next_line(0, &line) > 0 && ++nline)
	{
		if (state == STATE_START_ROOM || state == STATE_END_ROOM)
		{
			ret = add_end_or_start_room(line, state, infos, &tube, nline);
			state = STATE_ROOMS;
		}
		else if (nline == 1)
			ret = check_number_of_ants(line, infos);
		else if (*line == '#')
			state = check_command_comment(line, state, nline);
		else if (state == STATE_ROOMS)
		{
			if (is_tube_valid(line))
			{
				ret = save_tube_if_valid(line, tube, nline);
				state = STATE_TUBES;
			}
			else
				ret = save_room_if_valid(line, &tube, nline);
		}
		else if (state == STATE_TUBES)
			ret = save_tube_if_valid(line, tube, nline);
		if (ret)
			ft_printf("%s\n", line);
		ft_strdel(&line);
		if (!ret)
			return (0);
	}
	ft_strdel(&line);
	return (1);
}

int			read_stdin(t_tube *tube, t_infos *infos)
{
	check_line(tube, infos);
	write(1, "\n", 1);
	if (infos->fourmis <= 0)
		return (0);
	return (1);
}
