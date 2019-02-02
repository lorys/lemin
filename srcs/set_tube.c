/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:07:06 by llopez            #+#    #+#             */
/*   Updated: 2019/02/02 20:57:46 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_tube(t_tube *tube)
{
	tube->prev = NULL;
	tube->next = NULL;
	tube->name = NULL;
	tube->ants = 0;
	tube->already_moved = 0;
	tube->passages = 0;
	tube->x = 0;
	tube->y = 0;
	tube->vu = 0;
	tube->pass = 0;
	tube->steps = -1;
	tube->useless = 0;
	tube->links = (t_paths *)malloc(sizeof(t_paths));
	tube->links->next = NULL;
	tube->links->prev = NULL;
	tube->links->room = NULL;
}

void	set_infos(t_infos *infos)
{
	infos->fourmis = 0;
	infos->bonusants = 0;
	infos->bonus = 0;
	infos->select = 0;
	infos->start = NULL;
	infos->end = NULL;
	infos->shortest_path = 0;
}

void	set_paths(t_paths *paths)
{
	paths->room = NULL;
	paths->next = NULL;
	paths->prev = NULL;
}

t_tube	*found_next(t_tube *next, t_next *possible, t_next *shortest)
{
	free(shortest);
	free(possible);
	return (next);
}
