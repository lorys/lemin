/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_research.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 06:51:28 by llopez            #+#    #+#             */
/*   Updated: 2019/02/01 16:14:03 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_room_linked(t_tube *tube)
{
	t_tube	*tmp;
	int		count;

	count = 0;
	tmp = tube;
	while (tube->prev)
	{
		count = (tube->links) ? count + 1 : count;
		tube = tube->prev;
	}
	while ((tmp = tmp->next))
		count = (tube->links) ? count + 1 : count;
	return (count);
}

void	set_research(t_infos *infos, t_tube *tube)
{
	char	*buffer;
	t_paths	*tmp;
	int	a;

	a = 0;
	if (!find_path(infos))
		display_error(tube, infos);
	else
	{
		if (infos->bonusants > 0)
			infos->fourmis = infos->bonusants;
		infos->room_total = count_room_linked(tube);
		infos->rounds = 0;
		infos->start->ants = infos->fourmis;
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
		tmp = infos->start->links;
		while (tmp)
		{
			if (tmp->room->steps)
				a++;
			if (tmp->room->steps)
				printf("%s\t\t(%d steps)\n", tmp->room->name, tmp->room->steps);
			tmp = tmp->next;
		}
		printf("%d connexions at start\n", a);
		move_ants(infos, buffer);
		if (!infos->bonus)
			fill_buffer(NULL, buffer, 1, infos);
		free(buffer);
		printf("\n\033[41m%d rounds\033[0m\n", infos->rounds);
	}
}
