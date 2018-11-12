/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_research.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 06:51:28 by llopez            #+#    #+#             */
/*   Updated: 2018/11/12 07:20:06 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_research(t_infos *infos, t_paths *paths, t_tube **ants,\
		t_tube *tube)
{
	if (!find_path(infos->start, infos, infos->start, paths))
		display_error(tube, paths, infos, ants);
	else
	{
		set_ants(infos, &ants);
		move_ants(paths, infos, ants);
		free(ants);
	}
}
