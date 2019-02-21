/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vizu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 05:40:31 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/21 19:14:04 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>
#include "libft.h"
#include "common.h"
#include "parser.h"
#include "visualizer.h"

static void		set_real_position(t_vertice *room_list, t_anthill *anthill, \
				int *height, int *width)
{
	*height -= *height * 0.1;
	*width -= *width * 0.1;
	while (room_list)
	{
		room_list->x = ((*width * room_list->x) + *width * 0.2) / (anthill->max_x);
		room_list->y = ((*height * room_list->y) + *height * 0.2) / (anthill->max_y);
		room_list = room_list->next;
	}
}

static void		display_room_name(t_vertice *room, int color)
{
	attron(A_BOLD);
	attron(COLOR_PAIR(color));
	mvprintw(room->y, room->x - ((ft_strlen(room->name) + 2) / 2), \
		"[%.5s]", room->name);
	attroff(COLOR_PAIR(color));
	attroff(A_BOLD);
}

static void		display_map(t_vertice *room, t_infos *infos)
{
	t_path		*link;

	if (room)
	{
		link = room->links;
		while (link)
		{
			plot_line(room->x, room->y, link->room->x, link->room->y);
			link = link->next;
		}
		display_map(room->next, infos);
		display_room_name(room, room == infos->start || room == infos->end ? 21 : 20);
	}
}

static void		launch(t_vertice *room_list, t_infos *infos)
{
	int			screen_height;
	int			screen_width;
	t_anthill	anthill;

	init_anthill(&anthill, room_list);
	getmaxyx(stdscr, screen_height, screen_width);
	set_real_position(room_list, &anthill, &screen_height, &screen_width);
	display_map(room_list, infos);
}

int				main(void)
{
	t_infos		infos;

	init_infos(&infos);
	read_file(&infos);
	if (!infos.room_list)
		return (EXIT_FAILURE);
	initscr();
	noecho();
	curs_set(0);
	init_colors();
	launch(infos.room_list, &infos);
	free_everything(&infos);
	refresh();
	sleep(1000);
	endwin();
	return (EXIT_SUCCESS);
}
