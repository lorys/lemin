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

static void		launch(t_tube *tube, t_infos *infos)
{
	int			screen_height;
	int			screen_width;
	t_anthill	anthill;

	(void)infos;
	init_anthill(&anthill, tube);
	getmaxyx(stdscr, screen_height, screen_width);
	//printw("width: %d, height %d, anthill width: %d, anthill height: %d\n", screen_width, screen_height, anthill.width, anthill.height);
	while (tube->next)
	{
		printw("pos_x: %d, pos_y: %d name: %s\n", (screen_width * tube->x) / (anthill.width + anthill.min_x), (screen_height * tube->y) / (anthill.height + anthill.min_y), tube->name);
		mvprintw((screen_width * tube->x) / (anthill.width + anthill.min_x), (screen_height * tube->y) / (anthill.height + anthill.min_y), "%s", tube->name);
		tube = tube->next;
	}
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
	launch(tube, infos);
	free_everything(tube, infos, paths, ants);
	refresh();
	getch();
	sleep(100);
	endwin();
	return (EXIT_SUCCESS);
}