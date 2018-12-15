/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_research.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 06:51:28 by llopez            #+#    #+#             */
/*   Updated: 2018/12/07 06:44:54 by llopez           ###   ########.fr       */
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
	int		ant_num;
	t_paths	*tmp;

	ant_num = 1;
	if (!find_path(infos->start, infos, infos->start, paths))
		display_error(tube, paths, infos);
	else
	{
		while (paths->prev)
			paths = paths->prev;
		if (infos->bonusants > 0)
			infos->fourmis = infos->bonusants;
		infos->room_total = count_room_linked(tube);
		infos->rounds = 0;
		infos->start->ants = infos->fourmis;
		if (!(buffer = (char *)malloc(sizeof(*buffer) * BUFFER_SIZE)))
			return ;
		infos->start->ants = 0;
		while (ant_num < infos->fourmis)
		{
			ant_num = make_line(paths->next, infos, ant_num);
			ant_num++;
		}
		tmp = paths;
		while (tmp)
		{
			ft_printf("Name: %s\n", tmp->room->name);
			tmp = tmp->next;
		}
		if (!infos->bonus)
			fill_buffer(NULL, buffer, 1, infos);
		free(buffer);
		printf("\n\033[41m%d rounds\033[0m\n", infos->rounds);
	}
}
