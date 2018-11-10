/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:12:07 by llopez            #+#    #+#             */
/*   Updated: 2018/11/10 22:52:29 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		find_path(t_tube *room, t_infos *infos, t_tube *from, t_paths *paths)
{
	int	i;
	int	ret;
	int	found;
	int	b;

	found = 0;
	i = 0;
	ret = 0;
	b = 0;
	if (room == infos->end)
		return (1);
	room->vu = 1;
	while (room->links && room->links[i])
	{
		if (room->links[i] == infos->end)
		{
			//printf("\t\t%s ->%s\n",room->name, room->links[i]->name);
			room->to_end = 1;
			if (paths)
				paths->steps = realloc_paths(paths, room->links[i]);
			//paths->steps = realloc_paths(paths, room);
			room->vu = 0;
			return (1);
		}
		i++;
	}
	i = 0;
	while (room->links && room->links[i])
	{
		if ((room->links[i]->vu || room->links[i] == from) && ++i)
			continue;
		if ((ret = find_path(room->links[i], infos, room, paths)))
		{
			found++;
			if (paths)
			{
				paths->steps = realloc_paths(paths, room->links[i]);
				b = 0;
				while (room->links[b])
				{
					if (b != i && find_path(room->links[b], infos, room, NULL))
					{
						paths->steps = realloc_paths(paths, room);
						break;
					}
					b++;
				}
			}
		}
		i++;
	}
	//printf("\t\t%s a %d liens vers %s\n", room->name, found, infos->end->name);
	if (found > 0)
		room->vu = 0;
	return (found);
}
