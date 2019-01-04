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
	int	tmpi;

	tmpi = 0;
	ret = 0;
	tmp = (room) ? room->links : NULL;
	(void)from;
	if (room == infos->start)
		return (1);
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		if (tmp->room == infos->start)
			return (1);
		if (tmp->room != from && !tmp->room->vu && (ret += find_path(tmp->room, infos, room, nb+1)))
			tmp->room->steps = (tmp->room->steps > nb || !tmp->room->steps) ? nb : tmp->room->steps;
		tmp->room->vu = 1;
		tmp = tmp->next;
	}
	printf("(return %d)\n", ret);
	return (ret);
}
