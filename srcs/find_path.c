/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:12:07 by llopez            #+#    #+#             */
/*   Updated: 2018/12/17 12:03:06 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	already_saved(t_tube *room, t_paths *paths, t_infos *infos)
{
	t_paths	*tmp;
	int		count;
	int		countc;
	int		found;

	found = 0;
	count = 0;
	countc = 0;
	tmp = paths;
	if (room == infos->end || room == infos->start)
		return (0);
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp->room && tmp->room != infos->end)
	{
		countc++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->room == room)
			found = 1;
		if (tmp->room == infos->end && !found)
		{
			count = 0;
			found = 0;
		}
		else if (tmp->room == infos->end && found && count <= countc)
			return (1);
		else
			count++;
		tmp = tmp->next;
	}
	return (0);
}

static int	check_every_path(t_tube *room, t_paths *paths, t_infos *infos,\
		t_tube *from)
{
	t_paths		*tmp;
	int			found;
	int			ret;

	ret = 0;
	found = 0;
	tmp = room->links;
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		if (tmp->room && (tmp->room->vu || tmp->room == from))
		{
			tmp = tmp->next;
			continue;
		}
		if (find_path(tmp->room, infos, room, paths) && !already_saved(room, paths, infos))
		{
			found++;
			realloc_paths(paths, room);
			if (tmp->next && room->links->next && !already_saved(room, paths, infos))
				realloc_paths(paths, from);
		}
		tmp = tmp->next;
	}
	return (found);
}

static int	check_links_end(t_tube *room, t_infos *infos, t_paths *paths)
{
	t_paths *tmp;

	tmp = room->links;
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		if (tmp->room == infos->end)
		{
			realloc_paths(paths, tmp->room);
			realloc_paths(paths, room);
			room->vu = 0;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int			find_path(t_tube *room, t_infos *infos, t_tube *from, \
			t_paths *paths)
{
	int	found;

	found = 0;
	if (room == infos->end)
	{
		realloc_paths(paths, room);
		return (1);
	}
	room->vu = 1;
	if (check_links_end(room, infos, paths))
		return (1);
	found = check_every_path(room, paths, infos, from);
	room->vu = (found > 0) ? 0 : room->vu;
	return (found);
}
