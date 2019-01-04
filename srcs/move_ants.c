/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:03:15 by llopez            #+#    #+#             */
/*   Updated: 2018/12/19 17:40:27 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_tube	*whereis(int ants, t_infos *infos)
{
	t_tube	*tmp;
	int	ants_moving;

	ants_moving = 0;
	tmp = infos->start;
	if (infos->end->ants >= ants)
		return (infos->end);
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		printf("have %d want %d\n", tmp->ants, ants);
		if (tmp != infos->start && tmp != infos->end && tmp->ants)
			ants_moving++;
		if (tmp != infos->start && tmp != infos->end && tmp->ants == ants)
			return (tmp);
		tmp = tmp->next;
	}
	if (ants > (ants_moving + infos->end->ants))
		return (infos->start);
	return (NULL);
}

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
		ft_printf("\033[41mL%d-%s\033[0m", l + 1, room->name);
	else if (infos->bonus)
		ft_printf("\033[%dmL%d-%s\033[0m", l, l + 1, room->name);
	else
	{
		tmp = ft_itoa(l + 1);
		fill_buffer("L", buffer, 0, infos);
		fill_buffer(tmp, buffer, 0, infos);
		fill_buffer("-", buffer, 0, infos);
		fill_buffer(room->name, buffer, 0, infos);
		free(tmp);
	}
}

static t_tube		*change_room(int l, t_infos *infos)
{
	t_tube	*new_room;
	t_tube	*from;
	t_tube	*minus;
	t_paths	*tmp;

	new_room = NULL;
	minus = NULL;
	from = whereis(l, infos);
	if (from == infos->end || from == NULL)
		return (NULL);
	tmp = (from) ? from->links : NULL;
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	if (from && from->links != tmp)
		from->links = tmp;
	while (tmp)
	{
		if (tmp->room == infos->end)
		{
			minus = infos->end;
			break;
		}
		if ((!minus || (tmp->room->steps < minus->steps && tmp->room->steps > 0))\
			&& tmp->room->steps > 0\
			&& !tmp->room->ants && tmp->room != infos->start)
			minus = tmp->room;
		tmp = tmp->next;
	}
	new_room = minus;
	if (new_room && ((new_room->steps > 0 && !new_room->ants) || new_room == infos->end))
	{
		if (new_room != infos->end && new_room != infos->start)
			new_room->ants = l;
		else if (new_room == infos->end)
			infos->end->ants++;
		if (from == infos->start)
			infos->start->ants--;
		else
			from->ants = 0;
		return (new_room);
	}
	return (NULL);
}

void			move_ants(t_infos *infos, char *buffer)
{
	int		i;
	int		ants_moved;
	t_tube		*next;

	next = NULL;
	ants_moved = 0;
	i = infos->end->ants;
	while (i < infos->fourmis)
	{
		if ((next = change_room((i + 1), infos)))
		{
			if (ants_moved++)
				fill_buffer(" ", buffer, 0, infos);
			show_ant(i, next, infos, buffer);
		}
		i++;
	}
	if (infos->end->ants < infos->fourmis)
	{
		infos->rounds++;
		fill_buffer("\n", buffer, 0, infos);
		move_ants(infos, buffer);
	}
}
