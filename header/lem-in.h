/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:12:06 by llopez            #+#    #+#             */
/*   Updated: 2018/11/10 22:14:24 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef	struct	s_tube {
	char			*name;
	int				x;
	int				y;
	int				vu;
	int				to_end;
	struct s_tube	**links; 
	struct s_tube	*next;
	struct s_tube	*prev;
}				t_tube;

typedef	struct	s_infos {
	struct s_tube	*end;
	struct s_tube	*start;
	int				fourmis;
}				t_infos;

typedef	struct	s_paths {
	struct s_tube	**steps; 
	struct s_tube	**base;
}				t_paths;

t_tube		**realloc_links(t_tube *tube, t_tube *add);
t_tube		**realloc_paths(t_paths *tube, t_tube *add);
int			find_path(t_tube *room, t_infos *infos, t_tube *from, t_paths *paths);
t_tube		*find_room(char *name, t_tube **list);
void		make_tube(char *line, t_tube *tube);
int			save_end(t_tube **tube, t_infos *infos);
void		save_room(t_tube **tube, char *name, int x, int y);
int			save_start(t_tube **tube, t_infos *infos);
void		show_struct(t_tube **tube);
int			read_stdin(t_tube *tube, t_infos *infos);
t_tube		*toend(t_tube *tube);
int			ft_tubelen(t_tube *len);
int			check_room(char *line);
int			ft_strisdigit(char *str);
int			ft_tubelen(t_tube *len);

#endif
