/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2019/02/04 18:25:44 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		else
		{
			ft_putstr_fd("usage: lem-in [-c] [-r] [-s ant] [-a ant]\n\n    \
--colors, -c: colored output\n    --rounds, -r: display number of rounds\n    \
--select, -s: highlight only one ant in output\n      \
--ants, -a: set number of ants directly in command line\n", 2);
			exit(EXIT_FAILURE);
		}
	}
}

int				main(int argc, char **argv)
{
	t_tube		*room_list;
	t_infos		infos;

	room_list = NULL;
	set_infos(&infos);
	bonus_manager(argc, argv, &infos);
	read_stdin(&room_list, &infos);
	if (!room_list || !infos.start || !infos.end || infos.fourmis <= 0)
		display_error(room_list, NULL);
	else
		set_research(&infos, room_list);
	free_everything(room_list, NULL);
	return (EXIT_SUCCESS);
}
