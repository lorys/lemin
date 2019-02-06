/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2019/02/06 04:07:20 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "common.h"
#include "parser.h"
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
	t_infos		infos;
	t_map		*map;
	t_vertice	*room_list;

	init_infos(&infos);
	room_list = NULL;
	map = NULL;
	bonus_manager(argc, argv, &infos);
	read_file(NULL, &map);
	while (map)
	{
		ft_putstr(map->buffer);
		map = map->next;
	}
	// if (!room_list || !infos.start || !infos.end || infos.fourmis <= 0)
	// 	display_error(room_list);
	// else
	// {
	// 	find_paths(&infos);
	// 	print_debug(&infos);
	// }
	// free_everything(room_list);
	return (EXIT_SUCCESS);
}
