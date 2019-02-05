/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 15:32:02 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/03 17:26:02 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"
#include "common.h"

int		count_edges(t_tube	*room)
{
	int		res;
	t_paths	*tmp;

	res = 0;
	tmp = room->links;
	while (tmp)
	{
		if (tmp->room->vu != STATUS_DEAD_END)
		res++;
		tmp = tmp->next;
	}
	return (res);
}

int		max_paths(t_infos *infos)
{
	int	a;
	int	b;

	a = count_edges(infos->start);
	b = count_edges(infos->end);
	return (a > b ? b : a);
}

void	print_debug(t_infos *infos)
{
	printf("\n\033[36;1mmax_paths: %d\nnb_paths : %d\033[0m\n", max_paths(infos), infos->nb_paths);
}
