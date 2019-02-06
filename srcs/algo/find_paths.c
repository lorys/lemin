/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:51:27 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/03 20:34:09 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lem_in.h"

int	flow_count(t_tube *room, int *capacity, int *flow, t_infos *infos)
{
	t_paths	*links;

	if (room == infos->end)
		return (1);
	links = room->links;
	(*capacity)++;
	if (room->ants)
		(*flow)++;
	while (links)
	{
		if (links->room->steps && links->room->steps < room->steps)
			flow_count(links->room, capacity, flow, infos);
		links = links->next;
	}
	return (0);
}

t_tube	*get_minus(t_tube *room, t_infos *infos)
{
	t_paths	*links;
	int	capacity;
	int	flow;
	int	cf;
	t_tube	*next;

	next = NULL;
	cf = 0;
	links = room->links;
	while (links)
	{
		capacity = 0;
		flow = 0;
		if (links->room->steps && !links->room->already_moved)
		{
			flow_count(links->room, &capacity, &flow, infos);
			/*printf("link = %s (%d)\tcapacity = %d\tflow = %d\n", \
				links->room->name, \
				links->room->steps, \
				capacity, flow);
			*/if (!cf || cf > capacity - flow)
			{
				cf = capacity - flow;
				next = links->room;
			}
		}
		links = links->next;
	}
	if (next)
		printf("next = %s\n", next->name);
	return (next);
}

int	bfs(t_tube *room, t_tube *from, int nb, t_infos *infos)
{
	t_paths *links;
	int	total;

	if (room == infos->start && ++infos->bfs)
		return (1);
	total = 0;
	links = room->links;
	room->vu = 1;
	while (links)
	{
		if (links->room != from && links->room->steps > 0\
			 && links->room->steps < nb)
			return (1);
		if (links->room != infos->end && links->room != infos->start\
			 && (!links->room->steps || links->room->steps > nb))
			links->room->steps = nb;
		links = links->next;
	}
	links = room->links;
	while (links)
	{
		if (links->room != from && (links->room->steps\
			 || links->room == infos->start))
			total += bfs(links->room, room, nb + 1, infos);
		links = links->next;
	}
	if (!total)
		room->steps = 0;
	return (total);
}

int	find_paths(t_infos *infos)
{
	bfs(infos->end, NULL, 1, infos);
	return (infos->bfs);
}
