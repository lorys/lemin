/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2019/03/16 18:40:18 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "common.h"
#include "parser.h"
#include "algo.h"

static void	print_usage(void)
{
	ft_putstr_fd("usage: lem-in [-r] [-s ant] [-a ant] [-f map_file]\n\n"
	"    --rounds, -r: display number of rounds\n"
	"    --select, -s: highlight only one ant in output\n"
	"      --ants, -a: set number of ants directly in command line\n"
	"      --file, -f: open file `map_file' instead of reading stdin\n", 2);
}

static void	bonus_manager(int argc, char **argv, t_infos *infos)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "--rounds") || !ft_strcmp(argv[i], "-r"))
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
			print_usage();
			exit(EXIT_FAILURE);
		}
	}
}

void		sort_solution(t_solution *solution)
{
	size_t		i;
	size_t		j;
	size_t		x;
	t_path		*path;

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

int			main(int argc, char **argv)
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
	show_output(solution, infos.nb_ants, infos.rounds, &infos);
	free_solution(&solution);
	free_everything(&infos);
	return (EXIT_SUCCESS);
}
