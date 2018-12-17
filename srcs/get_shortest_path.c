/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shortest_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 05:19:09 by llopez            #+#    #+#             */
/*   Updated: 2018/12/17 21:51:56 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
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
	if (possible->room)
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
*/

int				is_linked(t_tube *room1, t_tube *room2)
{
	t_paths	*links;

	links = room1->links;
	while (links->prev)
		links = links->prev;
	while (links)
	{
		if (links->room == room2)
			return (1);
		links = links->next;
	}
	return (0);
}

t_tube			*get_shortest_path(t_paths *paths, t_tube *from, t_infos *infos)
{
/*	int		steps;
	t_next	*possible;
	t_next	*shortest;

	steps = 0;
	possible = NULL;
	shortest = NULL;
	init_next(&possible, &shortest);
*/
	t_paths	*tmp;
	t_tube	*minus_next;
	int		count;
	int		minus;

	minus_next = NULL;
	minus = INT_MAX;
	if (is_linked(from, infos->end))
		return (infos->end);
	while (paths->prev)
		paths = paths->prev;
	while (paths)
	{
		if (is_linked(paths->room, from) && !paths->room->ants)
		{
			count = 0;
			tmp = paths;
			while (tmp && tmp->room != infos->end && tmp->room != infos->start)
			{
				count++;
				tmp = tmp->next;
			}
			if (count > 0 && count < minus)
			{
				minus_next = paths->room;
				minus = count;
				paths = tmp;
				continue;
			}
		}
		paths = paths->next;
	}
	return ((minus_next && !minus_next->ants) ? minus_next : NULL);
}
