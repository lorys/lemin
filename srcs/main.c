/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2019/02/19 16:40:06 by pcarles          ###   ########.fr       */
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

int				main(int argc, char **argv)
{
	t_infos		infos;

	init_infos(&infos);
	bonus_manager(argc, argv, &infos);
	if (read_file(&infos) < 0)
	{
		free_everything(&infos);
		return (EXIT_FAILURE);
	}
	if (create_matrix(&infos.residual_matrix, infos.room_total) == -1)
	{
		ft_putstr_fd("memory allocation failure\n", 2);
		free_everything(&infos);
		return (EXIT_FAILURE);
	}
	if ((infos.parent_array = (int *)malloc(sizeof(*infos.parent_array) * infos.room_total)) == NULL)
		return (-1);
	if (!infos.room_list || !infos.start || !infos.end || infos.nb_ants <= 0)
		display_error(&infos);
	else
		edmonds_karp(&infos);
	free_everything(&infos);
	return (EXIT_SUCCESS);
}
