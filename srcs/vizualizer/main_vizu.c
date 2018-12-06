/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vizu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 05:40:31 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/30 05:40:32 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>
#include "lem_in.h"
#include "vizualizer.h"

static void		init_anthill(t_anthill *anthill, t_tube *rooms)
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

static void		compute_real_position(t_tube *room_list, t_anthill *anthill, \
				int *height, int *width)
{
	*height -= *height * 0.1;
	*width -= *width * 0.1;
	while (room_list)
	{
		room_list->x = ((*width * room_list->x) / (anthill->max_x)) + (*width * 0.05);
		room_list->y = ((*height * room_list->y) / (anthill->max_y)) + (*height * 0.05);
		room_list = room_list->next;
	}
}

static void		display_map(t_tube *room_list)
{
	t_tube		**links;

	if (room_list)
	{
		links = room_list->links;
		while (links && *links)
		{
			plot_line(room_list->x, room_list->y, (*links)->x, (*links)->y);
			links++;
		}
		display_map(room_list->next);
		attron(A_BOLD);
		attron(COLOR_PAIR(1));
		mvprintw(room_list->y, room_list->x - (ft_strlen(room_list->name) + 2) / 2, \
		"[%.5s]", room_list->name);
		attroff(COLOR_PAIR(1));
		attroff(A_BOLD);
	}
}

static void		draw_map(t_tube *room_list)
{
	int			screen_height;
	int			screen_width;
	t_anthill	anthill;

	init_anthill(&anthill, room_list);
	getmaxyx(stdscr, screen_height, screen_width);
	compute_real_position(room_list, &anthill, &screen_height, &screen_width);
	display_map(room_list);
}

// static t_ant	*find_ant(char *name, t_ant *ant_list)
// {

// }

// static int		parse_line(t_ant *antlist)
// {
// 	t_ant		*current_ant;

// 	if (*line++ != 'L')
// 		return (0);
// 	current_ant = find_ant(line);
// }

static void		do_animation(t_tube *room_list)
{
	char		*line;

	(void)room_list;
	while (get_next_line(0, &line) > 0)
	{
		
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

int				main(void)
{
	t_infos		*infos;
	t_tube		*room_list;

	if (!(infos = (t_infos *)malloc(sizeof(t_infos))))
		return (EXIT_FAILURE);
	room_list = NULL;
	set_infos(infos);
	parse(&room_list, infos);
	if (!room_list)
	{
		free_everything(room_list, infos, NULL);
		return (EXIT_FAILURE);
	}
	initscr();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	draw_map(room_list);
	refresh();
	do_animation(room_list);
	free_everything(room_list, infos, NULL);
	sleep(1000);
	endwin();
	return (EXIT_SUCCESS);
}
