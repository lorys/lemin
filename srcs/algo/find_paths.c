/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:51:27 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/13 08:18:47 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "common.h"
#include "lem_in.h"

void			get_next_room(uint32_t **matrix, unsigned int u, t_infos *infos)
{
	unsigned int	x;

	x = 0;
	if (u = infos->end->id)
		return ;
	while (x < infos->room_total)
	{
		if (read_matrix(matrix, u, x) == 1)
			get_next_room(matrix, x, infos);
		x++;
	}
}

t_paths		*get_path(uint32_t **matrix, t_infos *infos)
{
	unsigned int	u;
	unsigned int	x;

	u = infos->start->id;
	x = 0;
	while (x < infos->room_total)
	{
		if (read_matrix(matrix, u, x) == 1)
		x++;
	}
}