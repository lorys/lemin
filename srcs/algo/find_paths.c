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

t_tube	*get_minus(t_tube *room, t_infos *infos)
{
	t_paths	*links;
	t_tube	*minus;

	minus = NULL;
	links = room->links;
	while (links)
	{
		if (links->room == infos->end)
			return (infos->end);
		links = links->next;
	}
	if (room == infos->start)
	{
		minus = minus_path(infos, 1);
		if (!minus && infos->paths_nb <= 3 && bury_path(infos->start, infos, 1)\
		&& ++infos->paths_nb)
			minus = minus_path(infos, 1);
	}
	else
		minus = next_step_path(room, 1, infos);
	return ((minus && !minus->ants) ? minus : NULL);
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
