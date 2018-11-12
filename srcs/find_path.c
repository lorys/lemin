/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:12:07 by llopez            #+#    #+#             */
/*   Updated: 2018/11/12 06:15:39 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_every_path(t_tube *room, t_paths *paths, t_infos *infos,\
		t_tube *from)
{
	int	i;
	int found;

	found = 0;
	i = 0;
	while (room->links && room->links[i])
	{
		if ((room->links[i]->vu || room->links[i] == from) && ++i)
			continue;
		if (find_path(room->links[i], infos, room, paths))
		{
			found++;
			paths->steps = realloc_paths(paths, room);
			if (room->links[i + 1])
				paths->steps = realloc_paths(paths, from);
		}
		i++;
	}
	return (found);
}

static int	check_links_end(t_tube *room, t_infos *infos, t_paths *paths)
{
	int i;

	i = 0;
	while (room->links && room->links[i])
	{
		if (room->links[i] == infos->end)
		{
			paths->steps = realloc_paths(paths, room->links[i]);
			paths->steps = realloc_paths(paths, room);
			room->vu = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

int			find_path(t_tube *room, t_infos *infos, t_tube *from, \
		t_paths *paths)
{
	int	i;
	int	found;
	int	b;

	found = 0;
	i = 0;
	b = 0;
	if (room == infos->end)
	{
		paths->steps = realloc_paths(paths, room);
		return (1);
	}
	room->vu = 1;
	if (check_links_end(room, infos, paths))
		return (1);
	found = check_every_path(room, paths, infos, from);
	room->vu = (found > 0) ? 0 : room->vu;
	return (found);
}
