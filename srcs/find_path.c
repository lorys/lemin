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

int			find_path(t_tube *room, t_infos *infos, t_tube *from, int nb)
{
	t_paths	*tmp;
	int		ret;

	ret = 0;
	tmp = (room) ? room->links : NULL;
	printf("room = %s\n", room->name);
	if (room == infos->start)
		return (1);
	printf("Not start (%s).\n", infos->start->name);
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		if (tmp->room == infos->start)
			return (1);
		printf("checking = %s\n", tmp->room->name);
		if (tmp->room != from && !tmp->room->vu && (ret += find_path(tmp->room, infos, room, nb+1)))
		{
			tmp->room->steps = nb;
			printf("\tsteps saved for %s : %d\n", tmp->room->name, tmp->room->steps);
			tmp->room->vu = 1;
		}
		tmp = tmp->next;
	}
	return (ret);
}
