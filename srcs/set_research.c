/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_research.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 06:51:28 by llopez            #+#    #+#             */
/*   Updated: 2019/02/03 23:01:19 by llopez           ###   ########.fr       */
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
	int		a;

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
		move_ants(infos, buffer);
		if (!infos->bonus)
			fill_buffer(NULL, buffer, 1, infos);
		free(buffer);
		if (!infos->round_bonus)
			ft_printf("\n\033[41m%d rounds\033[0m\n", infos->rounds);
	}
}

int		check_start(t_paths *tmp, t_infos *infos)
{
	while (tmp)
	{
		if (tmp->room == infos->start)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		visitable(t_paths *tmp, t_tube *room, t_infos *infos, int nb)
{
	int		ret;

	ret = 0;
	if ((infos->radius > nb || !infos->radius) && tmp->room != infos->end \
			&& (!tmp->room->vu || tmp->room->pass > nb) && !tmp->room->steps)
		ret = voyager(tmp->room, room, infos, nb + 1);
	return (ret);
}
