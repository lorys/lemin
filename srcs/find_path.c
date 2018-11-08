/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:12:07 by llopez            #+#    #+#             */
/*   Updated: 2018/11/08 18:41:40 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		find_path(t_tube *room, t_infos *infos, t_tube *from, t_tube *paths)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (room == infos->end)
		return (1);
	room->vu = 1;
	while (room->links[i])
	{
		if ((room->links[i] == from || room->links[i]->vu == 1) && ++i)
			continue;
		printf("checking ->%s\n", room->links[i]->name);
		ret = find_path(room->links[i], infos, room, paths);
		if (ret == 1)
		{
			paths->links = realloc_links(paths, room->links[i]);
			ret++;
		}
		i++;
	}
	if (ret)
		return (2);
	return (0);
}
