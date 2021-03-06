/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 05:35:58 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/16 18:07:10 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct/vertice.h"
# include "struct/infos.h"

# define STATE_ROOMS 1
# define STATE_TUBES 2
# define STATE_START_ROOM 3
# define STATE_END_ROOM 4
# define STATE_START 5

# define PARSER_VERBOSITY 1
# define LI_BUFFER_SIZE 65536

int					line_is_valid(t_vertice **room_listp, t_infos *infos, \
					char *line, int nline);
t_vertice			*is_room_valid(char *line, t_vertice *room_list, int nline);
int					is_tube_valid(char *line, t_vertice *room_list, int nline);
int					save_room_if_valid(char *line, t_vertice **rooms, \
					t_infos *infos, int nline);
int					save_tube_if_valid(char *line, t_vertice *rooms, \
					t_infos *infos, int nline);
t_vertice			*create_room(char *name, int x, int y);
void				append_room(t_vertice **room_listp, t_vertice *room);
void				make_tube(char *line, t_vertice *room_list, t_infos *infos);
long				ft_atoi_long(char const *s);
int					check_overflow(char *str);
void				warn_parsing(char *str, int nline);
void				error_parsing(char *str, int nline);
int					count_char(char *str, char c);

int					read_file(t_infos *infos);
void				fill_buffer(char *str);
unsigned int		count_room(t_vertice *room_list);

#endif
