/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:08:59 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/19 16:47:56 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "common.h"
#include "algo.h"

static void	backtrack(t_infos *infos)
{
	unsigned int v;
	unsigned int u;

	v = infos->end->id;
	while (v != infos->start->id)
	{
		u = infos->parent_array[v];
		write_matrix(infos->residual_matrix, 1, u, v);
		write_matrix(infos->residual_matrix, -1, v, u);
		v = u;
	}
}

int			edmonds_karp(t_infos *infos)
{
	unsigned int	flow;
	t_solution		*solution;

	solution = NULL;
	flow = 0;
	while (42)
	{
		if (!bfs(infos, infos->residual_matrix, infos->parent_array))
			break ;
		flow++;
		backtrack(infos);
		solution = get_paths(infos->residual_matrix, flow, infos);
		if (solution->total_size > (size_t)infos->nb_ants)
			break ;
	}
	if (!solution)
		display_error(infos);
	show_output(solution, infos->nb_ants, infos->rounds);
	return (1);
}
