/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2019/02/10 00:01:48 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "common.h"
#include "parser.h"
#include "lem_in.h"

static	void	bonus_manager(int argc, char **argv, t_infos *infos)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "--colors") || !ft_strcmp(argv[i], "-c"))
			infos->bonus = 1;
		else if (!ft_strcmp(argv[i], "--rounds") || !ft_strcmp(argv[i], "-r"))
			infos->round_bonus = 1;
		else if ((!ft_strcmp(argv[i], "--select") || \
			!ft_strcmp(argv[i], "-s")) && i + 1 < argc)
			infos->select = ft_atoi(argv[++i]);
		else if ((!ft_strcmp(argv[i], "--ants") || !ft_strcmp(argv[i], "-a")) \
			&& i + 1 < argc)
			infos->bonusants = ft_atoi(argv[++i]);
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

int				main(int argc, char **argv)
{
	t_infos		infos;

	init_infos(&infos);
	bonus_manager(argc, argv, &infos);
	read_file(&infos.room_list, &infos);
	edmonds_karp(&infos);
	// if (!room_list || !infos.start || !infos.end || infos.fourmis <= 0)
	// 	display_error(room_list);
	// else
	// {
	// 	ft_putchar('\n');
	// 	find_paths(&infos);
	// 	print_debug(&infos);
	// }
	free_matrix(infos.adjacency_matrix, infos.room_total);
	free_everything(infos.room_list);
	return (EXIT_SUCCESS);
}
