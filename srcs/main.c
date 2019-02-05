/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2019/02/03 15:41:27 by pcarles          ###   ########.fr       */
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
	t_tube		*room_list;
	//t_tube		*tmp;
	//t_paths		*paths_tmp;

	init_infos(&infos);
	room_list = NULL;
	bonus_manager(argc, argv, &infos);
	read_stdin(&room_list, &infos);
	if (!room_list || !infos.start || !infos.end || infos.fourmis <= 0)
		display_error(room_list);
	else
	{
		find_paths(&infos);
		print_debug(&infos);
		
		// Debug informations
		// tmp = room_list;
		// while (tmp)
		// {
		// 	// Theses rooms should have only one other room connected
		// 	if (tmp->vu == 2)
		// 	{
		// 		paths_tmp = tmp->links;
		// 		while (paths_tmp)
		// 		{
		// 			ft_printf("Edge name: %s\n", paths_tmp->room->name);
		// 			paths_tmp = paths_tmp->next;
		// 		}
		// 	}
		// 	ft_printf("Name: %7.5s | nb: %d\n", tmp->name, tmp->vu);
		// 	tmp = tmp->next;
		// }
		// End debug infos
	}
	free_everything(room_list);
	return (EXIT_SUCCESS);
}
