/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shortest_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 05:19:09 by llopez            #+#    #+#             */
/*   Updated: 2018/11/29 06:47:07 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		set_next(t_next **choice, int *steps, t_tube *room)
{
	(*choice)->steps = *steps;
	(*choice)->room = room;
	*steps = 0;
}

static t_tube	*choose_path(t_next *shortest, t_next *possible)
{
	t_tube *tmp;

	tmp = NULL;
	if (!shortest || !possible)
		return (NULL);
	if (shortest->room && !shortest->room->ants)
	{
		tmp = shortest->room;
		free(possible);
		free(shortest);
		return (tmp);
	}
	if (possible->room && !possible->room->ants)
	{
		tmp = possible->room;
		free(possible);
		free(shortest);
		return (tmp);
	}
	free(possible);
	free(shortest);
	return (NULL);
}

static void		init_next(t_next **possible, t_next **shortest)
{
	(*possible) = (t_next *)malloc(sizeof(t_next));
	(*shortest) = (t_next *)malloc(sizeof(t_next));
	(*possible)->steps = -1;
	(*possible)->room = NULL;
	(*shortest)->steps = -1;
	(*shortest)->room = NULL;
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
		if (paths->room != infos->start || paths->room != infos->end)
			steps++;
		if (paths->room == from)
			next = paths->next->room;
		if (next == infos->end)
		{
			free(possible);
			free(shortest);
			return (next);
		}
		if (paths->room == infos->end\
				&& (shortest->steps > steps || shortest->steps == -1) && next)
			set_next(&shortest, &steps, next);
		if (paths->room == infos->end && next && !next->ants \
				&& (possible->steps > steps || possible->steps == -1))
			set_next(&possible, &steps, next);
		paths = paths->next;
	}
	return (choose_path(shortest, possible));
}
