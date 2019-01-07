/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:07:06 by llopez            #+#    #+#             */
/*   Updated: 2019/01/07 19:55:18 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"

void	init_infos(t_infos *infos)
{
	infos->start = NULL;
	infos->end = NULL;
	infos->fourmis = 0;
	infos->bonus = 0;
	infos->select = 0;
	infos->bonusants = 0;
	infos->room_total = 0;
	infos->rounds = 0;
}