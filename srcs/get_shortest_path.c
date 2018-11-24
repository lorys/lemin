/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shortest_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 05:19:09 by llopez            #+#    #+#             */
/*   Updated: 2018/11/24 15:41:23 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		set_next(t_next *choice, int *steps, t_tube *room)
{
	choice->steps = *steps;
	choice->room = room;
	*steps = 0;
}

static t_tube	*choose_path(t_next *shortest, t_next *possible)
{
	if (shortest->room && !shortest->room->ants)
		return (shortest->room);
	if (possible->room && !possible->room->ants)
		return (possible->room);
	return (NULL);
}

static void		init_next(t_next *possible, t_next *shortest)
{
	possible->steps = -1;
	possible->room = NULL;
	shortest->steps = -1;
	shortest->room = NULL;
}

static int		stepslen(t_paths *paths)
{
	int i;

	i = 0;
	while (paths->steps[i + 1])
		i++;
	return (i);
}

t_tube			*get_shortest_path(t_paths *paths, t_tube *from, t_infos *infos)
{
	int		i;
	int		steps;
	t_next	possible;
	t_next	shortest;
	t_tube	*next;

	steps = 0;
	i = stepslen(paths);
	next = NULL;
	init_next(&possible, &shortest);
	while (i >= 0)
	{
		(paths->steps[i] != infos->start || paths->steps[i] != infos->end) &&\
							steps++;
		(paths->steps[i] == from) && (next = paths->steps[i - 1]);
		if (paths->steps[i] == infos->end\
				&& (shortest.steps > steps || shortest.steps == -1) && next)
			set_next(&shortest, &steps, next);
		if (paths->steps[i] == infos->end && next && !next->ants\
				&& (possible.steps > steps || possible.steps == -1))
			set_next(&possible, &steps, next);
		i--;
	}
	return (choose_path(&shortest, &possible));
}
