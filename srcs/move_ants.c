/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:03:15 by llopez            #+#    #+#             */
/*   Updated: 2018/11/30 06:39:11 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		need_to_move(t_tube **ants, t_infos *infos)
{
	int i;

	i = 0;
	while (ants[i])
	{
		if (ants[i] != infos->end)
			return (1);
		i++;
	}
	return (0);
}

static void		show_ant(int i, t_tube **ants, t_infos *infos)
{
	if (infos->select == (i + 1))
		ft_printf("\033[41mL%d-%s\033[0m", i + 1, ants[i]->name);
	else if (infos->bonus)
		ft_printf("\033[%dmL%d-%s\033[0m", i, i + 1, ants[i]->name);
	else
		ft_printf("L%d-%s", i + 1, ants[i]->name);
}

static int		change_room(int i, t_paths *paths, t_tube **ants,\
		t_infos *infos)
{
	t_tube	*new_room;

	new_room = NULL;
	new_room = get_shortest_path(paths, ants[i], infos);
	if (new_room)
	{
		ants[i]->ants = 0;
		ants[i] = new_room;
		if (ants[i] != infos->end)
			ants[i]->ants = 1;
		return (1);
	}
	return (0);
}

void			move_ants(t_paths *paths, t_infos *infos, t_tube **ants)
{
	int		i;
	int		ants_moved;

	ants_moved = 0;
	i = 0;
	while (ants[i])
	{
		if (ants[i] == infos->end && ++i)
			continue;
		if (change_room(i, paths, ants, infos))
		{
			if (ants_moved)
				write(1, " ", 1);
			show_ant(i, ants, infos);
			ants_moved++;
		}
		i++;
	}
	write(1, "\n", 1);
	if (need_to_move(ants, infos))
		move_ants(paths, infos, ants);
}
