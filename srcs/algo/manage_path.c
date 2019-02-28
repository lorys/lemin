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

int	bury_path(t_tube *room, t_infos *infos, int nb)
{
	t_tube	*next;
	int	ret;
	int	tmp;

	ret = 0;
	room->vu = 3;
	if ((next = minus_available(room, infos)) == infos->end && ++ret)
		room->hidden = infos->paths_nb + nb;
	else if (next && next != infos->start && next->vu != 3 && !next->hidden\
		 && (ret = bury_path(next, infos, nb + 1)))
		room->hidden = infos->paths_nb + nb;
	if (next && !ret)
	{
		tmp = next->steps;
		next->steps = 0;
		ret = bury_path(room, infos, nb);
		next->steps = tmp;
	}
	room->vu = 0;
	return (ret);
}

t_tube	*next_step_path(t_tube *room, int noants, t_infos *infos)
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
	links = room->links;
	while (links)
	{
		if (links->room != infos->start && links->room->hidden\
		&& links->room->hidden == room->hidden + 1\
		&& ((noants && !links->room->ants) || (!noants)))
			return (links->room);
		links = links->next;
	}
	return (NULL);
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
		&& links->room->steps && !links->room->hidden)
			minus = links->room;
		links = links->next;
	}
	return (minus);
}

t_tube	*minus_path(t_infos *infos, int noants)
{
	t_paths	*links;
	t_tube	*minus;

	minus = NULL;
	links = infos->start->links;
	while (links)
	{
		if (links->room == infos->end)
			return (infos->end);
		if (links->room->hidden && (!minus || path_length(minus, infos)\
		> path_length(links->room, infos)) && ((noants\
		&& !links->room->ants) || (!noants)))
			minus = links->room;
		links = links->next;
	}
	return (minus);
}

int	path_length(t_tube *room, t_infos *infos)
{
	t_paths *links;
	int	count;

	count = 0;
	links = NULL;
	if (!room || !room->hidden)
		return (-1);
	while (minus_available(room, infos) != infos->end)
	{
		links = room->links;
		while (links)
		{
			if (links->room->hidden == room->hidden + 1 && ++count)
			{
				room = links->room;
				break;
			}
			links = links->next;
		}
		if (!links)
			return (0);
	}
	return (count);
}
