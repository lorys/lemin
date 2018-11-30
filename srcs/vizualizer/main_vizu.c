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
	while (rooms->name)
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

static void		set_real_position(t_tube *tube, t_anthill *anthill, \
				int *height, int *width)
{
	*height -= *height * 0.1;
	*width -= *width * 0.1;
	while (tube->name)
	{
		tube->x = ((*width * tube->x) + *width * 0.2) / (anthill->max_x);
		tube->y = ((*height * tube->y) + *height * 0.2) / (anthill->max_y);
		tube = tube->next;
	}
}

static void		display_map(t_tube *tube)
{
	t_tube		**links;

	if (tube->name)
	{
		links = tube->links;
		while (links && *links)
		{
			plot_line(tube->x, tube->y, (*links)->x, (*links)->y);
			links++;
		}
		display_map(tube->next);
		attron(A_BOLD);
		attron(COLOR_PAIR(1));
		mvprintw(tube->y, tube->x - (ft_strlen(tube->name) + 2) / 2, \
		"[%.5s]", tube->name);
		attroff(COLOR_PAIR(1));
		attroff(A_BOLD);
	}
}

static void		launch(t_tube *tube)
{
	int			screen_height;
	int			screen_width;
	t_anthill	anthill;

	init_anthill(&anthill, tube);
	getmaxyx(stdscr, screen_height, screen_width);
	set_real_position(tube, &anthill, &screen_height, &screen_width);
	display_map(tube);
}

int				main(void)
{
	t_infos		*infos;
	t_tube		*tube;

	if (!(tube = (t_tube *)malloc(sizeof(t_tube))) \
	|| !(infos = (t_infos *)malloc(sizeof(t_infos))))
		exit(EXIT_FAILURE);
	set_tube(tube);
	set_infos(infos);
	parse(tube, infos);
	if (!tube->name)
		return (EXIT_FAILURE);
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	launch(tube);
	refresh();
	free_everything(tube, infos, NULL, NULL);
	sleep(1000);
	endwin();
	return (EXIT_SUCCESS);
}
