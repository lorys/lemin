/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:03:15 by llopez            #+#    #+#             */
/*   Updated: 2018/12/06 18:33:53 by llopez           ###   ########.fr       */
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

static void		fill_buffer(char *str, char *buffer)
{
	int i;
	int	a;

	a = 0;
	i = 0;
	while (i < 6000)
	{
		if (buffer[i] == '\0')
		{
			while (a+i < 6000)
			{
				if (!str[a])
				{
					buffer[i+a] = '\0';
					break;
				}
				buffer[i+a] = str[a];
				a++;
			}
			if (a+i == 6000)
			{
				write(1, buffer, ft_strlen(buffer));
				buffer[0] = '\0';
			}
		}
		i++;
	}
}

static void		show_ant(int l, t_tube *room, t_infos *infos, char *buffer)
{
	if (infos->select == l)
	{
		fill_buffer("\033[41mL", buffer);
		fill_buffer(ft_itoa(l), buffer);
		fill_buffer(room->name, buffer);
		fill_buffer("\033[0m", buffer);
	}
	else if (infos->bonus)
	{
		fill_buffer("\033[", buffer);
		fill_buffer(ft_itoa(l), buffer);
		fill_buffer("mL", buffer);
		fill_buffer(ft_itoa(l), buffer);
		fill_buffer(room->name, buffer);
		fill_buffer("\033[0m", buffer);
	}
	else
	{
		fill_buffer("L", buffer);
		fill_buffer(ft_itoa(l + 1), buffer);
		fill_buffer("-", buffer);
		fill_buffer(room->name, buffer);
	}
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

void			move_ants(t_paths *paths, t_infos *infos, char *buffer)
{
	int		i;
	int		ants_moved;

	ants_moved = 0;
	i = infos->end->ants;
	while (i < infos->fourmis)
	{
		if (change_room((i + 1), paths, infos))
		{
			if (ants_moved)
				fill_buffer(" ", buffer);
			show_ant(i, whereis((i + 1), paths, infos), infos, buffer);
			ants_moved++;
		}
		i++;
	}
	if (ants_moved)
	{
		fill_buffer("\n", buffer);
		move_ants(paths, infos, buffer);
	}
}
