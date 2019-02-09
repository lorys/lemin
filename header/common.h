/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:59:42 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/09 17:40:48 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "struct/infos.h"
# include "struct/vertice.h"
# include "struct/path.h"
# include "struct/map.h"

# define DEBUG 1

int				ft_stris(char *str, int (*f)(int c));
int				ft_strisnumber(char *str);
void			free_everything(t_vertice *tube);
void			free_map(t_map *map);
void			free_char_tab(char **str);
void			display_error(t_vertice *tube);
int				count_edges(t_vertice	*room);
void			print_debug(t_infos *infos);

int				create_matrix(t_infos *infos);
void			free_matrix(uint32_t **adjacency_matrix, unsigned int size);
int				write_matrix(t_infos *infos, unsigned int x, unsigned int y);
int				read_matrix(t_infos *infos, unsigned int x, unsigned int y);
void			print_matrix(t_infos *infos);

#endif