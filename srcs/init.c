/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:07:06 by llopez            #+#    #+#             */
/*   Updated: 2019/02/09 17:36:34 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"

void	init_infos(t_infos *infos)
{
	infos->start = NULL;
	infos->end = NULL;
	infos->fourmis = 0;
	infos->nb_paths = 0;
	infos->bonus = 0;
	infos->select = 0;
	infos->bonusants = 0;
	infos->round_bonus = 0;
	infos->file_path = NULL;
	infos->adjacency_matrix = NULL;
	infos->room_total = 0;
	infos->rounds = 0;
}