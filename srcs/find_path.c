/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:12:07 by llopez            #+#    #+#             */
/*   Updated: 2018/12/19 17:22:31 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_path(t_tube *room, t_infos *infos, t_tube *from, int nb)
{
	t_paths	*tmp;
	int	ret;
	int	total;

	if (room == infos->start)
		return (1);
	tmp = room->links;
	ret = 0;
	total = 0;
	room->vu = 1;
	printf("%s\n", room->name);
	tmp = room->links;
	while (tmp)
	{
		if (!tmp->room->vu && tmp->room != from && (ret = find_path(tmp->room, infos, room, nb + 1)))
		{
			total += ret;
			if (room != infos->end)
			{
				room->steps = (room->steps > nb || !room->steps) ? nb : room->steps;
				return (1);
			}
		}
		tmp = tmp->next;
	}
	return (total);
}
