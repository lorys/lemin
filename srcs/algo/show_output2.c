/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_output2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 10:41:46 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/17 16:38:01 by pcarles          ###   ########.fr       */
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
		printf("path %zu: size: %zu nb_ants: %zu\n", i, solution->path_size[i], solution->nb_ants[i]);
		check += solution->nb_ants[i];
		i++;
	}
	issou = (nb_ants - solution->capacity) % solution->nb_paths + 1;
	while (issou--)
	{
		printf("issou: %zu\n", issou);
		solution->nb_ants[issou]++;
	}
	if (check == nb_ants)
		printf("INCORYABL DU CUL\n");
	else
		printf("pas ouf du cul: nb_ants: %zu, check: %zu\n", nb_ants, check);
}

t_path		*get_next_path(t_solution *solution)
{
	static size_t	last_path = 0;

	if (last_path >= solution->nb_paths)
		last_path = 0;
	return (solution->paths[last_path++]);
}
