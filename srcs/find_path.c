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
		room->pass++;
	//printf("from = %s\troom = %s %s\tsteps = %d\tnb = %d\t (%d pass)\n", (from)?from->name:NULL, room->name, (room->vu)?"(VU)":"", room->steps, nb, room->pass);
	tmp = (room) ? room->links : NULL;
	base = tmp;
	while (base && base->prev)
		base = base->prev;
	tmp = base;
	while (tmp)
	{
		if (tmp->room->vu != -1)
			ret = 1;
		if (tmp->room == infos->start)
		{
	//		printf("%s\n", room->name);
			if (!room->steps || room->steps > nb)
				room->steps = nb;
			return (nb);
		}
		tmp = tmp->next;
	}
	if (!ret && room == infos->end)
		printf("%s failed.\n", room->name);
	if (!ret)
		return (0);
	ret = 0;
	tmp = base;
	room->vu = -1;
	//printf("start recursive by %s\n", room->name);
	while (tmp)
	{
		if (tmp->room != from && !tmp->room->vu)
		{
			init = 0;
			if (tmp->room->steps > nb || !tmp->room->steps)
			{
				tmp->room->steps = nb;
				init = find_path(tmp->room, infos, room, nb + 1);
				ret += init;
				if (!init)
				{
					tmp->room->vu = 1;
					tmp->room->steps = 0;
				}
				else if (init - nb == 1)
				{
					room->vu = 0;
					return (1);
				}
			}
	//		if (init)
	//			printf("%s link to start\n", tmp->room->name);
			//printf("\t%s is %d steps from end.\n", tmp->room->name, tmp->room->steps);
		}
		tmp = tmp->next;
	}
	//printf("stop recursive by %s\n", room->name);
	room->vu = 0;
	return ((ret) ? nb : 0);
}
