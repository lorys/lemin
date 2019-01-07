/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 05:43:04 by llopez            #+#    #+#             */
/*   Updated: 2019/01/07 20:08:18 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "struct/infos.h"
#include "struct/tube.h"
#include "struct/path.h"

# define BUFFER_SIZE 5000

t_tube			*find_room(char *room_name, t_tube *room_list);
void			init_infos(t_infos *infos);
int				make_line(t_paths *path_list, t_infos *infos, int ant);
void			find_paths(t_infos *infos);

#endif
