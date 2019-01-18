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

int		ft_tubelena(t_tube *room)
{
	int	len;

	len = 0;
	while (room && room->prev)
		room = room->prev;
	while (room)
	{
		len++;
		room = room->next;
	}
	return (len);
}

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
	//printf("from = %s\troom = %s %s\tsteps = %d\tnb = %d\n", (from)?from->name:NULL, room->name, (room->vu)?"(VU)":"", room->steps, nb);
	tmp = (room) ? room->links : NULL;
	base = tmp;
	while (base && base->prev)
		base = base->prev;
	tmp = base;
	while (tmp)
	{
		if (tmp->room == infos->start)
		{
	//		printf("%s\n", tmp->room->name);
			if (!room->steps || room->steps > nb)
				room->steps = nb;
			return (nb);
		}
		tmp = tmp->next;
	}
	tmp = base;
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
					tmp->room->steps = 0;
				else if (init-nb == 1)
					return (1);
			}
			/*if (init)
				printf("%s link to start\n", tmp->room->name);*/
			//printf("\t%s is %d steps from end.\n", tmp->room->name, tmp->room->steps);
		}
		tmp = tmp->next;
	}
	return ((ret) ? nb : 0);
}
