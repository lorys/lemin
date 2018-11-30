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

static int		check_number_of_ants(char *line, t_infos *infos)
{
	int		ret;
	long	tmp;

	ret = 0;
	if (!ft_strisdigit(line))
		error_parsing("the first line must be the number of ants", 1);
	else
	{
		tmp = ft_atoi_long(line);
		if (tmp > INT_MAX || tmp < INT_MIN || ft_strlen(line) > 10)
		{
			error_parsing("int overflow", 1);
			ret = 0;
		}
		else
		{
			infos->fourmis = (int)tmp;
			ret = 1;
		}
	}
	return (ret);
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
				t_tube **rooms, int nline)
{
	if (save_room_if_valid(line, rooms, nline))
	{
		*to_change = (*rooms)->prev;
		return (1);
	}
	return (0);
}

static int		check_line(t_tube **tube, t_infos *infos, char *line, int nline)
{
	static int	state = STATE_ROOMS;
	int			ret;

	ret = 0;
	if (state == STATE_START_ROOM || state == STATE_END_ROOM)
	{
		if (state == STATE_START_ROOM)
			ret = add_start_or_end_room(line, &(infos->start), tube, nline);
		else if (state == STATE_END_ROOM)
			ret = add_start_or_end_room(line, &(infos->end), tube, nline);
		state = STATE_ROOMS;
	}
	else if (nline == 1)
		ret = check_number_of_ants(line, infos);
	else if (*line == '#')
		ret = check_command_comment(line, &state, nline);
	else if (is_tube_valid(line))
		state = STATE_TUBES;
	else if (state == STATE_ROOMS)
		ret = save_room_if_valid(line, tube, nline);
	if (state == STATE_TUBES && !ret)
		ret = save_tube_if_valid(line, *tube, nline);
	return (ret);
}

int				read_stdin(t_tube *tube, t_infos *infos)
{
	char		*line;
	int			nline;
	int			ret;

	line = NULL;
	nline = 0;
	while (get_next_line(0, &line) > 0 && ++nline)
	{
		ret = check_line(&tube, infos, line, nline);
		if (ret)
			ft_printf("%s\n", line);
		else
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	write(1, "\n", 1);
	if (infos->fourmis <= 0)
		return (0);
	return (1);
}
