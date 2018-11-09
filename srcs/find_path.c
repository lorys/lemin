/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:12:07 by llopez            #+#    #+#             */
/*   Updated: 2018/11/09 20:23:53 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		find_path(t_tube *room, t_infos *infos, t_tube *from, t_tube *paths)
{
	int	i;
	int	ret;
	int	found;

	found = 0;
	i = 0;
	ret = 0;
	if (room == infos->end)
		return (1);
	room->vu = 1;
	while (room->links && room->links[i])
	{
		if (room->links[i] == infos->end)
		{
			if (paths != NULL)
				paths->links = realloc_links(paths, room->links[i]);
			return (1);
		}
		if ((room->links[i] == from || room->links[i]->vu == 1) && ++i)
			continue;
		printf("checking ->%s\n", room->links[i]->name);
		if (found > 0 && paths)
		{
			ret = find_path(room->links[i], infos, room, NULL);
			if (ret)
			{
				printf("\t\tUN AUTRE CHEMIN\n");
				save_room(&paths, NULL, 0, 0);
				find_path(room->links[i], infos, room, paths);
				paths->links = realloc_links(paths, room->links[i]);
				found++;
			}
		}
		else
		{
			printf("\tno other way found yet.\n");
			ret = find_path(room->links[i], infos, room, paths);
			if (ret)
			{
				found++;
				if (paths != NULL)
					paths->links = realloc_links(paths, room->links[i]);
			}
		}
		i++;
	}
	printf("paths found in %s : %d\n", room->name, found);
	if (found > 1)
		room->vu = 0;
	return (found);
}
