/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:07:06 by llopez            #+#    #+#             */
/*   Updated: 2019/02/19 15:32:08 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "lem_in.h"

void	init_infos(t_infos *infos)
{
	infos->file_path = NULL;
	infos->start = NULL;
	infos->end = NULL;
	infos->room_list = NULL;
	infos->room_total = 0;
	infos->adjacency_matrix = NULL;
	infos->residual_matrix = NULL;
	infos->nb_ants = 0;
	infos->colors = 0;
	infos->selected_ant = 0;
	infos->rounds = 0;
}