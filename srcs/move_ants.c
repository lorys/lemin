/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:03:15 by llopez            #+#    #+#             */
/*   Updated: 2018/11/21 09:26:18 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_tube	*get_shortest_path(t_paths *paths, t_tube *from, t_infos *infos)
{
	int		i;
	int		steps;
	int		min;
	int		min_possible;
	t_tube	*min_way;
	t_tube	*way;
	t_tube	*next;
	int		tmp;

	min_possible = -1;
	way = NULL;
	steps = 0;
	i = 0;
	min = -1;
	min_way = NULL;
	next = NULL;
	tmp = 0;
	while (paths->steps[i + 1])
		i++;
	while (i >= 0)
	{
		if (paths->steps[i] != infos->start || paths->steps[i] != infos->end)
			steps++;
		if (paths->steps[i] == from)
			next = paths->steps[i - 1];
		if (paths->steps[i] == infos->end && (min > steps || min == -1) && next)
		{
			min_way = next;
			min = steps;
			steps = 0;
		}
		if (paths->steps[i] == infos->end && next\
				&& !next->ants && (min_possible > steps || min_possible == -1))
		{
			min_possible = steps;
			way = next;
		}
		i--;
	}
	if ((min_way && !min_way->ants) || (way && !way->ants))
		return ((min_way && !min_way->ants) ? min_way : way);
	return (NULL);
}

static int		need_to_move(t_tube **ants, t_infos *infos)
{
	int i;

	i = 0;
	while (ants[i])
	{
		if (ants[i] != infos->end)
			return (1);
		i++;
	}
	return (0);
}

void			move_ants(t_paths *paths, t_infos *infos, t_tube **ants)
{
	int		i;
	t_tube	*new_room;

	i = 0;
	new_room = NULL;
	while (ants[i])
	{
		if (ants[i] == infos->end && ++i)
			continue;
		new_room = get_shortest_path(paths, ants[i], infos);
		if (new_room)
		{
			ants[i]->ants = 0;
			ants[i] = new_room;
			if (ants[i] != infos->end)
				ants[i]->ants = 1;
			ft_printf("L%d-%s ", i + 1, ants[i]->name);
		}
		i++;
	}
	ft_printf("\n");
	if (need_to_move(ants, infos))
		move_ants(paths, infos, ants);
}
