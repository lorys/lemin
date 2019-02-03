/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:12:07 by llopez            #+#    #+#             */
/*   Updated: 2019/02/03 10:54:29 by llopez           ###   ########.fr       */
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

	if (room->passages > 20000)
		return (0);
	ret_minus = 0;
	total = 0;
	tmp = room->links;
	room->passages++;
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
		if ((infos->radius > nb || !infos->radius)\
			&& tmp->room != infos->end && (!tmp->room->vu || tmp->room->pass > nb)\
			&& !tmp->room->steps && tmp->room != from \
			&& (ret = voyager(tmp->room, room, infos, nb + 1)))
		{
			if (ret == nb+1)
				infos->radius = ret;
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
	minus_room->pass = nb+1;
	return (ret_minus);
}

int			set_position(t_tube *room, t_tube *from, t_infos *infos, int nb)
{
	t_paths	*links;

	links = room->links;
	while (links)
	{
		if (links->room == infos->start)
		{
			room->steps = (!room->steps || room->steps > nb) ? nb : room->steps;
			return (1);
		}
		links = links->next;
	}
	room->vu = 2;
	links = room->links;
	while (links)
	{
		if (links->room != from && links->room->pass == nb+1 && links->room->vu != 2)
		{
			if (set_position(links->room, room, infos, nb + 1))
			{
				room->steps = (!room->steps || room->steps > nb) ? nb : room->steps;
				return (1);
			}
		}
		links = links->next;
	}
	return (0);
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
		total++;
		links = links->next;
	}
	printf("%d links to end\n", total);
	total = 0;
	links = infos->end->links;
	ret = 0;
	while (links)
	{
		infos->radius = 0;
		if (total >= ft_tubelen(infos->start))
			break;
		if (links->room == infos->start)
			total++;
		if ((ret = voyager(links->room, infos->end, infos, 1)))
		{
			printf("voyager = %d\n", ret);
			total++;
			set_position(links->room, infos->end, infos, 1);
		}
		else
		{
			printf("\tpaths not found by %s\n", links->room->name);
		}
		reset_view(infos->start);
		links = links->next;
	}
	return (total);
}
