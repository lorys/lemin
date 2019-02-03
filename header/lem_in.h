/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 05:43:04 by llopez            #+#    #+#             */
/*   Updated: 2019/02/04 00:35:40 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define DEBUG 1
# define BUFFER_SIZE 5000

typedef	struct	s_paths {
	struct s_paths	*next;
	struct s_paths	*prev;
	struct s_tube	*room;
}				t_paths;

typedef	struct	s_tube {
	char			*name;
	int				x;
	int				y;
	int				vu;
	int				ants;
	int				steps;
	int				already_moved;
	int				passages;
	int				pass;
	struct s_paths	*links;
	struct s_tube	*next;
	struct s_tube	*prev;
}				t_tube;

typedef	struct	s_infos {
	struct s_tube	*end;
	struct s_tube	*start;
	int				fourmis;
	int				bonus;
	int				select;
	int				bonusants;
	int				room_total;
	int				rounds;
	int				round_bonus;
	int				radius;
	int				ret_minus;
}				t_infos;

typedef	struct	s_next {
	struct s_tube	*room;
	int				steps;
}				t_next;

t_tube			*to_base(t_tube *base);
void			show_ant(int l, t_tube *room, t_infos *infos, char *buffer);
void			fill_buffer(const char *str, char *buffer, int print,\
		t_infos *infos);
int				check_start(t_paths *tmp, t_infos *infos);
int				visitable(t_paths *tmp, t_tube *room, t_infos *infos, int nb);
int				voyager(t_tube *room, t_tube *from, t_infos *infos, int nb);
t_tube			*found_next(t_tube *next, t_next *possible, t_next *shortest);
void			realloc_paths(t_paths *tube, t_tube *add);
int				find_path(t_infos *infos);
t_tube			*find_room(char *room_name, t_tube *room_list);
void			fill_buffer(const char *str, char *buffer, int print,\
		t_infos *infos);
void			make_tube(char *line, t_tube *room_list);
void			show_struct(t_tube **tube);
int				read_stdin(t_tube **room_listp, t_infos *infos);

t_tube			*toend(t_tube *tube);
int				ft_tubelen(t_tube *len);
int				ft_strisdigit(char *str);
void			move_ants(t_infos *infos, char *buffer);
void			free_char_tab(char **str);
void			free_everything(t_tube *tube, t_infos *infos);
void			free_list(t_tube *list);
void			set_research(t_infos *infos, t_tube *tube);
void			display_error(t_tube *tube, t_infos *infos);
int				ft_stris(char *str, int (*f)(int c));
int				ft_strisnumber(char *str);
void			set_infos(t_infos *infos);
void			set_paths(t_paths *paths);

#endif
