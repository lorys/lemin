/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:59:42 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/20 18:03:25 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdint.h>
# include <stddef.h>
# include "struct/infos.h"
# include "struct/vertice.h"
# include "struct/path.h"

void			init_infos(t_infos *infos);
void			init_algo(t_infos *infos);

int				ft_stris(char *str, int (*f)(int c));
int				ft_strisnumber(char *str);
void			display_error(t_infos *infos);
t_vertice		*find_room(char *room_name, t_vertice *room_list);
t_vertice		*find_room_by_id(unsigned int id, t_vertice *room_list);

int				create_matrix(uint32_t ***matrixp, size_t size);
int				write_matrix(uint32_t **matrix, int value, unsigned int x, \
				unsigned int y);
int				read_matrix(uint32_t **matrix, unsigned int x, unsigned int y);

void			free_everything(t_infos *infos);
void			free_paths(t_path *path_list);
void			free_char_tab(char **str);

#endif
