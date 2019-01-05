/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2019/01/05 19:09:58 by pcarles          ###   ########.fr       */
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
	t_tube		*room_list;
	t_tube		*tmp;
	t_infos		*infos;
	t_paths		*paths;

	if (!(paths = (t_paths *)malloc(sizeof(t_paths)))\
		|| !(infos = (t_infos *)malloc(sizeof(t_infos))))
		return (EXIT_FAILURE);
	room_list = NULL;
	set_infos(infos);
	set_paths(paths);
	bonus_manager(argc, argv, infos);
	read_stdin(&room_list, infos);
	if (!room_list || !infos->start || !infos->end || infos->fourmis <= 0)
		display_error(room_list, paths, infos);
	else
	{
		find_paths(infos);
		
		// Debug informations
		tmp = room_list;
		while (tmp)
		{
			// Theses rooms should have only one other room connected
			if (tmp->vu == 2)
			{
				paths = tmp->links;
				while (paths)
				{
					ft_printf("Edge name: %s\n", paths->room->name);
					paths = paths->next;
				}
			}
			ft_printf("Name: %7.5s | nb: %d\n", tmp->name, tmp->vu);
			tmp = tmp->next;
		}
		// End debug infos
	}
	free_everything(room_list, infos, paths);
	return (EXIT_SUCCESS);
}
