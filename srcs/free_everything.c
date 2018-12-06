/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:05:15 by llopez            #+#    #+#             */
/*   Updated: 2018/11/30 10:29:42 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_everything(t_tube *room_list, t_infos *infos, t_paths *paths)
{
	free_list(room_list);
	free(infos);
	while (paths && paths->prev)
		paths = paths->prev;
	free_paths(paths);
}
