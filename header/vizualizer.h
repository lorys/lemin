/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 05:36:06 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/30 05:36:07 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZUALIZER_H
# define VIZUALIZER_H

# include "lem_in.h"

typedef struct	s_anthill
{
	int			min_y;
	int			max_y;
	int			min_x;
	int			max_x;
	int			height;
	int			width;
}				t_anthill;

typedef struct	s_ant
{
	int			name;
	t_tube		*current_room;
}				t_ant;

int				parse(t_tube **room_listp, t_infos *infos);
void			plot_line(int x0, int y0, int x1, int y1);

#endif
