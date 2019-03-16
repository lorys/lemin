/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:08:59 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/16 21:25:05 by pcarles          ###   ########.fr       */
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
	// if (solution->nb_paths == 1 && solution->path_size[0] > nb_ants)
	// 	return (1);
	while (i + 1 < solution->nb_paths)
	{
		capacity += (solution->path_size[i + 1] - solution->path_size[i]) * (i + 1); 
		i++;
	}
	solution->capacity = capacity;
	return (capacity > (nb_ants / solution->nb_paths) ? 1 : 0);
}

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
	//t_solution		*last_solution;

	solution = NULL;
	//last_solution = NULL;
	flow = 0;
	while (42)
	{
		if (!bfs(infos, infos->residual_matrix, infos->parent_array))
			break ;
		if (solution != NULL)
			free_solution(&solution);
		flow++;
		backtrack(infos);
		//last_solution = solution;
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
	free(*solutionp);
	*solutionp = NULL;
}


// int         diff_between_path(t_tab_path *tab, int i)
// {
//     int difference;
//     difference = 0;
//     while (tab->prev != NULL)
//         tab = tab->prev;
//     while (i-- > 0 && tab->next)
//         tab = tab->next;
//     if (tab->next)
//         difference = tab->next->path_size - tab->path_size;
//     else
//         difference = -1;
//     return (difference);
// }
// int         ft_nb_path(t_all elem, t_tab_path *tab, int i, int capacity)
// {
//     int nb_ant;
//     nb_ant = elem.number_ants;
//     if (diff_between_path(tab, i - 1) != -1)
//         capacity = capacity + (diff_between_path(tab, i) * i);
//     else
//         return (i);
//     if (capacity > nb_ant)
//         return (i);
//     else
//     {
//         i++;
//         return (ft_nb_path(elem, tab, i, capacity));
//     }
// }