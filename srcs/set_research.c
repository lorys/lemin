/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_research.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 06:51:28 by llopez            #+#    #+#             */
/*   Updated: 2018/12/17 20:28:35 by llopez           ###   ########.fr       */
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

void	set_research(t_infos *infos, t_paths *paths, t_tube *tube)
{
	char	*buffer;

	if (!find_path(infos->start, infos, infos->start, paths))
		display_error(tube, paths, infos);
	else
	{
		if (infos->bonusants > 0)
			infos->fourmis = infos->bonusants;
		infos->room_total = count_room_linked(tube);
		infos->rounds = 0;
		infos->start->ants = infos->fourmis;
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
		while (paths->prev)
			paths = paths->prev;
		move_ants(paths, infos, buffer);
		if (!infos->bonus)
			fill_buffer(NULL, buffer, 1, infos);
		free(buffer);
		printf("\n\033[41m%d rounds\033[0m\n", infos->rounds);
	}
}
