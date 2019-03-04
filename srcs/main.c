/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2019/03/04 16:53:54 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "common.h"
#include "parser.h"
#include "algo.h"

static	void	bonus_manager(int argc, char **argv, t_infos *infos)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "--colors") || !ft_strcmp(argv[i], "-c"))
			infos->colors = 1;
		else if (!ft_strcmp(argv[i], "--rounds") || !ft_strcmp(argv[i], "-r"))
			infos->rounds = 1;
		else if ((!ft_strcmp(argv[i], "--select") || \
			!ft_strcmp(argv[i], "-s")) && i + 1 < argc)
			infos->selected_ant = ft_atoi(argv[++i]);
		else if ((!ft_strcmp(argv[i], "--ants") || !ft_strcmp(argv[i], "-a")) \
			&& i + 1 < argc)
			infos->nb_ants = ft_atoi(argv[++i]);
		else if ((!ft_strcmp(argv[i], "--file") || !ft_strcmp(argv[i], "-f")) \
			&& i + 1 < argc)
			infos->file_path = argv[++i];
		else
		{
			ft_putstr_fd("usage: lem-in [-c] [-r] [-s ant] [-a ant] [-f map_file]\n\n    \
--colors, -c: colored output\n    --rounds, -r: display number of rounds\n    \
--select, -s: highlight only one ant in output\n      \
--ants, -a: set number of ants directly in command line\n      \
--file, -f: open file `map_file' instead of reading stdin\n", 2);
			exit(EXIT_FAILURE);
		}
	}
}

// char	*flags[] = {"colors", "rounds", "select", "ants", "file"}

// static void		parse(int ac, int index, char *arg)
// {

// }

// static void		parse_flags(int ac, char **av, t_infos *infos)
// {
// 	int			index;
// 	char		*tmp;

// 	index = 0;
// 	while (++index < ac)
// 	{
// 		tmp = av[index];
// 		if (*tmp++ == '-')
// 		{
// 			if (*tmp == '-' && tmp++)
// 				parse1();
// 			else
// 				parse2();
// 		}
// 	}
// }

// static void	print_path(t_path *path)
// {
// 	ft_printf("Path :");
// 	while (path)
// 	{
// 		ft_printf("%s ", path->room->name);
// 		path = path->next;
// 	}
// 	ft_printf("\n");
// }

// static void		show_solution(t_solution *solution)
// {
// 	unsigned int	x;

// 	x = 0;
// 	while (x < solution->nb_paths)
// 	{
// 		ft_printf("Path size: %5d | ", solution->path_size[x]);
// 		print_path(solution->paths[x]);
// 		x++;
// 	}
// 	ft_printf("Total size: %d\n\n", solution->total_size);
// }

static void	sort_solution(t_solution *solution)
{
	size_t		i;
	size_t		j;
	size_t	x;
	t_path	*path;

	i = 1;
	while (i < solution->nb_paths)
	{
		x = solution->path_size[i];
		path = solution->paths[i];
		j = i;
		while (j > 0 && solution->path_size[j - 1] > x)
		{
			solution->path_size[j] = solution->path_size[j - 1];
			solution->paths[j] = solution->paths[j - 1];
			j -= 1;
		}
		solution->path_size[j] = x;
		solution->paths[j] = path;
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_infos		infos;
	t_solution	*solution;

	init_infos(&infos);
	bonus_manager(argc, argv, &infos);
	if (read_file(&infos) < 0)
	{
		free_everything(&infos);
		return (EXIT_FAILURE);
	}
	ft_putchar('\n');
	if (!infos.room_list || !infos.start || !infos.end || infos.nb_ants <= 0)
		display_error(&infos);
	init_algo(&infos);
	if ((solution = edmonds_karp(&infos)) == NULL)
		display_error(&infos);
	sort_solution(solution);
	show_output(solution, infos.nb_ants, infos.rounds);
	free_solution(&solution);
	free_everything(&infos);
	return (EXIT_SUCCESS);
}
