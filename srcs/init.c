/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:07:06 by llopez            #+#    #+#             */
/*   Updated: 2019/02/21 17:47:13 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "common.h"

void	init_infos(t_infos *infos)
{
	infos->file_path = NULL;
	infos->start = NULL;
	infos->end = NULL;
	infos->room_list = NULL;
	infos->room_total = 0;
	infos->adjacency_matrix = NULL;
	infos->residual_matrix = NULL;
	infos->parent_array = NULL;
	infos->nb_ants = 0;
	infos->colors = 0;
	infos->selected_ant = 0;
	infos->rounds = 0;
}

void	init_algo(t_infos *infos)
{
	if (create_matrix(&infos->residual_matrix, infos->room_total) == -1
		|| (infos->parent_array = (int *)malloc(sizeof(*(infos->parent_array)) \
		* infos->room_total)) == NULL)
	{
		ft_putstr_fd("memory allocation failure\n", 2);
		free_everything(infos);
		exit(EXIT_FAILURE);
	}
}
