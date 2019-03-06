/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 05:43:04 by llopez            #+#    #+#             */
/*   Updated: 2019/02/03 16:24:18 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "struct/infos.h"
#include "struct/tube.h"
#include "struct/path.h"

# define BUFFER_SIZE 4096

typedef enum	e_status
{
	STATUS_OK = 0,
	STATUS_DEAD_END,
	STATUS_VISITED
}				t_status;

t_tube			*last_path(t_infos *infos);
t_tube			*choose_ants(t_tube *room, t_infos *infos);
int			path_length(t_tube *room, t_infos *infos);
t_tube			*minus_available(t_tube *room, t_infos *infos);
t_tube			*minus_path(t_infos *infos, int noants);
t_tube			*next_step_path(t_tube *room, int noants,\
				t_infos *infos);
int			ft_linkslen(t_tube *room);
int			bury_path(t_tube *room, t_infos *infos, int nb);
t_tube			*find_room(char *room_name, t_tube *room_list);
void			init_infos(t_infos *infos, t_btu *btu);
int			make_line(t_paths *path_list, t_infos *infos,\
				int ant);
int			find_paths(t_infos *infos);
void			fill_buffer(const char *str, char *buffer, int print,\
				t_infos *infos);
void			show_ant(int l, t_tube *room, t_infos *infos, char *buffer);
int			change_room(t_infos *infos, t_tube *from, t_tube *to, \
				char *buffer);

#endif
