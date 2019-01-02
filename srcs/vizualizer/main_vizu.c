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

static void		set_real_position(t_tube *room_list, t_anthill *anthill, \
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

static t_ant	*create_ant(int name, char *room, t_tube *room_list)
{
	t_ant		*new;

	if (!room || !(new = (t_ant *)ft_memalloc(sizeof(*new))))
		return (NULL);
	new->name = name;
	new->current_room = find_room(room, room_list);
	new->in_anthill = 1;
	new->next = NULL;
	new->color = name % 6;
	return (new);
}

static void		move_ant(int name, char *destination, t_ant **ant_list, t_tube *room_list, int *nb_ants)
{
	t_ant		*ant;

	if (!(*ant_list))
		*ant_list = create_ant(name, destination, room_list);
	ant = *ant_list;
	while (ant)
	{
		if (name == ant->name)
		{
			ant->current_room = find_room(destination, room_list);
			ant->in_anthill = 1;
			return ;
		}
		ant = ant->next;
	}
	ant = *ant_list;
	while (ant)
	{
		if (!ant->in_anthill)
		{
			ant->name = name;
			ant->current_room = find_room(destination, room_list);
			ant->in_anthill = 1;
			ant->color = name % 6;
			*nb_ants = *nb_ants - 1;
			return ;
		}
		ant = ant->next;
	}
	ant = *ant_list;
	while (ant->next)
		ant = ant->next;
	ant->next = create_ant(name, destination, room_list);
	*nb_ants = *nb_ants - 1;
}

static void		reset_ants(t_ant *ant_list)
{
	while (ant_list)
	{
		ant_list->in_anthill = 0;
		ant_list = ant_list->next;
	}
}

static void		display_ants(t_ant *ant_list)
{
	t_tube		*room;

	while (ant_list)
	{
		room = ant_list->current_room;
		attron(COLOR_PAIR(ant_list->color));
		mvprintw(room->y - 1, room->x - 2, "[L%.2d]", ant_list->name);
		attroff(COLOR_PAIR(ant_list->color));
		ant_list->in_anthill = 0;

		ant_list = ant_list->next;
	}
}

static void		parse_line_ants(char *line, t_ant **ant_list, t_tube *room_list, t_infos *infos)
{
	char		*tmp;
	char		*room_name;

	while(*line)
	{
		if (*line++ != 'L')
			return ;
		if (!(tmp = ft_strchr(line, ' ')))
			break ;
		*tmp = '\0';
		room_name = ft_strdup(ft_strchr(line, '-') + 1);
		*tmp = '\n';
		move_ant(ft_atoi(line), room_name, ant_list, room_list, &infos->fourmis);
		ft_strdel(&room_name);
		line = tmp + 1;
	}
	if (*line)
	{
		room_name = ft_strdup(ft_strchr(line, '-') + 1);
		move_ant(ft_atoi(line), room_name, ant_list, room_list, &infos->fourmis);
		ft_strdel(&room_name);
	}
}

static void		parse_ants(t_tube *room_list, t_infos *infos)
{
	char		*line;
	int			nline;
	t_ant		*ant_list;

	nline = 0;
	ant_list = NULL;
	(void)infos;
	while (get_next_line(0, &line) > 0 && ++nline)
	{
		reset_ants(ant_list);
		parse_line_ants(line, &ant_list, room_list, infos);
		ft_strdel(&line);
		display_ants(ant_list);
		mvprintw(0, 0, "ligne:%d", nline);
		mvprintw(infos->start->y - 1, infos->start->x - 2, "[%d]", infos->fourmis);
		refresh();
		sleep(2);
	}
	ft_strdel(&line);
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
	start_color();
	init_pair(20, COLOR_BLUE, COLOR_BLACK);
	init_pair(21, COLOR_GREEN, COLOR_BLACK);
	init_pair(0, COLOR_WHITE, COLOR_RED);
	init_pair(1, COLOR_WHITE, COLOR_GREEN);
	init_pair(2, COLOR_BLACK, COLOR_YELLOW);
	init_pair(3, COLOR_WHITE, COLOR_BLUE);
	init_pair(4, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(5, COLOR_WHITE, COLOR_CYAN);
	launch(room_list, &infos);
	refresh();
	parse_ants(room_list, &infos);
	free_everything(room_list, NULL);
	sleep(1000);
	endwin();
	return (EXIT_SUCCESS);
}
