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
	t_paths	*base;
	int	ret;
	int	init;

	ret = 0;
	init = 0;
	base = NULL;
	if (room == infos->start)
		return (1);
	printf("from = %s\troom = %s\tsteps = %d\tnb = %d\n", (from)?from->name:NULL, room->name, room->steps, nb);
	tmp = (room) ? room->links : NULL;
	base = tmp;
	while (base && base->prev)
		base = base->prev;
	tmp = base;
	while (tmp)
	{
		if (tmp->room == infos->start)
		{
			if (!room->steps || room->steps > nb)
				room->steps = nb;
			return (1);
		}
		tmp = tmp->next;
	}
	tmp = base;
	while (tmp)
	{
		if (tmp->room->steps && tmp->room->steps < nb && tmp->room->vu)
			return (1);
		if (tmp->room != from && tmp->room != infos->start && tmp->room != from)
		{
			init = find_path(tmp->room, infos, room, nb + 1);
			if (init)
				printf("%s link to start\n", tmp->room->name);
			ret += init;
			if ((!tmp->room->steps || tmp->room->steps > nb) && init)
				tmp->room->steps = nb;
			else if (!ret)
				tmp->room->steps = 0;
			tmp->room->vu = 1;
			printf("\t%s is %d steps from end.\n", tmp->room->name, tmp->room->steps);
		}
		tmp = tmp->next;
	}
	return (ret);
}
