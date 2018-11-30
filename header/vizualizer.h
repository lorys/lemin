#ifndef VIZUALIZER_H
# define VIZUALIZER_H

# include "lem_in.h"

typedef struct s_anthill
{
	int			min_y;
	int			max_y;
	int			min_x;
	int			max_x;
	int			height;
	int			width;
}				t_anthill;

int				parse(t_tube *tube, t_infos *infos);
void			plot_line(int x0, int y0, int x1, int y1);

#endif