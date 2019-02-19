/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:07:00 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/19 16:38:23 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

#include <stdint.h>
#include <stddef.h>
#include "struct/infos.h"

typedef struct		s_solution
{
	struct s_path	**paths;
	size_t			*path_size;
	size_t			total_size;
	size_t			nb_paths;
}					t_solution;

typedef struct		s_queue
{
	unsigned int	value;
	struct s_queue	*next;
}					t_queue;

int					bfs(t_infos *infos, uint32_t **residual_matrix, int *parent);
int					edmonds_karp(t_infos *infos);

t_solution			*get_paths(uint32_t **matrix, size_t path_counter, t_infos *infos);
void				show_output(t_solution *solution, size_t nb_ants, int display_rounds);

#endif