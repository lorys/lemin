/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:12:07 by llopez            #+#    #+#             */
/*   Updated: 2018/11/06 22:12:23 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		find_path(t_tube *room, t_infos *infos, t_tube *from)
{
	int steps;
	int	i;
	int ret;
	int	y;

	y = 0;
	ret = 0;
	i = 0;
	steps = 1;
	room->vu = 1;
	if (room == infos->end)
		return (1);
	while (room->links && room->links[i])
	{
		if ((room->links[i] == from || room->links[i]->vu == 1) && ++i)
			continue;
		printf("on test %s[%d] = %s\n", room->name, i, room->links[i]->name);
		if ((ret = find_path(room->links[i], infos, room)))
		{
			printf(">>>%s\n", room->links[i]->name);
			steps += ret;
		}
		i++;
	}
	return (0);
}
