/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_output2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 10:41:46 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/17 18:05:53 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct/path.h"
#include "algo.h"

#include <stdio.h>

void		calculate_ants(t_solution *solution, size_t nb_ants)
{
	size_t	i;
	size_t	check;
	size_t	issou;

	i = 0;
	check = 0;
	while (i < solution->nb_paths)
	{
		solution->nb_ants[i] = ((nb_ants - solution->capacity) / solution->nb_paths) + (solution->path_size[solution->nb_paths - 1 - i] - solution->path_size[0]);
		i++;
	}
	issou = (nb_ants - solution->capacity) % solution->nb_paths;
	while (issou--)
		solution->nb_ants[issou] += 1;
	i = 1;
	solution->path_size[0] = 1;
	printf("path %zu: size: %zu nb_ants: %zu\n", i, solution->path_size[0], solution->nb_ants[0]);
	while (i < solution->nb_paths)
	{
		solution->path_size[i] = solution->nb_ants[i - 1] + 1;
		solution->nb_ants[i] += solution->nb_ants[i - 1];
		printf("path %zu: size: %zu nb_ants: %zu\n", i, solution->path_size[i], solution->nb_ants[i]);
		check += solution->nb_ants[i];
		i++;
	}
	if (check == nb_ants)
		printf("INCORYABLE DU CUL\n");
	else
		printf("pas ouf du cul: nb_ants: %zu, check: %zu\n", nb_ants, check);
}

unsigned int	get_next_ant(t_solution *solution, t_path *path)
{
	size_t		i;
	t_path		*tmp;

	i = 0;
	while ((tmp = solution->paths[i]) != path)
		i++;
	if (solution->path_size[i] >= solution->nb_ants[i] + 1)
		return (0);
	return ((unsigned int)solution->path_size[i]++);
}

t_path		*get_next_path(t_solution *solution)
{
	static size_t	last_path = 0;

	if (last_path >= solution->nb_paths)
		last_path = 0;
	return (solution->paths[last_path++]);
}
