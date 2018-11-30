/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 05:43:04 by llopez            #+#    #+#             */
/*   Updated: 2018/11/30 04:03:37 by llopez           ###   ########.fr       */
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

# define DEBUG 0

typedef	struct	s_tube {
	char			*name;
	int				x;
	int				y;
	int				vu;
	int				ants;
	struct s_tube	**links;
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
}				t_infos;

typedef	struct	s_paths {
	struct s_paths		*next;
	struct s_paths		*prev;
	struct s_tube		*room;
}				t_paths;

typedef	struct	s_next {
	struct s_tube	*room;
	int				steps;
}				t_next;

void			free_paths(t_paths *paths);
t_tube			**realloc_links(t_tube *tube, t_tube *add);
void			realloc_paths(t_paths *tube, t_tube *add);
int				find_path(t_tube *room, t_infos *infos, t_tube *from,\
			t_paths *paths);
t_tube			*find_room(char *name, t_tube **list);
int				make_tube(char *line, t_tube *tube);
int				save_room(t_tube **tube, char *name, int x, int y);
void			show_struct(t_tube **tube);
int				read_stdin(t_tube *tube, t_infos *infos);
t_tube			*toend(t_tube *tube);
int				ft_tubelen(t_tube *len);
int				ft_strisdigit(char *str);
int				ft_tubelen(t_tube *len);
void			move_ants(t_paths *paths, t_infos *infos, t_tube **ants);
int				set_ants(t_infos *infos, t_tube ***ants);
void			free_char_tab(char **str);
void			free_everything(t_tube *tube, t_infos *infos, t_paths *paths,\
			t_tube **ants);
void			free_list(t_tube *list);
void			set_research(t_infos *infos, t_paths *paths, t_tube **ants,\
			t_tube *tube);
void			set_tube(t_tube *tube);
void			display_error(t_tube *tube, t_paths *paths, t_infos *infos,\
			t_tube **ants);
t_tube			*get_shortest_path(t_paths *paths, t_tube *from,\
			t_infos *infos);
int				ft_strisdigit(char *str);
int				int_free(void *data);
void			set_infos(t_infos *infos);
void			set_paths(t_paths *paths);

#endif
