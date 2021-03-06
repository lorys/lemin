/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:07:00 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/18 16:30:01 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include <stdint.h>
# include <stddef.h>
# include "struct/infos.h"

typedef struct		s_solution
{
	struct s_path	**paths;
	size_t			*path_size;
	size_t			*nb_ants;
	size_t			capacity;
	int				is_start_end;
	size_t			nb_paths;
}					t_solution;

typedef struct		s_queue
{
	unsigned int	value;
	int				check_only_annulable;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_algo
{
	struct s_queue	*queue;
	int				state;
}					t_algo;

int					bfs(t_infos *infos, uint32_t **residual_matrix, \
					int *parent);
t_solution			*edmonds_karp(t_infos *infos);
void				free_solution(t_solution **solutionp);

t_solution			*get_paths(uint32_t **matrix, size_t path_counter, \
					t_infos *infos);
void				show_output(t_solution *solution, \
					int display_rounds, t_infos *infos);
t_path				*get_next_path(t_solution *solution);
void				sort_solution(t_solution *solution);

void				calculate_ants(t_solution *solution, size_t nb_ants);
unsigned int		get_next_ant(t_solution *solution, t_path *path);
void				display_roundsf(int display_rounds, unsigned int rounds);

#endif
