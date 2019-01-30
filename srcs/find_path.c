/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:12:07 by llopez            #+#    #+#             */
/*   Updated: 2018/12/19 17:22:31 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		voyager(t_tube *room, t_tube *from, t_infos *infos, int nb)
{
	t_paths	*tmp;
	int	ret;
	int	total;
	int	ret_minus;
	t_tube	*minus_room;

	ret_minus = 0;
	total = 0;
	tmp = room->links;
	while (tmp)
	{
		if (tmp->room == infos->start || room == infos->start)
			return (nb);
		tmp = tmp->next;
	}
	room->vu = 1;
	tmp = room->links;
	minus_room = NULL;
	while (tmp)
	{
		if (tmp->room != infos->end && (!tmp->room->vu || tmp->room->pass > nb) && !tmp->room->steps && tmp->room != from && (ret = voyager(tmp->room, room, infos, nb + 1)))
		{
			total += ret;
			if (!ret_minus || ret < ret_minus)
			{
				ret_minus = ret;
				minus_room = tmp->room;	
			}
		}
		tmp = tmp->next;
	}
	if (!minus_room)
		return (0);
	minus_room->pass = nb;
	return (ret_minus);
}

void		set_position(t_tube *room, t_tube *from, t_infos *infos, int nb)
{
	t_paths	*links;

	links = room->links;
	if (room == infos->start)
		return ;
	room->steps = (!room->steps || room->steps > nb) ? nb : room->steps;
	room->vu = 2;
	while (links)
	{
		if (links->room != from && links->room->pass && links->room->vu != 2)
		{
			links->room->pass = 0;
			set_position(links->room, room, infos, nb + 1);
		}
		links = links->next;
	}
}

void		reset_view(t_tube *room)
{
	while (room->prev)
		room = room->prev;
	while (room)
	{
		room->vu = 0;
		room = room->next;
	}
}

int		find_path(t_infos *infos)
{
	t_paths	*links;
	int	total;
	int	ret;

	total = 0;
	links = infos->end->links;
	while (links)
	{
		if (links->room == infos->start)
			total++;
		if ((ret = voyager(links->room, infos->end, infos, 1)))
		{
			printf("voyager = %d\n", ret);
			total++;
			set_position(links->room, infos->end, infos, 1);
		}
		reset_view(infos->start);
		links = links->next;
	}
	return (total);
}
