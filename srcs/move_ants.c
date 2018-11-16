/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:03:15 by llopez            #+#    #+#             */
/*   Updated: 2018/11/16 10:34:18 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
static int		is_linked(t_tube *a, t_tube *b)
{
	int	i;

	i = 0;
	while (a->links[i])
		if (a->links[i++] == b)
			return (1);
	return (0);
}
static int		how_many_paths(t_paths *paths, t_tube *from)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (paths->steps[i])
	{
		if (paths->steps[i] == from)
			count++;
		i++;
	}
	return (count);
}
*/
static t_tube	*get_shortest_path(t_paths *paths, t_tube *from, t_infos *infos)
{
	int		i;
	int		min;
	int		min_tmp;
	t_tube	*way;

	i = 0;
	min = -2;
	way = NULL;
	while (paths->steps[i])
	{
		if (paths->steps[i] == infos->end)
		{
			min_tmp = i;
			while (paths->steps[i] && paths->steps[i+1] != from)
			{
				i++;
				if (paths->steps[i] == infos->end)
					continue;
			}
			if ((i - min_tmp) < infos->fourmis && !paths->steps[i]->ants)
				return (paths->steps[i]);
			else if (infos->fourmis > 1\
				&& ((i - min_tmp) + infos->fourmis < min || min == -2))
			{
				min = (i - min_tmp);
				way = paths->steps[i];
			}
			else if ((i - min_tmp) < min && !paths->steps[i]->ants)
			{
				min = (i - min_tmp);
				way = paths->steps[i];
			}
		}
		i++;
	}
	return (way);
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
