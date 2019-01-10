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
	if (room == infos->start)
		return (1);
	tmp = base;
	printf("\t\t\t%s\n", room->name);
	while (tmp && base->room->links->room != from)
	{
		if (nb < tmp->room->steps)
			tmp->room->steps = nb;
		if (tmp->room != from && (init = find_path(tmp->room, infos, room, nb + 1)))
		{
			ret += init;
			printf("\t%s is %d steps from end.\n", tmp->room->name, tmp->room->steps);
		}
		tmp = tmp->next;
	}
	return (ret);
}
