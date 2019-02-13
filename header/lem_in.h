/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 05:43:04 by llopez            #+#    #+#             */
/*   Updated: 2019/02/13 11:47:44 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "struct/infos.h"
#include "struct/vertice.h"
#include "struct/path.h"

typedef enum	e_status
{
	STATUS_OK = 0,
	STATUS_DEAD_END,
	STATUS_VISITED
}				t_status;

t_vertice			*find_room(char *room_name, t_vertice *room_list);
void				init_infos(t_infos *infos);
int					make_line(t_path *path_list, t_infos *infos, int ant);
void				find_paths(t_infos *infos);

int					edmonds_karp(t_infos *infos);

#endif
