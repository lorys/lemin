/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:59:42 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/15 16:33:29 by pcarles          ###   ########.fr       */
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
	size_t			nb_paths;
}				t_solution;

int				ft_stris(char *str, int (*f)(int c));
int				ft_strisnumber(char *str);
void			free_everything(t_vertice *tube);
void			free_map(t_map *map);
void			free_char_tab(char **str);
void			display_error(t_vertice *tube);
int				count_edges(t_vertice	*room);
void			print_debug(t_infos *infos);

int				create_matrix(uint32_t ***matrixp, size_t size);
void			copy_matrix(uint32_t **dst, uint32_t **src, size_t size);
void			free_matrix(uint32_t **adjacency_matrix, size_t size);
int				write_matrix(uint32_t **matrix, int value, unsigned int x, unsigned int y);
int				read_matrix(uint32_t **matrix, unsigned int x, unsigned int y);
void			print_matrix(uint32_t **matrix, size_t size);
t_vertice		*find_room_by_id(t_vertice *room_list, unsigned int id);

t_solution		*get_paths(uint32_t **matrix, t_infos *infos);
void			show_output(t_solution *solution, size_t nb_ants);

#endif