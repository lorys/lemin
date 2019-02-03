/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:03:15 by llopez            #+#    #+#             */
/*   Updated: 2019/02/03 11:49:33 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			fill_buffer(const char *str, char *buffer, int print,\
		t_infos *infos)
{
	static size_t	index = 0;
	int				str_len;
	char			*tmp;

	if (print || infos->bonus || infos->select > 0)
	{
		if (print)
			write(1, buffer, index);
		else
			write(1, str, ft_strlen(str));
		index = 0;
		return ;
	}
	tmp = buffer + index;
	str_len = ft_strlen(str);
	if (index + str_len >= BUFFER_SIZE - 1)
	{
		write(1, buffer, index);
		index = 0;
		fill_buffer(str, buffer, 0, infos);
		return ;
	}
	ft_memcpy(tmp, str, str_len);
	index += str_len;
}

static void		show_ant(int l, t_tube *room, t_infos *infos, char *buffer)
{
	char	*tmp;

	if (!room || !infos)
		return ;
	if (infos->select == l)
		ft_printf("\033[41mL%d-%s\033[0m", l, room->name);
	else if (infos->bonus)
		ft_printf("\033[%dmL%d-%s\033[0m", l, l, room->name);
	else
	{
		tmp = ft_itoa(l);
		fill_buffer("L", buffer, 0, infos);
		fill_buffer(tmp, buffer, 0, infos);
		fill_buffer("-", buffer, 0, infos);
		fill_buffer(room->name, buffer, 0, infos);
		free(tmp);
	}
}

static int		change_room(t_infos *infos, t_tube *from, t_tube *to, char *buffer)
{
	int	init_ants;

	if (!to || !from)
		return (0);
	init_ants = from->ants;
	if (to == infos->end)
	{
		if (from != infos->start)
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
	t_tube	*minus_possible;
	t_paths	*tmp;

	if (!room || !room->ants || room->already_moved)
		return (NULL);
	tmp = room->links;
	minus = NULL;
	minus_possible = NULL;
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		if (tmp->room == infos->end)
			return (infos->end);
		if (!tmp->room->ants && tmp->room != infos->start && tmp->room->steps > 0 && (tmp->room->steps < room->steps || room == infos->start)\
			 && (!minus || minus->steps > tmp->room->steps))
			minus = tmp->room;
		tmp = tmp->next;
	}
	return (minus);
}

t_tube			*choose_ants(t_tube *room, t_infos *infos)
{
	t_tube	*minus_room;
	t_tube	*next;
	int		i;

	i = 0;
	next = NULL;
	minus_room = NULL;
	if (get_minus(infos->start, infos))
	{
		printf("%s\n", get_minus(infos->start));
		usleep(100000);
		return (infos->start);
	}
	while (room)
	{
		if (room->ants && (minus_room = get_minus(room, infos))\
				&& (!next || minus_room->steps < next->steps))
			next = minus_room;
		room = room->next;
	}
	printf("----->>>>>> %s\n", (next)?next->name:NULL);
	return (next);
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
	if (infos->end->ants != infos->fourmis)
		move_ants(infos, buffer);
}
