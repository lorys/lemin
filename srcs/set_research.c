/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_research.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 06:51:28 by llopez            #+#    #+#             */
/*   Updated: 2018/12/03 20:36:40 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_research(t_infos *infos, t_paths *paths, t_tube *tube)
{
	char *buffer;

	if (!find_path(infos->start, infos, infos->start, paths))
		display_error(tube, paths, infos);
	else
	{
		if (infos->bonusants > 0)
			infos->fourmis = infos->bonusants;
		infos->start->ants = infos->fourmis;
		buffer = malloc(sizeof(char) * 2000);
		bzero(buffer, 2000);
		move_ants(paths, infos, buffer);
		write(1, buffer, ft_strlen(buffer));
		free(buffer);
	}
}
