/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:03:15 by llopez            #+#    #+#             */
/*   Updated: 2018/11/24 15:39:51 by llopez           ###   ########.fr       */
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
		ft_printf("\033[41mL%d-%s\033[0m ", i + 1, ants[i]->name);
	else if (infos->bonus)
		ft_printf("\033[%dmL%d-%s\033[0m ", i, i + 1, ants[i]->name);
	else
		ft_printf("L%d-%s ", i + 1, ants[i]->name);
}

void			move_ants(t_paths *paths, t_infos *infos, t_tube **ants)
{
	int		i;
	t_tube	*new_room;

	i = 0;
	new_room = NULL;
	while (ants[i])
	{
		if (ants[i] == infos->end && ++i)
			continue;
		new_room = get_shortest_path(paths, ants[i], infos);
		if (new_room)
		{
			ants[i]->ants = 0;
			ants[i] = new_room;
			if (ants[i] != infos->end)
				ants[i]->ants = 1;
			show_ant(i, ants, infos);
		}
		i++;
	}
	ft_printf("\n");
	if (need_to_move(ants, infos))
		move_ants(paths, infos, ants);
}
