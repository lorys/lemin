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

int	voyager(t_tube *room, t_tube *from, int nb, t_infos *infos)
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
			total += voyager(links->room, room, nb + 1, infos);
		links = links->next;
	}
	if (!total)
		room->steps = 0;
	return (total);
}

int	find_paths(t_infos *infos)
{
	voyager(infos->end, NULL, 1, infos);
	return (infos->bfs);
}
