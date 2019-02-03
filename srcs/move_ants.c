/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:03:15 by llopez            #+#    #+#             */
/*   Updated: 2019/02/03 23:53:42 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		change_room(t_infos *infos, t_tube *from, t_tube *to, \
		char *buffer)
{
	int	init_ants;

	if (!to || !from)
		return (0);
	init_ants = from->ants;
	if (to == infos->end)
	{
		from->ants = 0;
		infos->end->ants++;
	}
	if (from == infos->start)
	{
		infos->start->ants--;
		init_ants = infos->fourmis - infos->start->ants;
		to->ants = init_ants;
		to->already_moved = 1;
	}
	else if (to != infos->end)
	{
		to->ants = from->ants;
		from->ants = 0;
		to->already_moved = 1;
	}
	show_ant(init_ants, to, infos, buffer);
	return (1);
}

static t_tube		*get_minus(t_tube *room, t_infos *infos)
{
	t_tube	*minus;
	t_paths	*tmp;

	if (!room || !room->ants || room->already_moved)
		return (NULL);
	tmp = room->links;
	minus = NULL;
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		if (tmp->room == infos->end)
			return (infos->end);
		if (!tmp->room->ants && tmp->room != infos->start\
				&& tmp->room->steps > 0 && (tmp->room->steps < room->steps\
				|| room == infos->start)\
				&& (!minus || minus->steps > tmp->room->steps))
			minus = tmp->room;
		tmp = tmp->next;
	}
	return (minus);
}

t_tube			*choose_ants(t_tube *room, t_infos *infos)
{
	t_tube	*minus_room;

	minus_room = NULL;
	if (get_minus(infos->start, infos))
		return (infos->start);
	while (room)
	{
		if (get_minus(room, infos))
			return (room);
		room = room->next;
	}
	return (minus_room);
}

void			move_ants(t_infos *infos, char *buffer)
{
	t_tube		*tmp;
	t_tube		*skip;
	int		moved;
	t_tube	*base;

	moved = 0;
	base = infos->start;
	tmp = NULL;
	skip = NULL;
	while (base->prev)
		base = base->prev;
	while ((tmp = choose_ants(base, infos)))
	{
		if (tmp->ants && !tmp->already_moved)
		{
			skip = get_minus(tmp, infos);
			if (skip)
			{
				if (moved)
					fill_buffer(" ", buffer, 0, infos);
				moved += change_room(infos, tmp, skip, buffer);
			}
		}
		if (tmp != infos->start && !get_minus(tmp, infos))
			tmp = tmp->next;
	}
	tmp = base;
	while (tmp)
	{
		tmp->already_moved = 0;
		tmp = tmp->next;
	}
	if (moved)
	{
		infos->rounds++;
		fill_buffer("\n", buffer, 0, infos);
	}
	if (infos->end->ants < infos->fourmis)
		move_ants(infos, buffer);
}
