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

int	ft_linkslen(t_tube *room)
{
	t_paths *links;
	int	count;

	count = 0;
	links = room->links;
	while (links)
	{
		count++;
		links = links->next;
	}
	return (count);
}

t_tube	*minus_available(t_tube *room, t_infos *infos)
{
	t_paths	*links;
	t_tube	*minus;

	minus = NULL;
	links = room->links;
	while (links)
	{
		if (links->room == infos->end)
			return (infos->end);
		if ((!minus || minus->steps > links->room->steps)\
			 && links->room->steps && (!links->room->hidden\
			 || room == infos->start) && !links->room->ants)
			minus = links->room;
		links = links->next;
	}
	return (minus);
}

t_tube	*set_minus_path(t_infos *infos)
{
	t_paths	*links;
	t_tube	*minus;

	minus = NULL;
	links = infos->start->links;
	while (links)
	{
		if (links->room == infos->end)
			return (infos->end);
		if ((!minus || minus->steps > links->room->steps)\
			 && links->room->steps && !links->room->ants\
			 && bury_path(links->room, infos, 1))
		{
			printf("\n");
			minus = links->room;
		}
		links = links->next;
	}
	return (minus);
}

int	bury_path(t_tube *room, t_infos *infos, int nb)
{
	t_tube	*next;
	int	ret;

	ret = 0;
	room->vu = 3;
	if ((next = minus_available(room, infos)) == infos->end && ++ret)
		room->hidden = infos->paths_nb + nb;
	else if (next && next->vu != 3 && !next->hidden\
		 && (ret = bury_path(next, infos, nb + 1)))
	{
		printf("%s (%d steps)", room->name, room->steps);
		room->hidden = infos->paths_nb + nb;
	}
	room->vu = 0;
	return (ret);
}

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
	if (room->hidden && room != infos->start)
	{
		links = room->links;
		while (links)
		{
			if (!links->room->ants && links->room->steps\
			 && links->room->hidden == room->hidden + 1)
				return (links->room);
			links = links->next;
		}
	}
	if (room == infos->start)
	{
		if ((minus = set_minus_path(infos)))
			return (minus);
		links = room->links;
		while (links)
		{
			if ((!minus || minus->steps < links->room->steps)\
			 && links->room->steps && links->room->hidden && !links->room->ants)
				minus = links->room;
			links = links->next;
		}
	}
	return (minus);
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
