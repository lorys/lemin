/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2018/11/30 04:02:48 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	bonus_manager(int argc, char **argv, t_infos *infos)
{
	int			i;

	i = 0;
	infos->select = -1;
	infos->bonus = 0;
	while (argc > i)
	{
		if (!ft_strcmp(argv[i], "-colors"))
			infos->bonus = 1;
		if (!ft_strcmp(argv[i], "-select") && argv[i + 1])
			infos->select = ft_atoi(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-ants") && argv[i + 1])
			infos->bonusants = ft_atoi(argv[i + 1]);
		i++;
	}
}

int				main(int argc, char **argv)
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
	set_infos(infos);
	set_paths(paths);
	bonus_manager(argc, argv, infos);
	read_stdin(tube, infos);
	if (!tube->name || !infos->start || !infos->end || infos->fourmis <= 0)
		display_error(tube, paths, infos, ants);
	else
		set_research(infos, paths, ants, tube);
	free_everything(tube, infos, paths, ants);
	return (EXIT_SUCCESS);
}
