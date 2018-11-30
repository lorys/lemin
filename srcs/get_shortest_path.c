/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shortest_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 05:19:09 by llopez            #+#    #+#             */
/*   Updated: 2018/11/30 01:26:09 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		set_next(t_next **choice, int *steps, t_tube *room)
{
	(*choice)->steps = *steps;
	(*choice)->room = room;
	*steps = 0;
}

static t_tube	*choose_path(t_next *shortest, t_next *possible, t_infos *infos)
{
	t_tube *tmp;

	tmp = NULL;
	if (!shortest || !possible)
		return (NULL);
	(void)infos;
	if (shortest->room && !shortest->room->ants)
		tmp = shortest->room;
	if (possible->room && !tmp && possible->steps != -1)
		tmp = possible->room;
	free(possible);
	free(shortest);
	return (tmp);
}

static void		init_next(t_next **possible, t_next **shortest)
{
	(*possible) = (t_next *)malloc(sizeof(t_next));
	(*shortest) = (t_next *)malloc(sizeof(t_next));
	(*possible)->steps = INT_MAX;
	(*possible)->room = NULL;
	(*shortest)->steps = INT_MAX;
	(*shortest)->room = NULL;
}

static int		get_distance(t_paths *paths, t_tube *from)
{
	int	i;

	i = 0;
	if (!paths)
		return (-1);
	while (paths && paths->room != from)
	{
		i++;
		paths = paths->next;
	}
	return (i);
}

t_tube			*get_shortest_path(t_paths *paths, t_tube *from, t_infos *infos)
{
	int		steps;
	t_next	*possible;
	t_next	*shortest;
	t_tube	*next;

	steps = 0;
	next = NULL;
	possible = NULL;
	shortest = NULL;
	init_next(&possible, &shortest);
	while (paths->prev)
		paths = paths->prev;
	while (paths)
	{
		if (paths->room == from)
		{
			steps = get_distance(paths, infos->end);
			next = paths->next->room;
			if (next == infos->end)
			{
				free(possible);
				free(shortest);
				return (next);
			}
			if (steps < shortest->steps)
				set_next(&shortest, &steps, next);
			if (steps < possible->steps && !next->ants)
				set_next(&possible, &steps, next);
		}
		paths = paths->next;
	}
	return (choose_path(shortest, possible, infos));
}
