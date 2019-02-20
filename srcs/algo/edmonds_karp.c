/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:08:59 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/20 18:10:39 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

t_solution	*edmonds_karp(t_infos *infos)
{
	unsigned int	flow;
	t_solution		*solution;

	solution = NULL;
	flow = 0;
	while (42)
	{
		if (!bfs(infos, infos->residual_matrix, infos->parent_array))
			break ;
		if (solution != NULL)
			free_solution(&solution);
		flow++;
		backtrack(infos);
		solution = get_paths(infos->residual_matrix, flow, infos);
		if (solution->total_size > (size_t)infos->nb_ants)
			break ;
	}
	return (solution);
}

void		free_solution(t_solution **solutionp)
{
	unsigned int	tmp;

	tmp = 0;
	while (tmp < (*solutionp)->nb_paths)
	{
		free_paths((*solutionp)->paths[tmp]);
		tmp++;
	}
	free((*solutionp)->paths);
	free((*solutionp)->path_size);
	free(*solutionp);
	*solutionp = NULL;
}
