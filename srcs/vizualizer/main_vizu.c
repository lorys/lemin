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
	while (rooms->next)
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

static void		set_real_position(t_tube *tube, t_anthill *anthill, int *height, int *width)
{
	*height -= *height * 0.1;
	*width -= *width * 0.1;
	while (tube)
	{
		tube->x = ((*width * tube->x) + *width * 0.2) / (anthill->max_x);
		tube->y = ((*height * tube->y) + *height * 0.2) / (anthill->max_y);
		tube = tube->next;
	}
}

static void		display_map(t_tube *tube)
{
	t_tube		**links;

	if (tube->next)
	{
		//printw("pos_x: %d, pos_y: %d name: %s\n", (width * tube->x) / (anthill->width + anthill->min_x), (height * tube->y) / (anthill->height + anthill->min_y), tube->name);
		links = tube->links;
		while (*links)
		{
			plot_line(tube->x, tube->y, (*links)->x, (*links)->y);
			links++;
		}
		display_map(tube->next);
		attron(A_BOLD);
		attron(COLOR_PAIR(1));
		mvprintw(tube->y, tube->x - (ft_strlen(tube->name) + 2) / 2, "[%.5s]", tube->name);
		attroff(COLOR_PAIR(1));
		attroff(A_BOLD);
	}	
}

static void		launch(t_tube *tube, t_infos *infos)
{
	int			screen_height;
	int			screen_width;
	t_anthill	anthill;

	(void)infos;
	init_anthill(&anthill, tube);
	getmaxyx(stdscr, screen_height, screen_width);
	set_real_position(tube, &anthill, &screen_height, &screen_width);
	//printw("width: %d, height %d, anthill width: %d, anthill height: %d\n", screen_width, screen_height, anthill.width, anthill.height);
	display_map(tube);
}

int				main(void)
{
	t_infos		*infos;
	t_tube		*tube;
	t_paths		*paths;
	t_tube		**ants;

	ants = NULL;
	if (!(tube = (t_tube *)malloc(sizeof(t_tube)))\
			|| !(paths = (t_paths *)malloc(sizeof(t_paths)))\
			|| !(infos = (t_infos *)malloc(sizeof(t_infos))))
		exit(EXIT_FAILURE);
	set_tube(tube);
	infos->fourmis = 0;
	infos->start = NULL;
	infos->end = NULL;
	paths->room = NULL;
	paths->next = NULL;
	paths->prev = NULL;
	parse(tube, infos);
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	launch(tube, infos);
	refresh();
	free_everything(tube, infos, paths, ants);
	sleep(1000);
	endwin();
	return (EXIT_SUCCESS);
}