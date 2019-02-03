/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vizu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 05:40:31 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/04 00:40:03 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>
#include "lem_in.h"
#include "vizualizer.h"

static void		set_real_position(t_tube *room_list, t_anthill *anthill, \
				int *height, int *width)
{
	*height -= *height * 0.1;
	*width -= *width * 0.1;
	while (room_list)
	{
		room_list->x = ((*width * room_list->x) + *width * 0.2) / \
						(anthill->max_x);
		room_list->y = ((*height * room_list->y) + *height * 0.2) / \
						(anthill->max_y);
		room_list = room_list->next;
	}
}

static void		display_map(t_tube *room, t_infos *infos)
{
	t_paths		*link;

	if (room)
	{
		link = room->links;
		while (link)
		{
			plot_line(room->x, room->y, link->room->x, link->room->y);
			link = link->next;
		}
		display_map(room->next, infos);
		attron(A_BOLD);
		if (room == infos->end || room == infos->start)
			attron(COLOR_PAIR(21));
		else
			attron(COLOR_PAIR(20));
		mvprintw(room->y, room->x - (ft_strlen(room->name) + 2) / 2, \
		"[%.5s]", room->name);
		if (room == infos->end || room == infos->start)
			attroff(COLOR_PAIR(21));
		else
			attroff(COLOR_PAIR(20));
		attroff(A_BOLD);
	}
}

static void		launch(t_tube *room_list, t_infos *infos)
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
	t_tube		*room_list;

	room_list = NULL;
	set_infos(&infos);
	parse(&room_list, &infos);
	if (!room_list)
		return (EXIT_FAILURE);
	initscr();
	init_colors();
	launch(room_list, &infos);
	curs_set(0);
	refresh();
	free_everything(room_list, NULL);
	sleep(1000);
	endwin();
	return (EXIT_SUCCESS);
}
