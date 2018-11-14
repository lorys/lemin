/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:03:15 by llopez            #+#    #+#             */
/*   Updated: 2018/11/12 07:22:55 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_tube	*get_shortest_path(t_paths *paths, t_tube *from)
{
	int		i;
	int		min;
	int		min_tmp;
	t_tube		*end;

	min_tmp = 0;
	i = 0;
	min = INT_MAX;
	end = paths->steps[0];
	while (paths->steps[i])
	{
		if (paths->steps[i] == end)
		{
			min_tmp = i;
			while (paths->steps[i] != from && paths->steps[i])
				i++;
			if ((i - min_tmp) < min && paths->steps[i] == from && !paths->steps[i]->ants)
			{
				printf("%s est plus proche\n", paths->steps[i - min_tmp]->name);
				min = (i - min_tmp);
			}
		}
		i++;
	}
	return (paths->steps[min]);
}

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
		new_room = get_shortest_path(paths, ants[i]);
		if (new_room)
		{
			ants[i]->ants = 0;
			ants[i] = new_room;
			if (ants[i] != infos->end)
				ants[i]->ants = 1;
			ft_printf("L%d-%s ", i + 1, ants[i]->name);
		}
		i++;
	}
	ft_printf("\n");
	if (need_to_move(ants, infos))
		move_ants(paths, infos, ants);
}
