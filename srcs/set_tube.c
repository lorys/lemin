/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:07:06 by llopez            #+#    #+#             */
/*   Updated: 2018/11/30 10:11:53 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_infos(t_infos *infos)
{
	infos->fourmis = 0;
	infos->bonusants = 0;
	infos->bonus = 0;
	infos->select = 0;
	infos->start = NULL;
	infos->end = NULL;
}

void	set_paths(t_paths *paths)
{
	paths->room = NULL;
	paths->next = NULL;
	paths->prev = NULL;
}

t_room	*found_next(t_room *next, t_next *possible, t_next *shortest)
{
	free(shortest);
	free(possible);
	return (next);
}
