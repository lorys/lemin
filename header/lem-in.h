/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:12:06 by llopez            #+#    #+#             */
/*   Updated: 2018/11/07 19:26:32 by llopez           ###   ########.fr       */
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
	struct s_tube	**links; 
	struct s_tube	*next;
	struct s_tube	*prev;
}				t_tube;

typedef	struct	s_infos { 
	struct s_tube	*end;
	struct s_tube	*start;
	int				fourmis;
}				t_infos;

t_tube		**realloc_links(t_tube *tube, t_tube *add);
int			find_path(t_tube *room, t_infos *infos, t_tube *from, int steps);
t_tube		*find_room(char *name, t_tube **list);
void		make_tube(char *line, t_tube *tube);
void		save_end(t_tube **tube, t_infos *infos);
void		save_room(t_tube **tube, char **split_tmp);
void		save_start(t_tube **tube, t_infos *infos);
void		show_struct(t_tube **tube);
int			read_stdin(t_tube *tube, t_infos *infos);
t_tube		*toend(t_tube *tube);

#endif
