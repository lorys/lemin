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
	tmp = (room) ? room->links : NULL;
	base = tmp;
	while (base && base->prev)
		base = base->prev;
	tmp = base;
	while (tmp)
	{
		if (tmp->room == infos->start)
			return (1);
		tmp = tmp->next;
	}
	tmp = base;
	while (tmp)
	{
		if (!tmp->room->vu && tmp->room != from && (!tmp->room->steps || nb < tmp->room->steps))
		{
			tmp->room->steps = nb;
			printf("\t%s is %d steps from end.\n", tmp->room->name, tmp->room->steps);
		}
		tmp = tmp->next;
	}
	tmp = base;
	while (tmp)
	{
		if (!tmp->room->vu && tmp->room != from && !(init = find_path(tmp->room, infos, room, nb+1)))
		{
			ret += init;
			printf("%s don't go anywhere\n", tmp->room->name);
			tmp->room->steps = 0;
		}
		tmp = tmp->next;
	}
	tmp->room->vu = 1;
	return (ret);
}
