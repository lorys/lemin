/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:08:59 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/17 20:33:00 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"
#include "algo.h"

#include <stdio.h>

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

static int	find_capacity(t_solution *solution, size_t nb_ants)
{
	size_t		capacity;
	size_t		i;

	capacity = 0;
	i = 0;
	solution->capacity = 0;
	if (solution->nb_paths == 1 && nb_ants == 1)
		return (1);
	while (i + 1 < solution->nb_paths)
	{
		capacity += (solution->path_size[i + 1] - solution->path_size[0]); 
		i++;
	}
	solution->capacity = capacity;
	return (capacity >= (nb_ants / solution->nb_paths) ? 1 : 0);
}

//debug
static void	print_path(t_path *path)
{
	printf("Path: ");
	while (path)
	{
		printf("%s ", path->room->name);
		path = path->next;
	}
	printf("\n");
}

static void		show_solution(t_solution *solution)
{
	unsigned int	x;

	x = 0;
	printf("\nSolution: nb_paths %zu | capacity: %zu\n", solution->nb_paths, solution->capacity);
	while (x < solution->nb_paths)
	{
		printf("Path size: %5zu | ", solution->path_size[x]);
		print_path(solution->paths[x]);
		x++;
	}
	printf("\n");
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
		if (find_capacity(solution, infos->nb_ants))
		{
			printf("\nSelected solution\n\n");
			show_solution(solution);
			break ;
		}
		show_solution(solution);
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
	free((*solutionp)->nb_ants);
	free(*solutionp);
	*solutionp = NULL;
}
