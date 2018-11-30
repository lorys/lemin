/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:03:15 by llopez            #+#    #+#             */
/*   Updated: 2018/11/30 11:31:27 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_tube	*whereis(int ants, t_paths *paths, t_infos *infos)
{
	if (ants <= infos->end->ants)
		return (paths->room);
	while (paths->prev)
		paths = paths->prev;
	while (paths && paths->next)
	{
		if (paths->room->ants == ants && paths->room != infos->start \
					&& paths->room != infos->end)
			return (paths->room);
		paths = paths->next;
	}
	return (infos->start);
}

static void		show_ant(int l, t_tube *room, t_infos *infos)
{
	if (infos->select == l)
		ft_printf("\033[41mL%d-%s\033[0m", l, room->name);
	else if (infos->bonus)
		ft_printf("\033[%dmL%d-%s\033[0m", l, l, room->name);
	else
		ft_printf("L%d-%s", l, room->name);
}

static int		change_room(int l, t_paths *paths, t_infos *infos)
{
	t_tube	*new_room;
	t_tube	*from;

	from = whereis(l, paths, infos);
	new_room = get_shortest_path(paths, from, infos);
	if (new_room)
	{
		from->ants = 0;
		if (new_room != infos->end && new_room != infos->start)
			new_room->ants = l;
		else if (new_room == infos->end)
			new_room->ants++;
		else if (new_room == infos->start)
			new_room->ants--;
		return (1);
	}
	return (0);
}

void			move_ants(t_paths *paths, t_infos *infos)
{
	int		i;
	int		ants_moved;

	ants_moved = 0;
	i = infos->end->ants;
	while ((i + 1) <= infos->fourmis)
	{
		if ((i + 1) <= infos->end->ants && ++i)
			continue;
		if (change_room((i + 1), paths, infos))
		{
			if (ants_moved)
				write(1, " ", 1);
			show_ant((i + 1), whereis((i + 1), paths, infos), infos);
			ants_moved++;
		}
		i++;
	}
	if (ants_moved)
	{
		write(1, "\n", 1);
		move_ants(paths, infos);
	}
}
