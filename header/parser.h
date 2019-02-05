/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 05:35:58 by pcarles           #+#    #+#             */
/*   Updated: 2019/01/05 19:07:44 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct/tube.h"
# include "struct/infos.h"

# define STATE_ROOMS 1
# define STATE_TUBES 2
# define STATE_START_ROOM 3
# define STATE_END_ROOM 4

void			read_stdin(t_tube **room_listp, t_infos *infos);
int				line_is_valid(t_tube **room_listp, t_infos *infos, \
				char *line, int nline);
t_tube			*is_room_valid(char *line, t_tube *room_list, int nline);
int				is_tube_valid(char *line, t_tube *room_list, int nline);
int				save_room_if_valid(char *line, t_tube **rooms, t_infos *infos, int nline);
int				save_tube_if_valid(char *line, t_tube *rooms, int nline);
t_tube			*create_room(char *name, int x, int y);
void			append_room(t_tube **room_listp, t_tube *room);
void			make_tube(char *line, t_tube *room_list);
long			ft_atoi_long(char const *s);
int				check_overflow(char *str);
void			warn_parsing(char *str, int nline);
void			error_parsing(char *str, int nline);
int				count_char(char *str, char c);

#endif
