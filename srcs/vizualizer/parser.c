/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:48:59 by llopez            #+#    #+#             */
/*   Updated: 2018/11/24 19:37:38 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "parser.h"

static int	save_room_if_valid(char *line, t_tube **rooms)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[i])
		i++;
	if (i != 3 || **tmp == 'L' || **tmp == '#' || !ft_strisdigit(tmp[1]) || !ft_strisdigit(tmp[2]))
		i = 0;
	else
	{
		i = 1;
		if (!save_room(rooms, tmp[0], ft_atoi(tmp[1]), ft_atoi(tmp[2])))
			i = 0;
	}
	free_char_tab(tmp);
	return (i);
}

static int	is_tube_valid(char *line)
{
	if (ft_strchr(line, '-') && !ft_strchr(line, ' '))
		return (1);
	return (0);
}

static int	save_tube_if_valid(char *line, t_tube *rooms)
{
	if (is_tube_valid(line))
	{
		if (make_tube(line, rooms))
			return (1);
	}
	return (0);
}

static int	check_number_of_ants(char *line, t_infos *infos)
{
	int		ret;

	ret = 0;
	if (ft_strisdigit(line))
	{
		infos->fourmis = ft_atoi(line);
		ret = 1;
	}
	return (ret);
}

static int	check_command_comment(char *line, int state)
{
	if (!ft_strcmp(line, "##start"))
		return (STATE_START_ROOM);
	else if (!ft_strcmp(line, "##end"))
		return (STATE_END_ROOM);
	else
		return (state);
}

static int	add_end_or_start_room(char *line, int state, t_infos *infos, t_tube **rooms)
{
	if (state == STATE_START_ROOM || state == STATE_END_ROOM)
	{
		if (save_room_if_valid(line, rooms))
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

static int	check_line(t_tube *tube, t_infos *infos)
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
			ret = add_end_or_start_room(line, state, infos, &tube);
			state = STATE_ROOMS;
		}
		else if (nline == 1)
			ret = check_number_of_ants(line, infos);
		else if (*line == '#')
			state = check_command_comment(line, state);
		else if (state == STATE_ROOMS)
		{
			if (is_tube_valid(line))
			{
				ret = save_tube_if_valid(line, tube);
				state = STATE_TUBES;
			}
			else
				ret = save_room_if_valid(line, &tube);
		}
		else if (state == STATE_TUBES)
			ret = save_tube_if_valid(line, tube);
		ft_strdel(&line);
		if (!ret)
			return (0);
	}
	ft_strdel(&line);
	return (1);
}

int		parse(t_tube *tube, t_infos *infos)
{
	check_line(tube, infos);
	if (infos->fourmis <= 0)
		return (0);
	return (1);
}
