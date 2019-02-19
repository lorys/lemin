/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:59:42 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/19 15:52:17 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdint.h>
# include "struct/infos.h"
# include "struct/vertice.h"
# include "struct/path.h"
# include "struct/map.h"

# define DEBUG 1

typedef struct	s_solution
{
	struct s_path	**paths;
	size_t			*path_size;
	size_t			total_size;
	size_t			nb_paths;
}				t_solution;

int				ft_stris(char *str, int (*f)(int c));
int				ft_strisnumber(char *str);

void			free_everything(t_infos *infos);
void			free_char_tab(char **str);

void			display_error(t_infos *infos);
int				count_edges(t_vertice	*room);
void			print_debug(t_infos *infos);

int				create_matrix(uint32_t ***matrixp, size_t size);
void			copy_matrix(uint32_t **dst, uint32_t **src, size_t size);
int				write_matrix(uint32_t **matrix, int value, unsigned int x, unsigned int y);
int				read_matrix(uint32_t **matrix, unsigned int x, unsigned int y);
void			print_matrix(uint32_t **matrix, size_t size);
t_vertice		*find_room_by_id(unsigned int id, t_vertice *room_list);

t_solution		*get_paths(uint32_t **matrix, size_t path_counter, t_infos *infos);
void			show_output(t_solution *solution, size_t nb_ants, int display_rounds);

#endif