/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vizu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 23:45:37 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/03 23:53:27 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "vizualizer.h"

void			init_anthill(t_anthill *anthill, t_tube *rooms)
{
	anthill->min_x = rooms->x;
	anthill->max_y = rooms->y;
	anthill->max_x = rooms->x;
	anthill->min_y = rooms->y;
	while (rooms)
	{
		if (rooms->x < anthill->min_x)
			anthill->min_x = rooms->x;
		if (rooms->y < anthill->min_y)
			anthill->min_y = rooms->y;
		if (rooms->x > anthill->max_x)
			anthill->max_x = rooms->x;
		if (rooms->y > anthill->max_y)
			anthill->max_y = rooms->y;
		rooms = rooms->next;
	}
	anthill->height = anthill->max_y - anthill->min_y;
	anthill->width = anthill->max_x - anthill->min_x;
}

void			init_colors(void)
{
	start_color();
	init_pair(20, COLOR_BLUE, COLOR_BLACK);
	init_pair(21, COLOR_GREEN, COLOR_BLACK);
	init_pair(0, COLOR_WHITE, COLOR_RED);
	init_pair(1, COLOR_WHITE, COLOR_GREEN);
	init_pair(2, COLOR_BLACK, COLOR_YELLOW);
	init_pair(3, COLOR_WHITE, COLOR_BLUE);
	init_pair(4, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(5, COLOR_WHITE, COLOR_CYAN);
}
