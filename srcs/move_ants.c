/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:03:15 by llopez            #+#    #+#             */
/*   Updated: 2018/12/07 01:30:05 by llopez           ###   ########.fr       */
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

 void			fill_buffer(const char *str, char *buffer, int print)
{
	static size_t	index = 0;
	int				str_len;
	char			*tmp;

	if (print)
	{
		write(1, buffer, index);
		index = 0;
		return ;
	}
	tmp = buffer + index;
	str_len = ft_strlen(str);
	if (index + str_len >= BUFFER_SIZE-1)
	{
		write(1, buffer, index);
		index = 0;
		fill_buffer(str, buffer, 1);
		return ;
	}
	ft_memcpy(tmp, str, str_len);
	index += str_len;
}

static void		show_ant(int l, t_tube *room, t_infos *infos, char *buffer)
{
	if (infos->select == l)
	{
		fill_buffer("\033[41mL", buffer, 0);
		fill_buffer(ft_itoa(l), buffer, 0);
		fill_buffer(room->name, buffer, 0);
		fill_buffer("\033[0m", buffer, 0);
	}
	else if (infos->bonus)
	{
		fill_buffer("\033[", buffer, 0);
		fill_buffer(ft_itoa(l), buffer, 0);
		fill_buffer("mL", buffer, 0);
		fill_buffer(ft_itoa(l), buffer, 0);
		fill_buffer(room->name, buffer, 0);
		fill_buffer("\033[0m", buffer, 0);
	}
	else
	{
		fill_buffer("L", buffer, 0);
		fill_buffer(ft_itoa(l + 1), buffer, 0);
		fill_buffer("-", buffer, 0);
		fill_buffer(room->name, buffer, 0);
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
				fill_buffer(" ", buffer, 0);
			show_ant(i, whereis((i + 1), paths, infos), infos, buffer);
			ants_moved++;
		}
		i++;
	}
	if (ants_moved)
	{
		fill_buffer("\n", buffer, 0);
		move_ants(paths, infos, buffer);
	}
}
