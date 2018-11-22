/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:02:40 by llopez            #+#    #+#             */
/*   Updated: 2018/11/22 08:46:18 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	display_error(t_tube *tube, t_paths *paths, t_infos *infos,\
		t_tube **ants)
{
	free_everything(tube, infos, paths, ants);
	write(2, "ERROR", 5);
	exit(1);
}
