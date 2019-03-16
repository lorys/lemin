/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 05:36:06 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/16 18:07:05 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "struct/infos.h"
# include "struct/vertice.h"
# include "struct/path.h"

typedef struct			s_anthill
{
	int					min_y;
	int					max_y;
	int					min_x;
	int					max_x;
	int					height;
	int					width;
}						t_anthill;

void					init_anthill(t_anthill *anthill, t_vertice *rooms);
void					init_colors(void);

int						parse(t_vertice **room_listp, t_infos *infos);
void					plot_line(int x0, int y0, int x1, int y1);

#endif
