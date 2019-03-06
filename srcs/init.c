/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:07:06 by llopez            #+#    #+#             */
/*   Updated: 2019/02/03 15:40:15 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"

void	init_infos(t_infos *infos, t_btu *btu)
{
	btu->rounds = 0;
	btu->index = 0;
	btu->room = NULL;
	infos->start = NULL;
	infos->btu = btu;
	infos->end = NULL;
	infos->paths_nb = 0;
	infos->paths_index = 0;
	infos->total_room = 0;
	infos->fourmis = 0;
	infos->bfs = 0;
	infos->minus_path = 0;
	infos->bonus = 0;
	infos->select = 0;
	infos->bonusants = 0;
	infos->room_total = 0;
	infos->rounds = 0;
}
